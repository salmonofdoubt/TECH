#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/inotify.h>

//function signatures
void get_event (int fd, const char * target);
void handle_error (int error);

/* ----------------------------------------------------------------- */

int main (int argc, char *argv[])
{
   char target[FILENAME_MAX];
   int result;
   int fd;
   int wd;   /* watch descriptor */

   if (argc < 2) {
      fprintf (stderr, "Watching the current directory\n");
      strcpy (target, ".");
   }
   else {
      fprintf (stderr, "Watching %s\n", argv[1]);
      strcpy (target, argv[1]);
   }

   //filedescriptor that is returned by inotify_init
   fd = inotify_init();
   if (fd < 0) {
      handle_error (errno);
      return 1;
   }
   
   //watchdescriptor
   wd = inotify_add_watch (fd, target, IN_ALL_EVENTS);
   if (wd < 0) {
      handle_error (errno);
      return 1;
   }
   
   while (1) {
      get_event(fd, target);
   }

   return 0;
}

/* ----------------------------------------------------------------- */
/* Allow for 10 simultanious events */
#define BUFF_SIZE ((sizeof(struct inotify_event)+FILENAME_MAX)*10)
void get_event (int fd, const char * target)
{
   ssize_t len, i = 0;
   char action[81+FILENAME_MAX] = {0};
   char buff[BUFF_SIZE] = {0};
   len = read (fd, buff, BUFF_SIZE);
   
   while (i < len) {
      struct inotify_event *pevent = (struct inotify_event *)&buff[i];
      char action[81+FILENAME_MAX] = {0};

      if (pevent->len) 
         strcpy (action, pevent->name);
      else
         strcpy (action, target);
    
      if (pevent->mask & IN_ACCESS)       strcat(action, " was read");
      if (pevent->mask & IN_ATTRIB)       strcat(action, " Metadata changed");
      if (pevent->mask & IN_CLOSE_WRITE)  strcat(action, " opened for writing was closed");
      if (pevent->mask & IN_CLOSE_NOWRITE)strcat(action, " not opened for writing was closed");
      if (pevent->mask & IN_CREATE)       strcat(action, " created in watched directory");
      if (pevent->mask & IN_DELETE)       strcat(action, " deleted from watched directory");
      if (pevent->mask & IN_DELETE_SELF)  strcat(action, "Watched file/directory was itself deleted");
      if (pevent->mask & IN_MODIFY)       strcat(action, " was modified");
      if (pevent->mask & IN_MOVE_SELF)    strcat(action, "Watched file/directory was itself moved");
      if (pevent->mask & IN_MOVED_FROM)   strcat(action, " moved out of watched directory");
      if (pevent->mask & IN_MOVED_TO)     strcat(action, " moved into watched directory");
      if (pevent->mask & IN_OPEN)         strcat(action, " was opened");
 
   /*
      printf ("wd=%d mask=%d cookie=%d len=%d dir=%s\n",
              pevent->wd, pevent->mask, pevent->cookie, pevent->len, 
              (pevent->mask & IN_ISDIR)?"yes":"no");

      if (pevent->len) printf ("name=%s\n", pevent->name);
   */

      printf ("%s\n", action);
      
      i += sizeof(struct inotify_event) + pevent->len;

   }

}  /* get_event */

/* ----------------------------------------------------------------- */

void handle_error (int error)
{
   fprintf (stderr, "Error: %s\n", strerror(error));

}  /* handle_error */

/* ----------------------------------------------------------------- */