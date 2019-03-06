#!/usr/bin/python2.4
#
# Copyright 2006 Google Inc. All Rights Reserved.

"""Checks that a given user is in all of the groups needed for their job.

This module will check that the current user or the user given on the command
line belongs to all of the groups defined as required in a given configuration
file.  This can check for membership in mdb groups, unix groups, mailing lists,
p4 groups, borg usermaps and OWNERS files.  Additionally, logs access
policies and pager requirements are checked.

check_groups.py supports multiple 'classes', acting as collections of groups.
The idea is that not all crawlindex sre's care about dropsafe groups, and vice
versa.

To list the classes supported by the config file you're using, run:
  $ check_groups.py --config=<config> --list_classes

When you've decided the classes you want to check your memberships for, run:
  $ check_groups.py --config=<config> --classes=class1,class2,...

If no configuration file is specified the tool attempts to choose a
default based on mailing list membership.

If you want to run this for a user other than yourself, add the --user flag.

"""

__author__ = 'hurstdog@google.com (Andrew Hurst)'

import ConfigParser
import getpass
import os
import re
import select
import subprocess
import sys

from google3.pyglib import app
from google3.pyglib import flags
from google3.pyglib import logging
from google3.pyglib import OrderedDictionary
from google3.pyglib.ops import gldap

FLAGS = flags.FLAGS

flags.DEFINE_string('config', '',
                    'Configuration file holding required groups')
flags.DEFINE_string('users', getpass.getuser(),
                    'The comma separated user list to check memberships for')
flags.DEFINE_list('classes', '',
                  'The classes of memberships to check, '
                  'i.e. crawlindex, logs-sre, etc')
flags.DEFINE_boolean('list_classes', False,
                     'List all classes supported by the given config file')
flags.DEFINE_string('ldap_host', 'ldap://ldap.corp.google.com',
                    'URL for the LDAP server used to look up users.')
flags.DEFINE_string('expn_command', 'expn',
                    'Command used to expand mailing lists.')


# The default location of the configuration file.  Note that we will
# first try to open the filename passed as the --config argument.  If
# that fails then use this formatting against that same filename.
_DEFAULT_CONFIG_PATH = (
    '/home/build/google3/production/tools/check_groups/conf/%s')

_EMAIL_PAT = r'<?(%s)(\+[^@]*)?@.*\.?google.com>?'

# Magically divined optimal number of args to pass to expn.
MAX_EXPN_ARGS = 5


# We use this instead of commands.getstatusoutput since it allows us to ignore
# stderr.
def _GetStatusOutput(cmd):
  p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
  output = p.communicate()[0]
  return (p.returncode, output)


# Used so that we can mock out the response from getstatusoutput in the tests.
_GET_STATUS_OUTPUT = _GetStatusOutput


class GroupCheck(object):

  """Parent class for all group checks.

  All checks derive from this class in order to check in a unit test
  whether they overload all required attributes. To use a subclass you
  should call Check with no modifications to the provided group's
  case.

  To create a subclass, override _Check, and set _is_case_sensitive
  as to whether you want the provided group left as it is or converted
  to lower case for easier comparison.
  """
  NAME = 'group_check'
  PRETTY_NAME = 'generic group check'
  _WHAT_TO_DO = 'no help available'
  _IS_CASE_SENSITIVE = False

  @classmethod
  def GetFixHint(cls, unused_username, unused_group_tup):
    """Return a hint on how to fix the problem.

    Args:
      unused_username: the username of the affected user.
      unused_group_tup: (check_groups_group, group_to_join, rationale)

    Returns:
      A human-readable (English) string explaining what the user should do.
    """
    return cls._WHAT_TO_DO

  @classmethod
  def _Check(cls, name, group):
    """Internal implementation to check whether name is a member of group.

    Args:
      name: The username to check.
      group: The group to be checked for membership.

    Returns:
      True or False depending on whether the user was in the group.

    This is an abstract class method. It must be overridden in child
    classes. If _IS_CASE_SENSITIVE is False then the provided group
    will be in lower case.
    """
    raise NotImplementedError

  @classmethod
  def Check(cls, name, group):
    """External API call to check whether name is a member of the group.

    Args:
      name: The username to check.
      group: The group to be checked for membership, in its original case.

    Returns:
      True or False depending on whether the user was in the group.

    This method handles any case conversion specified by _IS_CASE_SENSITIVE.
    """
    if not cls._IS_CASE_SENSITIVE:
      group = group.lower()
    return cls._Check(name, group)


