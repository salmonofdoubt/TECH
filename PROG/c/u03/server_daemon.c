/*
A server that forks a child that runs an exec(). Supposed to become a daemon that is independent from the tty bash process group.
Problem with this code it deals with all resulting zombies but 1. 
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>	/*fork*/
#include <sys/wait.h>	/*deal with zombie*/
#include <sys/types.h>	/* -"- */
#include <fcntl.h>
#include <signal.h>

#define RUNNING_DIR	"/tmp"
#define LOCK_FILE	"server_daemon.lock"
#define LOG_FILE	"server_daemon.log"

void log_message(filename, message)
char *filename;
char *message;

{
FILE *logfile;
	logfile=fopen(filename,"a");
	if(!logfile) return;
	fprintf(logfile,"%s\n",message);
	fclose(logfile);
}

/*all fct signatures go here*/
void do_child_stuff (int sock);
void deal_with_zombies (int sig);
void signal_handler(int sig);
/* extra function used for daemonizing */
void make_daemon();

int main( int argc, char *argv[] ){
	int sockfd, newsockfd, port_number, clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	int child_pid;
	int daemon_pid;

	int SIG = -20;		/*SIGCHLD can be 20,17,18*/
	pid_t cpid, w;
	int status;
	
	/*get portnumber*/
	if (argc < 2 ) { 
		fprintf(stderr,"ERROR, argc[1] == portnumber\n");
		exit(1);
		}
	/*convert input to int*/
	port_number = atoi(argv[1]);

	/*use high port*/
	if (port_number < 1024 || port_number > 65535) { 
		fprintf(stderr,"ERROR, argc[1] == needs to be a high port\n");
		exit(1);
		}
		/* Deamonization probably starts here, after we got the cmd args */
	make_daemon();

	/* First call to socket() function */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
		}
	/* Initialize socket structure */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port_number);

	/* Now bind the host address using bind() call.*/
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
		}
	/* Start listening for client connection */
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	while (1) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0) {
			perror("ERROR on accept");
			exit(1);
			}
		/* Creates child process */
	child_pid= fork();

	if (child_pid < 0) {
		perror("ERROR on fork");
		exit(1);
		}
	if (child_pid == 0) {
		close(sockfd);
	/* tbd close all fds 0,1,2 as the child will run an exec() and does not need those*/
		printf("\nINFO: main(): value of sockfd: %d", sockfd);
		printf("\nINFO: main(): value of newsockfd: %d", newsockfd);
		printf("\nINFO: main(): child PID: %ld\n", (long) getpid());
		log_message(LOG_FILE, "LOG: created child process");

		do_child_stuff(newsockfd);
    exit(0);
		}
		else {
			deal_with_zombies(SIG);
			close(newsockfd);
			}
		}
	} /* end of while */

void do_child_stuff (int child_sock) {
	int execute;
	char buffer[256];
	bzero(buffer,256);

	printf("\nINFO: do_child_stuff()\n\texecuting \"ls\" on client\n");
	/*getchar();*/

	/* Use the default fd values. Without dup2 the program will execute ls on server */
	if (child_sock != 0) dup2(child_sock, 0);
	if (child_sock != 1) dup2(child_sock, 1);
	if (child_sock != 2) dup2(child_sock, 2);

	//execute = execlp("ls", "/tmp", 0, 0);
	system("ls");
	printf("\n closing"); //this never happens
	printf("\nINFO: closed child_sock %d", close(child_sock));

	/*if it's not working:*/
	if (execute == -1) {
		close(child_sock); 
		perror("out: ");
		exit(2);
	}
}

void deal_with_zombies (int sig) {
	pid_t pid;
	int   status, message_size, banner;
	char  message[100];
	
	/*waitpid uses bitmasks*/
	while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {  
		banner = 
		snprintf(message, 100, "\nINFO: deal_with_zombies(): banner");
		write(STDOUT_FILENO, message, banner);

		message_size = 
		snprintf(message, 100, "\nINFO: deal_with_zombies(): PID %d terminated with status/signal %d\n", pid, status);
		write(STDOUT_FILENO, message, message_size);
	}
}

void signal_handler(sig) {
	switch(sig) {
		case SIGHUP:
			log_message(LOG_FILE,"LOG: caught sighup");
			break;
		case SIGTERM:
			log_message(LOG_FILE,"LOG: caught sigterm, user issued kill");
			exit(0);
			break;
	}
}

void make_daemon() {
	int i, lfp;
	char str[10];
	
	if(getppid()==1)
		return;	/* hey there is already a daemon */

	i = fork();
	if (i < 0)
		exit(1);	/* fork error */
	if (i > 0) 
		exit(0);	/* parent exits */

	/* all goes well child (daemon) can now continue */
	setsid();	/* obtain a new process group */
	
	for (i = getdtablesize(); i >= 0; --i)
		close(i);	/* close all descriptors */
	i = open("/dev/null",O_RDWR); dup(i); dup(i); /* handle standart I/O */
	umask(027);	/* set newly created file permissions */
	
	chdir(RUNNING_DIR);	/* change running directory */
	lfp = open(LOCK_FILE, O_RDWR | O_CREAT, 0640);
	
	if (lfp < 0)
		exit(1); /* can not open */
	if (lockf(lfp,F_TLOCK,0) < 0)
	 	exit(0); /* can not lock */

	/* first instance continues */
	sprintf(str,"%d\n",getpid());
	write(lfp,str,strlen(str));	/* record pid to lockfile */
	
	signal(SIGCHLD,SIG_IGN);	/* ignore child */
	signal(SIGTSTP,SIG_IGN);	/* ignore tty signals */
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGHUP,signal_handler);	/* catch hangup signal */
	signal(SIGTERM,signal_handler);	/* catch kill signal */
}
