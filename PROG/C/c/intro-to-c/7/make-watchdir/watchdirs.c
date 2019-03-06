#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>

#define BUFSIZE 4096
#define MAXDIRS 256

void usage(const char *progname) {
  printf("Usage: %s <path to dir...>\n", progname);
}

int main(int argc, char *argv[]) {
  int in_fd;                   // inotify file descriptor
  fd_set fds;                  // file descriptor set
  int select_result;           // return value from select()
  char buffer[BUFSIZE];        // buffer for reading events (struct inotify_event + filename pairs)
  int nread;                   // number of bytes read using read()
  struct inotify_event *event; // pointer to currently processed event
  int offset;                  // buffer offset in bytes
  int event_count;             // number of events processed in this pass
  
  if (argc < 2) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  if (argc > MAXDIRS + 1) {
    fprintf(stderr, "Can't handle more than %d paths", MAXDIRS);
  }

  in_fd = inotify_init();

  for (i = 1; i < argc; i++) {
    if (inotify_add_watch(in_fd, argv[i], IN_ALL_EVENTS) < 0) {
      perror("inotify_add_watch()");
      exit(EXIT_FAILURE);
    }
  }

  for (;;) {
    FD_ZERO(&fds);
    FD_SET(in_fd, &fds);
    select_result = select(in_fd + 1, &fds, NULL, NULL, NULL);
    if (select_result == -1) {
      perror("select()");
    } else if (select_result) {
      nread = read(in_fd, buffer, BUFSIZE);

      if (nread < 0) {
        perror("read()");
        exit(EXIT_FAILURE);
      }

      offset = 0;
      event_count = 1;
      while (offset < nread) {
        event = (struct inotify_event *)(buffer + offset);
        printf("event #%d:\n", event_count);
        if (event->mask & IN_ACCESS       ) printf(" event type: IN_ACCESS\n");
        if (event->mask & IN_ATTRIB       ) printf(" event type: IN_ATTRIB\n");
        if (event->mask & IN_CLOSE_WRITE  ) printf(" event type: IN_CLOSE_WRITE\n");
        if (event->mask & IN_CLOSE_NOWRITE) printf(" event type: IN_CLOSE_NOWRITE\n");
        if (event->mask & IN_CREATE       ) printf(" event type: IN_CREATE\n");
        if (event->mask & IN_DELETE       ) printf(" event type: IN_DELETE\n");
        if (event->mask & IN_DELETE_SELF  ) printf(" event type: IN_DELETE_SELF\n");
        if (event->mask & IN_MODIFY       ) printf(" event type: IN_MODIFY\n");
        if (event->mask & IN_MOVE_SELF    ) printf(" event type: IN_MOVE_SELF\n");
        if (event->mask & IN_MOVED_FROM   ) printf(" event type: IN_MOVED_FROM\n");
        if (event->mask & IN_MOVED_TO     ) printf(" event type: IN_MOVED_TO\n");
        if (event->mask & IN_OPEN         ) printf(" event type: IN_OPEN\n");
        printf(" filename length: %d\n", event->len);
        printf(" filename: %s\n", event->name);
        offset += sizeof(struct inotify_event) + event->len;
        event_count++;
      }
    }
  }

  exit(EXIT_SUCCESS); // Not reached
}
