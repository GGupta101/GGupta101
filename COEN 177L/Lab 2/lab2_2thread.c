//Name: Gagan Gupta 
//Date: 01/16/20
//Title: Lab2 - Programming in C and use of Systems Calls
//Description: Simple thread programs to create 2 threads

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
#include <pthread.h>

void *crt(void *);
#define NTHREADS 2           //number of threads to create in the main
pthread_t threads[NTHREADS];
int main() {
    int i;
    for (i = 0; i < NTHREADS; i++){  
      printf("Creating Thread %d\n",i);      
      pthread_create(&threads[i], NULL, crt, NULL);  //create the thread while runningthe start routine
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);  //Join all the threads to return to the 1 original thread
	printf("\tThread returned with %d \n",  i);
    }
    printf("---Main thread done.---\n");
    return 0;
}

void *crt(void *arg) {  //Start routine to use with the pthread_create (don't use any inputs in the function
    printf("  Hello from the thread\n");
    return 0;
}
