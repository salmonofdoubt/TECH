  
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
  
int main() { 
	pid_t pid; 
	char *message; 
	int n; printf("fork program startingn"); 
	pid = fork(); 

	switch(pid){ 
		case -1: 
			exit(1); 
		case 0: 
			message = "this is the child process"; 
			n = 3; 
		break; 
		default: 
			message = "this is the parent process"; 
			n = 6; 
		break; 
	} 
  
	for(; n > 0; n--) { 
		puts(message); 
		sleep(1); 
	} 

exit(0); 
}