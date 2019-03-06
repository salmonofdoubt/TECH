#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0


void error(const char *msg) {
  perror(msg);
  exit(1);
}

main (int argc, char *argv[]){

  
  int    len;           		//len of received data
  int    rc;            		//reusable connection socket
  int    on = 1;        		//reusable connection socket
  int    sock;		     			
  int 	 new_socket; 				
  int    port_number;   		//argv[1]
  int    end_server = FALSE, copy_array = FALSE;
  int    close_conn;	
  char   buffer[8];		// read in buffer, ought to be 256 
  struct sockaddr_in addr;	//declare struct
  int    timeout;		//will be 3 min
  struct pollfd fds[200]; 	//array of pollfd structures
  int    numfds = 1;		//specifies the number of items in the fds array.
  int 	 current_size = 0;	//size of currently readable fds
  int 	 i, j;

	//take portnumber
  	if (argc < 2 ) { 
    		fprintf(stderr,"ERROR, argc[1] == portnumber\n");
    		exit(1);
    	}

  	//convert string to int
  	port_number = atoi(argv[1]);

	  //use high port
  	if (port_number < 1024 || port_number > 65535) { 
		fprintf(stderr,"ERROR, argc[1] == needs to be a high port\n");
		exit(1);
	}

  //create a AF_INET stream socket, receives incoming connections
	sock = socket(AF_INET, SOCK_STREAM, 0);
 
  // man - socket can be reused
  rc = setsockopt(sock, SOL_SOCKET,  SO_REUSEADDR, (char *)&on, sizeof(on));
  //reusable socket set to be nonblocking
  rc = ioctl(sock, FIONBIO, (char *)&on);
 
  //bind socket to server addr
  memset(&addr, 0, sizeof(addr));							//fill byte string with a byte value
  addr.sin_family      = AF_INET;							//AddressFamilily
  addr.sin_addr.s_addr = htonl(INADDR_ANY);		//endian byte order
  addr.sin_port        = htons(port_number);	//endian port order 
  rc = bind(sock, (struct sockaddr *) &addr, sizeof(addr));
 
	//listen() and set the listen back log
  rc = listen(sock, 5); 
  
  //initialize block of memory for fds to size of fds                          
  memset(fds, 0 , sizeof(fds));	
	
  // Initialize the pollfd structure 
  fds[0].fd = sock; 				//Set up the initial listening socket
  fds[0].events = POLLIN;		//capture POLLIN in events
  timeout = (3 * 60 * 1000);	//timeout 3 mins


  //Do-while "poll" for 3 mins,  
  //waiting for incoming connects, or more data on existing sockets.
  do {   
    printf("ready...\n");								//i.e. poll is ready
    rc = poll(fds, numfds, timeout);  	// (..,numberof fds,..)
    
    // Check to see if the 3 minute time out expired.
    if (rc == 0) {
      printf("  poll() timed out.  End program.\n");
      break; 
    }
    // Check which fds are actually readable.                       
    current_size = numfds;
    for (i = 0; i < current_size; i++){
    // Loop to find descriptors that returned POLLIN, and determine 
	 	// if they are listening or are active connection.
		if(fds[i].revents == 0)
        continue;

      //If revents is not POLLIN, it's unexpected result, so end the server.
      if ((fds[i].revents & POLLIN) == 0)  {
        printf("  Error! revents = %d\n", fds[i].revents);
        end_server = TRUE;
        break;
        }

      // is listening sock readable?  
      if (fds[i].fd == sock){
        printf("  Listening socket is readable\n");
        // ...and accept() all incoming connections queued up on the 
        // listening socket. 
        // Then, loop back and call poll again.   
        do {
          new_socket = accept(sock, NULL, NULL); 
          // If accept fails with (macro int) EAGAIN, then all were accepted.
		  		// Other failures on accept will cause ending the server.
		  		if (new_socket < 0) {
            if (errno != EAGAIN) {
              perror("  accept() failed");
                end_server = TRUE;
                }
              break;
            }
          // Add the new incoming connection to the pollfd structure
          printf("  Made new_socket %d\n", new_socket);
          fds[numfds].fd = new_socket;
          fds[numfds].events = POLLIN;
          numfds++;

        // Loop back up and accept another incoming connection
        } while (new_socket != -1);  
      }	//end of if "is listening socket readable?"

      // existing connection must be readable
      else { 
        printf("  fd %d is readable\n", fds[i].fd);
        close_conn = FALSE;
        // Receive all incoming data on this socket before looping back
        // and then call poll again.  
        do {
        // Receive data on this connection until rec fails with EAGAIN.
        // Any other failure closes the connection
          rc = recv(fds[i].fd, buffer, sizeof(buffer), 0);
          if (rc < 0) {
            if (errno != EAGAIN) {
              perror("  recv() failed");
              close_conn = TRUE;
            }
            break;
          }

          //is connection closed by client ?
          if (rc == 0){
            printf("  Connection closed\n");
            close_conn = TRUE;
						numfds--;   //compression needed
            break;
          }
		  
          //What was received
          len = rc;
          printf("%d bytes received on server\n", len);

          // Echo the data back to the client
          rc = send(fds[i].fd, buffer, len, 0);
          if (rc < 0){
            perror("  send() failed");
            close_conn = TRUE;
            break;
          }
        } while(TRUE);	

      }   // end of else, end of existing connection is readable     
    }     // End of loop through pollable descriptors

    // With copy_array flag ON, squeeze together the array
    // and decrement the number of file descriptors. 
    if (copy_array){
      copy_array = FALSE;
      for (i = 0; i < numfds; i++) {
        if (fds[i].fd == -1){
          for(j = i; j < numfds; j++){
            fds[j].fd = fds[j+1].fd;
          }
          numfds--;
        }
      }
    }

  } while (end_server == FALSE); // End of serving running.

  // Clean up open sockets
  for (i = 0; i < numfds; i++) {
    if(fds[i].fd >= 0)
      close(fds[i].fd);
  }
}

