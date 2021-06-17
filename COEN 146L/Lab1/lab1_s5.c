//Name: Gagan Gupta 
//Date: 09/24/20
//Title: COEN 146L : Lab 1 step 5
//Description: Sample C program showing the usage of 2 Threads

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
#include <pthread.h>	/* pthread */

#define NTHREADS 2

void *go(void *);
pthread_t threads[NTHREADS];

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, &n);
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
	    printf("Thread %d returned \n", i);
    }
    printf("Main thread done.\n");
    return 0;
}

void *go(void *arg) {
    usleep(*(int *)arg);
    return (NULL);
}
