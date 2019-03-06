#!/usr/bin/python2.4
#
# Copyright 2009 Google Inc. All Rights Reserved.

"""Tests for google3.codelab.pyquick.mdbregex.solution.machinewords."""

__author__ = 'alexperry@google.com (Alex Perry)'

import re

import google3
import mox

from google3.production.mdb import mdb_core
from google3.production.mdb import valueobject
from google3.pyglib import app
from google3.testing.pybase import googletest
from google3.codelab.pyquick.mdbregex import machinewords


class MachinesDatabaseTest(googletest.TestCase):

  def setUp(self):
    self.mox = mox.Mox()
    # Get the standard stuff in place until we can run a single search
    self.mox.StubOutWithMock(machinewords, 'mdb_core')
    self.mock_mdb_remotedb = self.mox.CreateMock(
        mdb_core.RemoteMachineDatabase)
    self.mock_mdb_handle = self.mox.CreateMock(mdb_core.RemoteMDBHandle)
    machinewords.mdb_core.RemoteMachineDatabase(read_only=True).AndReturn(
        self.mock_mdb_remotedb)
    self.mock_mdb_remotedb.Connect().AndReturn(
        self.mock_mdb_handle)
    self.mock_mdb_handle.Close()

  def tearDown(self):
    # Do not do VerifyAll for the student's code - initially
    self.mox.UnsetStubs()
    self.mox.ResetAll()

  def testDatacenters(self):
    # Set up the mock calls we need
    mock_mdb_query = self.mox.CreateMock(
        mdb_core.ListDatacenters)
    machinewords.mdb_core.ListDatacenters(
        self.mock_mdb_remotedb).AndReturn(mock_mdb_query)
    mock_datacenters = [
        valueobject.ValueObject({'value': 0}, (dc,))
        for dc in ['ye', 'ti']]
    mock_mdb_query.Retrieve(self.mock_mdb_handle).AndReturn(
        mock_datacenters)
    self.mox.ReplayAll()
    # Use the mock
    regex = machinewords.BuildRacknameRe({'0': 'o', '1': 'li'})
    # Check the returned string is usable
    machine_re = re.compile(regex, re.IGNORECASE)
    self.assert_(machine_re.match('yeti'))
    self.assert_(machine_re.match('yell\n'))
    self.assert_(not machine_re.match('yeties'))
    self.assert_(not machine_re.match('yale'))

  def testRacks(self):
    # Set up the mock calls we need
    mock_mdb_query = self.mox.CreateMock(
        mdb_core.ListMachines)
    machinewords.mdb_core.ListMachines(
        self.mock_mdb_remotedb).AndReturn(mock_mdb_query)
    mock_desired_racks = ['yet']
    mock_mdb_query.SetRacks(mock_desired_racks)
    mock_machines = [
        valueobject.ValueObject({'machine_name': 0}, (m + str(i),))
        for m in mock_desired_racks for i in [1, 2, 3]]
    mock_mdb_query.Retrieve(self.mock_mdb_handle).AndReturn(
        mock_machines)
    self.mox.ReplayAll()
    # Use the mock
    found = machinewords.GetMachinesWithinRacks(mock_desired_racks)
    # Check the result
    self.assertEqual(found, [m.machine_name for m in mock_machines])


def main(unused_argv):
  googletest.main()


if __name__ == '__main__':
  app.run()
