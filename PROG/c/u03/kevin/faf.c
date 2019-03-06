#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
 * Signal handler function to reap children.
 */
static void
clean_up_child(int sig, siginfo_t *si, void *unused)
{
  int status;
  pid_t pid;

  do {
    pid = wait3(&status, WNOHANG, NULL);
    if (pid > 0) {
      printf("INFO: Child %d exited with exit status %d.\n",
             pid, WEXITSTATUS(status));
    }
  } while (pid > 0);
}

/*
 * Signal handler function to exit with a nice message.
 */
static void
close_down(int sig, siginfo_t *si, void *unused)
{
  printf("INFO: Exiting, bye!\n");
  exit(EXIT_SUCCESS);
}

/*
 * Helper function to register a signal handler "handler" for signal "sig."
 */
void
register_handler(int sig, void (*handler)(int, siginfo_t *, void *))
{
  struct sigaction *sa;

  sa = (struct sigaction *)malloc(sizeof(struct sigaction));
  sa->sa_flags = SA_SIGINFO;
  sigemptyset(&sa->sa_mask);
  sa->sa_sigaction = handler;
  if (sigaction(sig, sa, NULL) == -1) {
    perror("ERROR: sigaction failed");
    exit(EXIT_FAILURE);
  }
}

/*
 * Helper function to register a signal handler "handler" for signal "sig."
 */
int
bind_to_host_port(const char *host, const char *port)
{
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int ear, s;
  int reuseaddr_val = 1;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;  /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_STREAM; /* Stream socket */
  hints.ai_flags = AI_PASSIVE;  /* For wildcard IP address */
  hints.ai_protocol = 0;      /* Any protocol */
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  s = getaddrinfo(host, port, &hints, &result);
  if (s != 0) {
    fprintf(stderr, "ERROR: getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  /* getaddrinfo() returns a list of address structures.
     Try each address until we successfully bind(2).
     If socket(2) (or bind(2)) fails, we (close the socket
     and) try the next address. */

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    ear = socket(rp->ai_family, rp->ai_socktype,
        rp->ai_protocol);
    if (ear == -1)
      continue;

    setsockopt(ear, SOL_SOCKET, SO_REUSEADDR,
               &reuseaddr_val, sizeof(reuseaddr_val));
    if (bind(ear, rp->ai_addr, rp->ai_addrlen) == 0)
      break;          /* Success */

    close(ear);
  }

  if (rp == NULL) {         /* No address succeeded */
    fprintf(stderr, "ERROR: Could not bind\n");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);       /* No longer needed */

  return ear;
}

/*
 * Helper function to log address info.
 */
void
log_client_info(struct sockaddr *peer_addr, socklen_t peer_addr_len)
{
  int s;
  char host[NI_MAXHOST], service[NI_MAXSERV];

  s = getnameinfo(peer_addr,
          peer_addr_len, host, NI_MAXHOST,
          service, NI_MAXSERV, NI_NUMERICSERV);
   if (s == 0)
    printf("INFO: Connection from %s:%s\n", host, service);
  else
    fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
}

/*
 * Helper macro to dup2 only if the old_fd != new_fd.
 */
#define DUP2W_CHK(old_fd, new_fd) if (old_fd != new_fd) dup2(old_fd, new_fd)

int
main(int argc, char *argv[])
{
  int ear, client;
  struct sockaddr peer_addr;
  socklen_t peer_addr_len;
  pid_t pid;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <local-address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  printf("INFO: Server running as pid %d.\n", getpid());

  register_handler(SIGCHLD, clean_up_child);
  register_handler(SIGHUP, close_down);
  register_handler(SIGTERM, close_down);

  ear = bind_to_host_port(argv[1], argv[2]);
  fcntl(ear, F_SETFL, FD_CLOEXEC, 1);

  listen(ear, 5);

  /* Get connections and send them a fortune. */

  for (;;) {
    peer_addr_len = sizeof(struct sockaddr);
    client = accept(ear, &peer_addr, &peer_addr_len);

    if (client < 0) {
      printf("INFO: hiccup!\n");
      continue;
    }

    log_client_info(&peer_addr, peer_addr_len);

    pid = fork();
    if (pid < 0) {
      /* Parent: deal with fork() error. */
      perror("ERROR: fork");
    } else if (pid > 0) {
      /* Parent: deal with fork() success. */
      close(client);
    } else {
      /* Child: Prep environment and exec command. */
      int fd;

      close(ear);
      /* Kind of a kludgy way to do this. */
      for (fd = 0; fd < 100; fd++) {
        if (fd != client) {
          close(fd);
        }
      }
      DUP2W_CHK(client, STDIN_FILENO);
      DUP2W_CHK(client, STDOUT_FILENO);
      DUP2W_CHK(client, STDERR_FILENO);
      if (client > STDERR_FILENO) close(client);
      if (execlp("ls", "/tmp", NULL) == -1) {
        perror("ERROR: execlp");
        exit(EXIT_FAILURE);
      }
    }

  }
}
