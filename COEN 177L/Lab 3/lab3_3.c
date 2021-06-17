/**************************
*       COEN177: Threads  *
**************************/

//Name: Gagan Gupta 
//Date: 01/23/20
//Title: Lab3 - Pthreads and the inter-process Communication - Pipes
//Description: Simple Thread code creating 10 threads and then joining them back to the main

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main() {
    int i;
    for (i = 0; i < NTHREADS; i++){  
        //Create a thread (we will have 10 in total) each will call the start routine
    }
    for (i = 0; i < NTHREADS; i++) {
        //Join all the 10 threads back together
	printf("Thread %d returned\n", i);
        pthread_join(threads[i],NULL);
    }
    //After everything is joined we are at the main thread again
    printf("Main thread done.\n");
    return 0;
}
//This is the start routine for the pthread_create
void *go(void *arg) {
 printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), *(int *)arg);
 return 0;
}


