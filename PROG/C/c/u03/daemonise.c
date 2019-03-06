int daemonise(int ear){
  int maxfd, fd;

  switch(fork()){
  case -1: return -1;
  case 0: break;
  default: exit(EXIT_SUCCESS);
  }

  /* become session leader */
  if(setsid() < 0) return -1;

  /*quit the job of session leader*/
  switch(fork()){
  case -1: return -1;
  case 0: break;
  default: exit(EXIT_SUCCESS);
  }

  umask(0);

  if(setuid(65534) < 0)
    err(EXIT_FAILURE, "setuid() failed\n");
  
  if(chdir("/") < 0)
    err(EXIT_FAILURE, "chdir() failed\n");

  maxfd = sysconf(_SC_OPEN_MAX);
  if(maxfd == -1)
    maxfd = 1024;
  for(; maxfd >= 0; maxfd--) {
    if(maxfd != ear) 
      close(maxfd);
  }
  return 0;
}