class BorgUsermapCheck(GroupCheck):

  """Checks a usermap for a username."""
  NAME = 'usermaps'
  PRETTY_NAME = NAME
  _WHAT_TO_DO = ('see http://wiki/twiki/bin/view/Main/ManagingBorgUsers'
                 '#Modifying_user_limits')

  __BORG_USERMAP_DIR = '/home/build/google3/production/borg/usermaps/'

  @classmethod
  def _Check(cls, username, usermap):
    """Checks the usermap for the given username.

    This depends on the class attribute defined above that says where
    the borg usermap directory is, and uses that to grep the usermap
    for the given username.

    Args:
      username: The name of the user to search for
      usermap: The borg usermap to check for existance.  This should be the
        relative path starting from the production/borg/usermaps/services/
        directory.

    Returns:
      True or False depending on if the usermap contains the given user.
    """
    path_sep = os.path.sep
    clean_user = _CleanForShell(username)
    map_parts = [_CleanForShell(part) for part in usermap.split(path_sep)]

    full_path = reduce(os.path.join, map_parts, cls.__BORG_USERMAP_DIR)
    full_path = os.path.normpath(full_path)
    logging.debug('Searching usermap %s for %s', full_path, clean_user)

    cmd = ('grep -s \'"%s"\' %s' % (clean_user, full_path))
    (status, unused_output) = _GET_STATUS_OUTPUT(cmd)

    return status == 0


class PerforceGroupCheck(GroupCheck):

  """Checks if the user is in the p4 group."""
  NAME = 'p4_groups'
  PRETTY_NAME = 'P4 groups'

  @classmethod
  def GetFixHint(cls, unused_username, group_tup):
    """Return a hint on how to join the relevant p4 group.

    Args:
      unused_username: the username of the affected user.
      group_tup: (check_groups_group, p4_group, rationale)

    Returns:
      A human-readable (English) string explaining what the user should do.
    """
    return ('Run "g4 group -o %(p4group)s" and look at the "Owners" section.  '
            'Ask one of the owners to add you to the group.  If the group '
            'has no owners, mail p4@ and ask them to add you to the group.  '
            'CC your manager on the email in case p4@ asks for their '
            'authorisation.'
            % {'p4group': group_tup[1]})

  @classmethod
  def _Check(cls, username, p4_group):
    """Checks if the user is in the p4 group, returning True or False.

    This only works if a .p4config can be found somewhere above your current
    working directory.  If there, this will use the p4 command and grep to
    see if the given user is a member of the correct group.

    Args:
      username: The username to check for membership in the following group.
      p4_group: The p4 group the user should be a member of.

    Returns:
      True or False depending on whether the p4 group contains the given user.
    """
    clean_user = _CleanForShell(username)

    logging.debug('Searching %s for %s', p4_group, clean_user)

    # catch error output as well, to see if we're not in a client.
    (status, p4_output) = _GET_STATUS_OUTPUT('p4 groups ' + clean_user)

    logging.debug('P4 command: p4 groups %s', clean_user)
    logging.debug('P4 output: %s', p4_output)

    if status != 0:
      logging.info('Error running p4 groups: %s. Try running from your home '
                   'directory.', p4_output)
      return False

    return p4_group in p4_output.splitlines()


class UnixGroupCheck(GroupCheck):

  """Checks the given unix group for the given username."""
  NAME = 'unix_groups'
  PRETTY_NAME = 'Unix groups'
  _WHAT_TO_DO = 'see https://corpdb.corp.google.com/groupman/'

  @classmethod
  def _Check(cls, username, unix_group):
    """Checks the given unix group for the given username.

    Args:
      username: The username to check for membership in the group.
      unix_group: The unix group the user should be a member of.

    Returns:
      True or False depending on whether the unix group contains the given
      user.
    """
    clean_user = _CleanForShell(username)

    logging.debug('Searching %s for %s', unix_group, clean_user)

    (status, id_output) = _GET_STATUS_OUTPUT('id -Gn %s' % clean_user)
    if status != 0:
      logging.info('Error running id, got: %s', id_output)
      return False
    else:
      logging.debug('Output from id: %s', id_output)

    return unix_group in id_output.split()


