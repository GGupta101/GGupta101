/**************************
*	pipe() for ls | more
**************************/

//Name: Gagan Gupta 
//Date: 01/23/20
//Title: Lab3 - Pthreads and the inter-process Communication - Pipes
//Description: Simple Pipe implementation using ls for the downstream child and more for the upstream child

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 
//main
int main() {
        //Setup the pipe
 	int fds[2];
 	pipe(fds);
	//The children together run the "ls | more" shell function
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
                //Open the upstream pipe and close the downstream pipe
	        dup2(fds[0], 0);                        
		close(fds[1]);
		execlp("more", "more", 0); 
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
	        //Open the downstream pipe and close the upstream pipe
	        dup2(fds[1], 1);                       
		close(fds[0]);
		execlp("ls", "ls", 0); 
	}
	else {  /*parent closes both ends and wait for children*/
	        //Close the pipe entirely 
	        close(fds[0]);
		close(fds[1]);
		//Parent waits for the children to finish before exiting automatically at the end of main
		wait(0);
		wait(0); 
	}
} 
