// Thread Sychronization

//Name: Gagan Gupta 
//Date: 02/06/20
//Title: Lab5 - Synchronization using semaphores 
//Description: Thread Hello 

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h>
#include <fcntl.h>

//Define the semaphore and the thread array
#define NTHREADS 10
pthread_t threads[NTHREADS];
sem_t *mutex; 

//Start routine for threads
void* go(void* arg) { 
  //Implement the wait function from the "wait and signal" of a semaphore
  sem_wait(mutex); //entry section
  printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
  sleep(1); 
  sem_post(mutex); //exit section 
  return (NULL);
} 

int main() { 
  //Unlink any semaphores from previous code
  sem_unlink("mutex"); 
  //Open the mutex semphore with the sem_open function
  mutex = sem_open("mutex", O_CREAT, 0644, 1);
  static int i;
  //Create 10 threads with pthread_create and use a seperate wait and signal in each start routine with the semaphore
  for (i = 0; i < NTHREADS; i++)  
    pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
  //Join the threads back to the main thread
  for (i = 0; i < NTHREADS; i++) {
    pthread_join(threads[i],NULL);
    printf("\t\t\tThread %d returned \n", i);
  }
  printf("Main thread done.\n");
  
  //Unlink the semaphore when done with the  usage of it
  sem_unlink("mutex"); 
  return 0; 
} 
