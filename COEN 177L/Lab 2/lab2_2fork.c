//Name: Gagan Gupta 
//Date: 01/16/20
//Title: Lab2 - Programming in C and use of Systems Calls
//Description: Simple fork program that only has one parent and one child

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {  //check to see if fork worked properly
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    //alternates the parent and the child process due to virtual CPUs multiplexing
    if (pid){
        // Parent process
        for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i);
            usleep(n);
        }
    }
    else{
        // Child process
        for (i=0;i<100;i++) {
            printf("Child process %d\n",i);
            usleep(n);
        }
    }
    return 0;
}