class MdbCheck(GroupCheck):

  """Checks an mdb group for a given username."""
  NAME = 'mdb_groups'
  PRETTY_NAME = 'MDB groups'
  _WHAT_DO_DO = 'see https://ganpati.corp.google.com/'

  @classmethod
  def GetFixHint(cls, username, group_tup):
    """Return a hint on how to join the relevant MDB group.

    Args:
      username: the username of the affected user.
      group_tup: (check_groups_group, mdb_group, rationale)

    Returns:
      A human-readable (English) string explaining what the user should do.
    """
    return ('Visit https://ganpati.corp.google.com/#Membership_Info?group=%s'
            '&member=%s@google.com&action=create' % (group_tup[1], username))

  @classmethod
  def _Check(cls, username, mdb_group):
    """Checks the given mdb group for the given username.

    Args:
      username: The user that should be a member of the mdb group.
      mdb_group: The group to check for the user in.

    Returns:
      True or False depending on if the mdb group contains the given user.
    """
    clean_user = _CleanForShell(username)

    logging.debug('Searching %s for %s', mdb_group, clean_user)

    # Expect lines like:
    # ^hurstdog   build-admin@prod$
    (status, mdb_out) = _GET_STATUS_OUTPUT(
        'ganpati --noheaders lsmem --mdb --include_indirect -m %s'
        % clean_user)

    if status != 0:
      # Only output 1000 characters of mdb_out because of limits in logging.py
      logging.info('Error running ganpati --noheaders lsmem --mdb '
                   '--include_indirect -m %s, got: %s',
                   clean_user, mdb_out[0:1000])
      return False

    mdb_lines = mdb_out.splitlines()
    try:
      groups = map(lambda x: x.split()[1].split('@')[0], mdb_lines)
    except IndexError:
      # Only output 1000 characters of mdb_out because of limits in logging.py
      logging.info('Error running ganpati --noheaders lsmem --mdb '
                   '--include_indirect -m %s, got: %s',
                   clean_user, mdb_out[0:1000])
      return False

    return mdb_group in groups


