//Name: Gagan Gupta 
//Date: 01/16/20
//Title: Lab2 - Programming in C and use of Systems Calls
//Description: Fork program to create 7 processes where processes may have two children, or no children at all.

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
void forkRecurrsive(int level,int n);
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    forkRecurrsive(6,n); // makes 6+1=7 processes where each has 0 or 2 children
    return 0;
}

void forkRecurrsive(int level,int n){  //recurrsive fuction to fit the precondition and alternates the fork funtion between child and parent to make sure every process has either 0 or 2 children. Takes in a level and a delay
    int i,j;
    int pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    if (pid==0){
	// Child process
        for (i=0;i<1;i++) {
	    for(j=0;j<level;j++)printf("\t");
            printf("Child process %d\n",getpid());
            usleep(n);
        }
	if(level>1 & level%2==1)forkRecurrsive(level-1,n);  //alternating recurrsive call
    }
    else{
        // Parent process
        for (i=0;i<1;i++) {
	  for(j=0;j<level;j++)printf("\t");
	  printf("Parent Process %d \n",getpid());
	    usleep(n);
        }
	wait(NULL);  //waits for the child process to end before ending itself
	if(level>1 & level%2==0)forkRecurrsive(level-1,n);  //alternation recurrsive call
    }
}
