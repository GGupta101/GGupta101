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
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) { //test to check is sucessfully  forked
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    else if(pid == 0) //ls if it is the child
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else //wait for the child to finish and print "Child Complete" and exit
    {
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
    return 0;
}