class EmailCheck(GroupCheck):

  """Checks that a user is a member of an email list, recursively."""
  NAME = 'email_lists'
  PRETTY_NAME = 'email lists'

  _MAX_DEPTH = 2
  _MAX_FORK = 5

  _cache = {}
  _fd = {}
  _jobs = OrderedDictionary.OrderedDictionary()
  _ldap = None
  _user_cache = {}
  _user_jobs = set()

  class _ExpnJob(object):
    """A list that has been or will be expanded by expn.

    expn is a command that will expand a google.com mail alias.

    Attributes:
      name: The name of the list to expand.
      depth: How deep into the expansion is this list.
      fd: File descriptor to read from the pipe connected to the child.
    """

    _BUF_SIZE = 4096

    def __init__(self, name, depth):
      self.depth = depth
      self.name = name
      self.fd = None
      self._buffer = []

    def Run(self):
      """Fork and exec expn, saving the file descriptor to be read from later.

      Returns:
        The file descriptor of the pipe connected to the child.
      """
      r, w = os.pipe()
      self.pid = os.fork()
      if self.pid == 0:
        os.close(r)
        os.dup2(w, 1)
        os.execlp(FLAGS.expn_command, 'expn', '-s', self.name)
      else:
        os.close(w)
        self.fd = r
        return r

    def Read(self):
      """Read any available output from the pipe.

      Returns:
        The child's output if EOF has been reached, None otherwise.
      """
      buf = os.read(self.fd, self._BUF_SIZE)
      if buf:
        self._buffer.append(buf)
      else:
        os.close(self.fd)
        return ''.join(self._buffer)

  class _UserJob(object):
    """Store users who have not, but will be, looked up in LDAP.

    Attributes:
      name: The name of the user to lookup.
      depth: The depth at which the user was found. This is saved in case this
          is not a user, and we need to call expn on this name. This ensures
          that lists will only be expanded to a certain level.
    """

    def __init__(self, name, depth):
      self.name = name
      self.depth = depth

    def __hash__(self):
      return hash(self.name)

    def __eq__(self, other):
      return self.name == other.name

    def IsUser(self, ldap):
      """Look up this user in LDAP.

      Args:
        ldap: GoogleLDAP object to use for talking to the LDAP server.

      Returns:
        True if this user is a user, False otherwise.
      """
      try:
        info = ldap.GetAttributes('uid=%s,ou=People,dc=google,dc=com' %
                                  self.name)
      except gldap.ObjectError:
        return False
      else:
        return 'person' in info['objectClass']

  @classmethod
  def _CheckList(cls, name, depth=None):
    """Create an _ExpnJob so expn is eventually called for this list.

    Args:
      name: The name of the list to expand.
      depth: The depth at which we found this list.
    """
    if depth is None:
      depth = cls._MAX_DEPTH

    if name not in cls._jobs:
      cls._jobs[name] = cls._ExpnJob(name, depth)

  @classmethod
  def _CheckUser(cls, name, depth):
    """Create an entry so this user can eventually be looked up in LDAP.

    Args:
      name: The name of the user to lookup.
      depth: The depth at which we found the user.
    """
    if name not in cls._user_cache:
      cls._user_jobs.add(cls._UserJob(name, depth))

  @classmethod
  def _StartJobs(cls):
    """Start a controlled number of children if there is work to be done."""
    while cls._jobs and len(cls._fd) < cls._MAX_FORK:
      job = cls._jobs.pop(iter(cls._jobs).next())

      fd = job.Run()
      cls._fd[fd] = job

  @classmethod
  def _LookupUser(cls):
    """Lookup one user in LDAP and cache the result.

    This method only looks up one user at a time so that we can return to main
    loop frequently. If the user we looked up is not actually a user, add a job
    to the queue to expn this name.
    """
    if not cls._user_jobs:
      return

    if cls._ldap is None:
      cls._ldap = gldap.GoogleLDAP()
      cls._ldap.Connect(FLAGS.ldap_host)

    user = cls._user_jobs.pop()
    found = user.IsUser(cls._ldap)

    cls._user_cache[user.name] = found
    if not found and user.depth >= 0:
      cls._CheckList(user.name, user.depth)

  @classmethod
  def _Select(cls):
    """Read from any files that ready to be read from.

    If any of file descriptors have output, read it and store it to be combined
    with any other output from the child. If we reach EOF reading from the
    child, yield the _ExpnJob object back to the caller.

    Yields:
      An _ExpnJob object that has collected all of its output.
    """
    watch = cls._fd.keys()
    if not watch:
      return

    # If there are _UserJobs to process, use a timeout of 0 so select will
    # return immediately. Otherwise use no timeout.
    if cls._user_jobs:
      read_fds, _, _ = select.select(watch, [], [], 0)
    else:
      read_fds, _, _ = select.select(watch, [], [])

    for fd in read_fds:
      job = cls._fd[fd]
      output = job.Read()
      if output is None:
        continue

      del cls._fd[fd]
      cls._cache[job.name] = output

      yield job

  @classmethod
  def _Reap(cls):
    """Call wait on any undead children."""
    while True:
      try:
        pid, _ = os.waitpid(0, os.WNOHANG)
      except OSError:
        return
      if pid == 0:
        return

  @classmethod
  def _RunAllJobs(cls, regex):
    """Main execution loop for parallel expn.

    As there is work available to be done, this method will create children to
    run expn and lookup users in LDAP. It also reads the results from children
    when they are ready, and reaps any zombie children.

    Args:
      regex: If the user matched by this regex is found in the expansion of a
          list, don't expand any deeper.
    """
    cls._StartJobs()

    while cls._user_jobs or cls._jobs or cls._fd:
      for job in cls._Select():
        if job.depth == 0:
          continue
        match = regex.search(cls._cache[job.name])
        if match:
          continue
        for user in cls._Output(job.name):
          cls._CheckUser(user, job.depth - 1)

      cls._Reap()
      cls._StartJobs()
      cls._LookupUser()

  @classmethod
  def _Output(cls, name):
    """Split the cached output of expn into a list of users.

    Args:
      name: The name of the list to split.

    Yields:
      A username (no @google.com) subscribed to the named list, skipping over
      any error messages (e.g. Private Membership).
    """
    username_pattern = '(.*?)(\+.*)?@google\.com$'

    for line in cls._cache[name].splitlines():
      username_match = re.match(username_pattern, line)
      if username_match:
        yield username_match.group(1)

  @classmethod
  def _CheckForEmail(cls, regex, name, max_depth=None):
    """Search through the cached output for a user matched by regex.

    Args:
      regex: A pattern that matches the user we are looking for.
      name: Name of the list to search for the user in.
      max_depth: How many times this method should recurse.

    Returns:
      True if the user was found in this list or its sublists, False otherwise.
    """
    if max_depth is None:
      max_depth = cls._MAX_DEPTH

    email_match = regex.search(cls._cache[name])
    if email_match:
      return True
    else:
      if max_depth <= 0:
        return False

      for user in cls._Output(name):
        if user in cls._user_cache and cls._user_cache[user] is not True:
          if cls._CheckForEmail(regex, user, max_depth - 1):
            return True

      return False

  @classmethod
  def Preload(cls, name, groups):
    """Run expn in parallel for all groups, saving the results into cache.

    Args:
      name: The username to check.
      groups: The groups that should be loaded into the cache.
    """
    for group in groups:
      cls._CheckList(_CleanForShell(group))
    email_regex = re.compile(_EMAIL_PAT % re.escape(name), re.MULTILINE)
    cls._RunAllJobs(email_regex)

  @classmethod
  def _Check(cls, username, email_list):
    """Checks that a user is a member of an email list, recursively.

    Args:
      username: The username to check for membership.
      email_list: The mailing list to look for the username in.

    Returns:
      True or False depending on if the email list contains the given user.

    For example, I am subscribed to webmirror-tech@ who is subscribed to
    crawlops@, a search for crawlops should show me subscribed to it.
    """
    email_regex = re.compile(_EMAIL_PAT % re.escape(username), re.MULTILINE)
    return cls._CheckForEmail(email_regex, _CleanForShell(email_list))

  @classmethod
  def GetFixHint(cls, _, group_tup):
    """Return a hint on how to join the relevant mailing list.

    Args:
      username: the username of the affected user.
      group_tup: (check_groups_group, email_group, rationale)

    Returns:
      A human-readable (English) string explaining what the user should do.
    """
    return ('see https://groups.google.com/a/google.com/group/%s/?tab=mg' %
            (group_tup[1]))


