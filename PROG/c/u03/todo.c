- processes and its signals, and signalmasks
- Kevins server code 
- close actual no. of fds open, remove any fds
- OKish deal with zombies (sigchild)

To deal with zombies you have three choices: 
a) live with it 
b) fix the parent process (its obvious that the problem is there. 
The parent hadn't waited for it's children to finnish) 
c) kill the parent 

use system call waitpid to wait for a specific process to terminate.

So lets look at the basics first, LIP:

***exec() 
as such does not exist. There are letters.  
514
- The execve(pathname, argv, envp) system call loads a new program (pathname,
with argument list argv, and environment list envp) into a process’s memory.
- The existing program text is discarded, and the stack, data, and heap segments
are freshly created for the new program. This operation is often referred to as
execing a new program 

563–576
#include <unistd.h>
- int execve(const char *pathname, char *const argv[], char *const envp[]);
  Never returns on success; returns –1 on error
- After an execve(), the process ID of the process remains the same, because the same
process continues to exist


32, 286, 345, 514, 563–579, 690, 801
effect on process attributes, 612–615
file descriptors and, 575–578
in multithreaded process, 605
process capabilities and, 805
set-user-ID program and, 169
signals and, 578–579
threads and, 686

***inetd (Internet superserver daemon), 
768, 1247–1251

***bash 

***fork #include <unistd.h>
-after it has completed its work, two processes exist, and, in each process, execution continues from the point where fork() returns.

pid_t fork(void);
- (pid_t is a type definition) 
- In parent: returns PID of child on success, or –1 on error; 
  to deal with say wait() on children: use getppid()
- in child: always returns 0
  to get it's own PID: getpid()

man 3 exec
man dup2


------------------
Mon Nov 14
------------------

READ
- Real, Effective, Saved UID
- deamonize a process

init(1) on top
- httpd
- inetd
...
- bash(pid 100) wait for login, execs login, so you login
	- then vi(101) 			(bash forks out vi)			1 PG
	- then grep(102)		(grep 3 /etc/passwd)		2 PG
		- with less(103)	(grep forks out less)		2 PG
	- server_fork(104)
	
all are in process groups PG
	- setsid()
	- setppid()
	
the whole bash with its forks is one session

so if terminal finishes, the topmost gets a SIGHUP, which is 
bash(), which is attached to stdin, stdout, stderr (/dev/tty0)
- then vi and grep get a SIGHUP also, delivered to the fg process.
- server_fork(104) will get a SIGHUP too :(

-> "disown" can be used to informs that server_fork 
		should not be notified of SIGHUP		
		fg / bg

So how to handle this better?
- take server_fork out of the PG that belongs to bash
- fork server_fork, and give it a setppid() and setsid()
- so it lives under inet(1)
- exit the parent (which lives in the bash PG)

- only the session leader should cease control
- but say open() returns control to a dev/tty again
- so before fork server_fork, become session leader, a deamon
	setsid()		-- creates new session and PG
		if(fork()){
			exit(0); 
		}
		loop();
		
	fork() -- 105 exit()
	
	A real Deamon runs disconnected!
	
	Steps
	=====
	bash -> reads server()
	bash forks -> parent
						 -> child -> exec(./server)
								setsid()
								fork -> parent exit(0)
										 -> child dowork()
													getcmd()?
													umask()?
													getlimit()?
													getuid()?
													
	Objective: get this to run and write PID to a file.
	
	cheating with crond?
	
	
	take care of closing old fd (dup2 does the trick).
	fd = open("/dev/null, O_RDONLY");
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	
	deal with userid
	----------------
	REAL UID				103		103
	EFFECTIVE UID		0 		65000 
	SAVED UID				103		0
	
	(root) chown root /server
	(root) chmod u+s  /server	
	so run setuid(65000)
	x -> y
	
	
	----------------------
	TUE
	----------------------
	run as 'nobody'
	
	logfile:
	cat /tmp/exampled.log
	
	fuser
	which processes are using a specified file, file system, or unix socket.  
	
	top -pid <of_ur_server>
	
	open FDs? check 
	lsof -i :10000

init can change runlevel
http://en.wikipedia.org/wiki/Runlevel
http://en.wikipedia.org/wiki/Fuser_(Unix)
http://en.wikipedia.org/wiki/Lsof

	scripts:
	/etc/init.d/sshd
		/etc/init.d/S20sshd 
		/etc/rc6.d/K20sshd 
		
		both say symlinks to /etc/init.d/sshd
		K kill  (ascibetical order: K1, K10, K19, K2 etc.)
		S start
		
switching between runlevels

daemontools
use at least a config file to start stop
	if not started and kill, print message to start first.
	if not killed and start, print already started. 
	e.g. init stuff is configured in /etc/init.conf and/or /etc/init/*.conf*/
	
	-----------------------
	WED
	-----------------------
	
	umask
	------
	open(path, flags, mode);	
		
		- flags 
		O_RDWR O_CREATE O_TRUNC O_EXEC
		O_CREATE: what perms on the file, only then the mode is required
		
		- mode
		setuid, setgid, stickybit(dir)
			0				0				0
	oct					4
			---------------------------
			owner		group		any
			r	w	e		r	w	e		r	w	e
1			1	0	0		1	0	0		1	0	0		perms given
	000	0	0	0		0	1	0		0	1	0		umask 0022
2	111	1	1	1		1	0	1		1	0	1		not
	100	1	1	0		1	0 0		1	0	0		add 1,2


	setting umask(0022) 022   clears bits
	daemon has umask 0
	
	create_mode = open_mode & (~umask)
	
	http://en.wikipedia.org/wiki/Sticky_bit
	http://en.wikipedia.org/wiki/Umask
	http://content.hccfl.edu/pollock/AUnix1/FilePermissions.htm
	
	- directories
					o		g		a
					rwx	rwx	rwx
	suid
	sgid
	sticky
	------------------
		7			7		7		7
	
	nobody:nogroup
	
	- UID
	real UID
	eff UID
	saved UID
	
	- Group management
	/etc/group
		grp  :*:307:fred, george, max
		other:*:308:fred,george
		lads :*:309:max
		
	now, at login:
	/bin/login	
		setreuid()
		initgroups() a libcall > setgroups()
		setgroups() will figure the groups
		setgid(307)	(etc/passwd fred:*:101:307:...) 
		
	root can make nobody
	
	initgroups("fred", 307)
	



















