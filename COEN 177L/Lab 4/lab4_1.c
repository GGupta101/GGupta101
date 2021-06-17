/**************************
*       COEN177: Threads  *
**************************/

//Name: Gagan Gupta 
//Date: 01/30/20
//Title: Lab4 - Developing multi-threaded applications
//Description: 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
// The threads are printing the same i multiple time because all the threads are using 
// the same memory at the same time. To make sure they access the memory location of i 
// at seperate times we have to implement a lock. This lock is of pthread_mutex_t type 
// and we have to initalize it in the beginning of the main. We start the lock in the 
// for loop before the pthread_create and end the lock at the end (before the return) 
// of the start routine. This is because the pthread_create calls the start routine 
// therefore also calling the print statement that was accessing the i data location. 
// After the lock was implemented only one thread could read/write to i at a time 
// therefore solving the given problem.
pthread_mutex_t mtx;
pthread_t threads[NTHREADS];
int main() {
    int i;
    //Initalize the lock
    pthread_mutex_init(&mtx,NULL);
    for (i = 0; i < NTHREADS; i++){  
      //Start the lock and create a thread (we will make 10 in total)
        pthread_mutex_lock(&mtx);
        pthread_create(&threads[i], NULL, go, &i);
    }
    for (i = 0; i < NTHREADS; i++) {
      //Join the thread and same it was returned
	printf("Thread %d returned\n", i);
        pthread_join(threads[i],NULL);
    }
    //When we are done join all the threads back together, we only have the main thread left
    printf("Main thread done.\n");
    return 0;
}
//This is the start routine for the pthread_create
void *go(void *arg) {
 printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), *(int *)arg);
 //End of the lock for the thread
pthread_mutex_unlock(&mtx);
 return 0;
}