class PagerCheck(GroupCheck):

  """Checks that a user has a valid pager address."""
  NAME = 'pager'
  PRETTY_NAME = 'pager alias'
  _WHAT_TO_DO = 'see /home/build/ops/data/mail/pagers'

  @classmethod
  def _Check(cls, username, email_substring):
    """Checks that a user's pager alias has a certain address or domain.

    Args:
      username: The user whose pager alias we're checking.
      email_substring: Some string that must be contained in the expansion
      of the pager alias.

    Returns:
      True or False depending if the user's pager alias has the right string in
      it.
    """
    email_regex = re.compile(email_substring, re.MULTILINE)
    return _CheckForEmail(email_regex, ['%s-pager' % username])


class LogsCheck(GroupCheck):

  """Checks that a user has logs access."""
  NAME = 'logs'
  PRETTY_NAME = 'logs access'
  _WHAT_TO_DO = 'see http://go/logs-access'

  LOGS_REPORT = '/home/build/static/projects/logs/accesstools/report'

  @classmethod
  def _Check(cls, username, logs_query):
    """Checks that a user has the specified logs access.

    Args:
      username: The user whose logs access we're checking.
      logs_query: a string; see the comments for TextQuery in
        //logs/accesstools:report.py for the syntax.

    Returns:
      True or False, depending whether the user's permissions match the query.
    """

    logging.debug('Checking for logs access "%s".', logs_query)

    command = "%s --query '%s' '%s'" % (cls.LOGS_REPORT, username, logs_query)
    (status, report_result) = _GET_STATUS_OUTPUT(command)
    report_result = report_result.strip()

    # The output should be 'True' or 'False'.  Convert it to bool.
    if status == 0 and report_result == 'True':
      return True
    if status == 0 and report_result == 'False':
      return False

    logging.warning('Error running %s, got: %s', command, report_result)
    return False


class OwnersCheck(GroupCheck):

  """Checks that the user is specified explicitly in an OWNERS file.

  This checks for the username being explicitly entered in the
  specified OWNERS file, not as part of another group.
  """
  NAME = 'owners'
  PRETTY_NAME = 'owners files'
  _WHAT_TO_DO = ('see http://www.corp.google.com/eng/howto/perforce/'
                 'OWNERS_files.html')
  _IS_CASE_SENSITIVE = True
  _NON_COMMENT_REGEX = re.compile('[^#]+')

  @classmethod
  def _Check(cls, username, owners_file):
    """Checks that a user is explicitly mentioned in an OWNERS file.

    Args:
      username: The user whose access we're checking.
      owners_file: The owners file to check, relative to /home/build.

    Returns:
      True or False depending if the user is present.
    """
    logging.debug('Searching OWNERS file %s for %s', owners_file, username)

    # Check for group membership.
    return cls.UserInOwnersFile(username, owners_file)

  @classmethod
  def UserInOwnersFile(cls, username, owners_file):
    """Check that 'username' is in the OWNERS file 'owners_file'."""
    f = None
    try:
      try:
        if owners_file.startswith('google3/production/mpmroot'):
          filename = os.path.join('/google/src/files/p5/head/depot',
                                  owners_file)
        else:
          filename = os.path.join('/home/build', owners_file)
        f = open(filename, 'r')
        for line in f:
          m = cls._NON_COMMENT_REGEX.match(line)
          if m and m.group(0).strip() == username:
            return True
        return False
      except IOError, e:
        logging.warn('Failed to read Perforce OWNERS file %s: %s',
                     owners_file, e)
        return False
    finally:
      if f:
        f.close()


# These are the group types that we support in the section definitions of the
# configuration file given to this script.
_SUPPORTED_CHECKS = [
    EmailCheck,
    PagerCheck,
    MdbCheck,
    UnixGroupCheck,
    PerforceGroupCheck,
    BorgUsermapCheck,
    LogsCheck,
    OwnersCheck,
    ]


