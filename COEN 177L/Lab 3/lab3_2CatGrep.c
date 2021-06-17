/**************************
*	pipe() for cat /etc/passwd | grep root
**************************/

//Name: Gagan Gupta 
//Date: 01/23/20
//Title: Lab3 - Pthreads and the inter-process Communication - Pipes
//Description: Pipe Implementation for cat /etc/passwd | grep root

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 
//main
int main() {
 	int fds[2];
 	pipe(fds);
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
	        //Close the downstream and open the upsteam to run the cat shell function with the /etc/passwd arguement
	        close(fds[0]);
		dup2(fds[1], 1);
		execlp("cat", "cat","/etc/passwd", 0);
		exit(0);
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
	        //Close the upstream and open the downstream to run the grep root (searchs for the word root) from what the upstream output
	        close(fds[1]);
		dup2(fds[0], 0);
		execlp("grep", "grep","root" , 0); 
		exit(0);
	}
	else {  /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0);
	}
	return 0;
} 
