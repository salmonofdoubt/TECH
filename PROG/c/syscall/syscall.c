/*
more advanced topic, stay cool
poll a (curr) direcory, watch for any events, here simply IN_ACCESS
inotify_init is a sys library 

Create inotify monitoring list. Add the desired directories/files to the inotify monitoring list. Monitoring list can be changed as and when needed
Request Inotify to report specific event changes to the monitoring list of files and directories. For example, request inotify to report ON ACCESS, ON OPEN, ON WRITING, ON CLOSE,etc.,

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <inotify.h>
#include <inotify-syscalls.h>

int main(int argc, char *argv[])
{
  // creating an inotify instance, returns filedescriptor (fd)
  int inotify_init(void);
  int fd;
  fd = inotify_init();       //returns a struct
  if (fd < 0)
  perror ("inotify_init");

                       
  //use actual watches, such as pathname 
  int wd1;
  wd1 = inotify_add_watch (int fd, 
                          "/home/abaumann/sreu/c/syscall",
                          IN_ACCESS | IN_MODIFY | IN_CREATE | IN_DELETE);
  
  if (wd < 0)
    perror("inotify_add_watch");
    
//-----create the event structure, according to man structure    
    struct inotify_event {
               int      wd;       // Watch descriptor 
               uint32_t mask;     // Mask of events 
               uint32_t cookie;   // Unique cookie associating related events (for    rename(2)) 
               uint32_t len;      // Size of name field 
               char     name[];   // Optional null-terminated name 
             };             
         }
         

/* size of the event structure, not counting name */
#define EVENT_SIZE  (sizeof (struct inotify_event))

/* reasonable guess as to size of 1024 events */
#define BUF_LEN        (1024 * (EVENT_SIZE + 16)

char buf[BUF_LEN];
int len, i = 0;

len = read (fd, buf, BUF_LEN);
if (len < 0) {
        if (errno == EINTR)
                /* need to reissue system call */
        else
                perror ("read");
} else if (!len)
        /* BUF_LEN too small? */

while (i < len) {
        struct inotify_event *event;

        event = (struct inotify_event *) &buf[i];

        printf ("wd=%d mask=%u cookie=%u len=%u\n",
                event->wd, event->mask,
                event->cookie, event->len);

        if (event->len)
                printf ("name=%s\n", event->name);

        i += EVENT_SIZE + event->len;
}


  
//2. selecting and looping 
select () //list of fds to watch
read()    //and then loop back


//---------------call functions tbd --------------