class ConfigurationChecker(object):
  """Checks that a given user is in the correct groups.

  This class knows how to read the configuration file, correctly check for each
  section if a user is a member of it, and report the groups that the user is
  not a member of.  This is the core of this program.
  """

  def __init__(self, config, user):
    """Initializes this ConfigurationChecker with the given configuration.

    Args:
      config: ConfigParser object with config file loaded into it.
      user: User to check group memeberships for.
    """
    self._config = config
    self._user = user

  def _GetOptions(self, section_name):
    try:
      for option in self._config.options(section_name):
        entry = self._config.get(section_name, option)
        yield option, entry

    except ConfigParser.NoSectionError:
      # Assume no programming errors, that all sections given to this method
      # and not marked optional actually should exist.
      if ':optional:' not in section_name:
        error_msg = ('Required section [%s] missing from configuration file.' %
                     section_name)
        _PrintUsageAndExit(error=error_msg)

  def _PreloadEmailCheck(self, classes):
    all_lists = set()
    for req_opt in ('required', 'optional'):
      for check_class in classes:
        section_name = '%s:%s:%s' % (check_class, req_opt, EmailCheck.NAME)
        for option, _ in self._GetOptions(section_name):
          all_lists.add(option)
    EmailCheck.Preload(self._user, all_lists)

  def _ExpandClassInclusions(self, base_classes):
    """Expands out class :meta:include options.

    This allows classes to compose themselves of other classes so as to not
    duplicate information unnecessarily, nor balloon the number of classes a
    person is expected to check.

    Args:
      base_classes: list of classes to expand out.

    Returns:
      set of classes with the includes expanded out.
    """

    parents = set()

    for base_class in base_classes:
      section_name = '%s:%s:%s' % (base_class, 'meta', 'include')

      if self._config.has_section(section_name):
        for parent, _ in self._GetOptions(section_name):
          parents.add(parent)

    # Find parents-of-parents.
    if parents:
      parents = parents.union(self._ExpandClassInclusions(parents))

    return parents.union(base_classes)

  def CheckMemberships(self, classes):
    """Checks that a user is in the correct groups, and reports any errors.

    This iterates over the configuration file given when creating this object
    and checks that the user is a member of any groups it finds that match the
    classes given.

    Missing groups are reported through the use of a MissingGroupTracker.

    Note that if the config file is incorrect, this will call sys.exit() and
    stop immediately letting the user know (through PrintUsageAndExit).

    Args:
      classes: List of classes of groups to check.

    Returns:
      Nothing, this prints all of its findings out.
    """
    mgt = MissingGroupTracker(self._user)

    classes = self._ExpandClassInclusions(classes)

    logging.info('Expanded classes to %s', ', '.join(classes))

    self._PreloadEmailCheck(classes)

    for checker in _SUPPORTED_CHECKS:
      for req_opt in ('required', 'optional'):
        for check_class in classes:
          logging.info('Checking %s %s for class %s', req_opt,
                       checker.PRETTY_NAME,
                       check_class)

          missing_groups = self._CheckMembershipInSection(check_class,
                                                          req_opt,
                                                          checker)

          if missing_groups:
            for mg in missing_groups:
              mgt.AddMissingGroup(checker, req_opt, check_class, mg,
                                  missing_groups[mg])

    mgt.ReportMissingGroups()

  def _CheckMembershipInSection(self, check_class, req_opt, checker):
    """Checks that the user is a member of the groups in the given section.

    For every entry in the config file section name as given by
    'check_class:req_opt:section' uses the given check_object to see if the
    instance's username is in that group.

    Returns a dict with the key being the name of the group they're missing
    membership in, and the value being a description of it.  If you get an
    empty dict back, they're missing no memberships.

    Note that if the config file is incorrect, this will call sys.exit() and
    stop immediately letting the user know (through PrintUsageAndExit).

    Args:
      check_class: The name of the class of groups.
      req_opt: "required" or "optional".
      checker: A method that takes a username and group name and
          checks for membership. Generally should be a value returned from
          _SUPPORTED_SECTIONS

    Returns:
      {missing_group: group_description, ...}
    """
    missing_groups = {}

    section_name = '%s:%s:%s' % (check_class, req_opt, checker.NAME)

    for option, entry in self._GetOptions(section_name):
      entry = self._config.get(section_name, option)
      logging.debug('Found option %s with value %s', option, entry)

      if checker.Check(self._user, option):
        logging.debug('%s is a member of %s', self._user, option)
      else:
        logging.debug('%s is NOT a member of %s', self._user, option)
        missing_groups[option] = entry

    return missing_groups


class MissingGroupTracker(object):

  """This class keeps track of all of the groups a user isn't in.

  The two methods users of this class will have to call are AddMissingGroup and
  ReportMissingGroups.  Just call AddMissing group with the information about
  the group the user isn't a member of for each group they're not a member of,
  then call ReportMissingGroups to print out a nice report of it.
  """

  # Tracking is done mainly through a dict of dicts of tuples.  The first key
  # is the group type (email_list, mdb_group, etc) the second key is 'required'
  # or 'optional', and the third level is a tuple with the first value being the
  # class that required that group, the second the group, and the third the
  # description of the group.  Eventually this should probably be refactored
  # into a class heirarchy.

  # Example:
  # dict {
  #   'email_list': {
  #     'required': [
  #       ('crawlindex,logs-sre,dropsafe', 'cil-team', 'CIL SRE List'),
  #     ],
  #     'optional': [
  #       ('crawlindex', 'borgmon-users', 'Borgmon help'),
  #       ('gws-push', 'search-team', 'Production talk'),
  #     ],
  #   },
  #   'mdb_group': {...},
  # }

  def __init__(self, username):
    """Sets up this object to track missing groups for the given user.

    Args:
      username: The user this object is tracking missing groups for.
    """
    self._tracker = {}
    self._username = username

  def AddMissingGroup(self, checker, req_opt, config_class, group, desc):
    """Tracks that the user isn't a member of the given group.

    Args:
      checker: The checker class responsible for the current check.
      req_opt: One of "required", or "optional".
      config_class: The name of the class in the config file that needs this
          group, i.e. "crawlindex", "logs-sre", "gws-push"
      group: The actual group the user isn't a member of, i.e. cil-team,
          webmirror-sre, gws-team, etc.
      desc: A description of the group.

    Returns:
      Nothing
    Raises:
      ValueError: req_opt is neither 'required' nor 'optional'.
    """
    if req_opt not in ('required', 'optional'):
      raise ValueError("Must pass 'required' or 'optional' as the req_opt arg")

    if checker not in self._tracker:
      self._tracker[checker] = {}
    if req_opt not in self._tracker[checker]:
      self._tracker[checker][req_opt] = []

    self._tracker[checker][req_opt].append((config_class, group, desc))

  def ReportMissingGroups(self):
    """Prints a report of the groups the user isn't a part of."""
    for checker in self._tracker:
      for req_opt in self._tracker[checker]:
        if self._tracker[checker][req_opt]:
          print '\n%s is missing memberships in the %s %s' % (
              self._username, req_opt, checker.PRETTY_NAME)

          for group_tup in self._tracker[checker][req_opt]:
            print ' * %s : (%s) %s' % (group_tup[1], group_tup[0], group_tup[2])
            hint = checker.GetFixHint(self._username, group_tup)
            print '(%s)' % (hint,)


def _CheckForEmail(regex, email_list, max_depth=2):
  """Recursively search for a pattern in expn'd email addresses.

  Args:
    regex: A Pattern object to match against the email expansions.
    email_list: List of emails to check recursively for regex.
    max_depth: The number of times this method can be called recursively
        before we give up the search.

  Returns:
    True or False whether the matching regex was found.

  This runs as a breadth-first search.

  The stop condition is running expn on a mailing list/username that
  doesn't give us any @google.com addresses back.  Unless there are mail
  loops, this shouldn't be a problem.

  There is also a max_depth parameter, which allows us to make sure we don't
  iterate recursively if there is a huge chain of mailing lists, or if it
  gets stuck on a regular expression for a private mailing list, etc. This
  method will stop recursing when max_depth==0
  """

  clean_email = ' '.join(map(_CleanForShell, email_list))

  logging.debug("Searching '%s' for /%s/", clean_email, regex.pattern)

  (status, expn_result) = _GET_STATUS_OUTPUT(
      '%s %s' % (FLAGS.expn_command, clean_email))

  if status != 0:
    # Don't give up if there was a "User unknown", common when people leave
    if '>... User unknown>' not in expn_result:
      logging.info('Error running expn %s, got: %s', clean_email, expn_result)
      return False

  logging.debug('For %s found:\n%s', clean_email, expn_result)

  # Match the regex against the results of the expn
  email_match = regex.search(expn_result)
  if email_match:
    logging.debug('Found %s == /%s/', email_match.group(0), regex)
    return True
  else:
    # If max_depth is 0, we don't recurse any farther
    if max_depth <= 0:
      return False
    max_depth -= 1

    # Now search recursively, since we didn't find a match, but only search
    # @google.com addresses since that's only what will expand.
    check_emails = []
    for line in set(expn_result.splitlines()):
      idx = line.find('@google.com')
      if idx >= 0:
        check_emails.append(line[0:idx])
        if len(check_emails) >= MAX_EXPN_ARGS:
          if _CheckForEmail(regex, check_emails, max_depth):
            return True
          else:
            del check_emails[:]
    else:
      if check_emails:
        return _CheckForEmail(regex, check_emails, max_depth)

    return False


def _CleanForShell(string):
  """Removes chars not in [A-Za-z0-9-_.+] from the string and returns it.

  This takes a string, and removes any characters that wouldn't be safe to pass
  to the shell from it and returns the string.  This method probably won't be
  useful except to functions in this file because it assumes that you never
  want to pass special characters to the shell.

  Args:
    string: A string you want to pass to the shell as part of a command without
        it keeping you up at night.

  Returns:
    A copy of string with all non alphanumeric, -, + and _, removed.
  """
  return re.sub(r'[^-.+\w]', '', string)


def _ListClasses(config):
  """Lists all of the classes supported by an initialized ConfigParser object.

  Args:
    config: A ConfigParser object initialized with the values from the
        configuration file given to this script.

  Returns:
    Nothing, this prints all of its results out.
  """
  classes = {}

  for section in config.sections():
    match = re.match(r'(\S+):(\S+):(\S+)', section)
    classes[match.group(1)] = 1

  print 'Supported classes: '
  class_list = classes.keys()
  class_list.sort()
  for c in class_list:
    print ' * %s' % c

  print


def _PrintUsageAndExit(error=''):
  """Prints out an optional error message, then the usage, and exits.

  Args:
    error: (optional) An error message to display before the usage

  Returns:
    Nothing, this exits when finished.
  """
  exit_val = 0
  if error:
    print '\nERROR: %s\n' % error
    exit_val = 1

  app.usage()
  sys.exit(exit_val)


def main(argv):
  """Fetches args, reads the config file, and starts the checking.

  Args:
    argv: Arguments to the script, not used other than for checking for
          improper usage.
  """
  # argv should only contain the script that was executed
  if len(argv) > 1:
    del argv[0]
    _PrintUsageAndExit(error='This script takes no positional arguments: %s'
                       % str(argv))

  if not FLAGS.config:
    if FLAGS.users:
      if FLAGS.users.find(',') >= 0:
        # More than 1 user given, make user specify configuration
        _PrintUsageAndExit(error='--config is a required flag.')
      else:
        user = FLAGS.users
    else:
      user = os.environ.get('USER')

    email_regex = re.compile(_EMAIL_PAT % re.escape(user), re.MULTILINE)

    config_root = ('/google/src/head/depot/google3/production/tools/'
                   'check_groups/conf')
    if _CheckForEmail(email_regex, ['sre-team'], max_depth=0):
      logging.info('No --config specified, defaulting to sre.cfg')
      FLAGS.config = os.path.join(config_root, 'sre.cfg')
    elif _CheckForEmail(email_regex, ['quantitative-team'], max_depth=0):
      logging.info('No --config specified, defaulting to quant/quant.cfg')
      FLAGS.config = os.path.join(config_root, 'quant/quant.cfg')
    else:
      _PrintUsageAndExit(error='--config is a required flag.')

  if os.path.exists(FLAGS.config):
    pass
  elif os.path.exists(_DEFAULT_CONFIG_PATH % FLAGS.config):
    FLAGS.config = _DEFAULT_CONFIG_PATH % FLAGS.config
  else:
    _PrintUsageAndExit(error=('Config file %s does not exist or '
                              'I can\'t read it!') % FLAGS.config)

  config = ConfigParser.ConfigParser()
  config.optionxform = str  # Owners require case insensitivity.
  config.read(FLAGS.config)

  if FLAGS.list_classes:
    _ListClasses(config)
    sys.exit(0)

  # complain if they don't give us --classes
  if not FLAGS.classes:
    _PrintUsageAndExit(error='One of --classes or --list_classes is required.')

  # Complain if they're running out of /home/build, since they won't get
  # perforce checks, but don't die since they still get some use of it.
  if os.getcwd().startswith('/home/build'):
    logging.warn('**** Running out of /home/build: '
                 'Don\'t expect perforce checks to work. ****')

  # Default to $USER, but use --user if they give it
  if FLAGS.users:
    test_users = FLAGS.users.split(',')
  else:
    test_users = [os.environ.get('USER')]

  for each_user in test_users:
    logging.info('Starting analysis for user %s', each_user)
    cc = ConfigurationChecker(config, each_user)
    cc.CheckMemberships(FLAGS.classes)


if __name__ == '__main__':
  app.run()