//Name: Gagan Gupta 
//Date: 02/06/20
//Title: Lab5 - Synchronization using semaphores 
//Description: Thread Synchornization for the producer and consumer problem

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <time.h>
#include <fcntl.h>

#define bSize 10
#define NTHREADPAIRS 10

//Define Producers and Consumers array
pthread_t tP[NTHREADPAIRS], tC[NTHREADPAIRS];
//Define the buffer which is the bridge between the producers and consumers
int buff[bSize];
//3 semaphore for interation between producer and consumer
sem_t *mutex, *full, *empty; 
int in, out, i, j;

void* producer(void* arg) {
  //Create a rand int from 0 to 99 and push onto the buffer for the corresponding consumer to read 
  int obj;
  obj=(rand()%100);
  sem_wait(empty);
  sem_wait(mutex);
  buff[in]=obj;
  printf("Producer %d produced int %d at index %d\n",(int)(size_t)arg,obj,in);
  sleep(1);
  in=(in+1)%bSize;
  sem_post(mutex);
  sem_post(full);
  return NULL;
} 

void* consumer(void* arg) {
  //Read the data from the buffer from the corresponding producer
  int obj;
  sem_wait(full);
  sem_wait(mutex);
  srand(time(0));
  obj=buff[out];
  printf("\tConsumer %d consumed int %d at index %d\n",(int)(size_t)arg,obj,out);
  out=(out+1)%bSize;
  sleep(1);
  sem_post(mutex);
  sem_post(empty);
  return NULL;
} 

int main() { 
  //Unlink any semaphores from previous code
  sem_unlink("mutex"); 
  sem_unlink("full"); 
  sem_unlink("empty"); 
  //Open all the semaphores for use
  mutex = sem_open("mutex", O_CREAT, 0644, 1);
  empty = sem_open("empty", O_CREAT, 0644, bSize);
  full = sem_open("full", O_CREAT, 0644, 0);
  //Create producer thread(s)
  for(i=0;i<NTHREADPAIRS;i++){
    pthread_create(&tP[i], NULL, producer, (void *)(size_t)i);
  }
  //Create consumer thread(s)
  for(j=0;j<NTHREADPAIRS;j++){
    pthread_create(&tC[j], NULL, consumer, (void *)(size_t)j);
  }
  //Join all the threads
  for(i=0;i<NTHREADPAIRS;i++){
    pthread_join(tP[i],NULL);
  }
  for(j=0;j<NTHREADPAIRS;j++){
    pthread_join(tC[j],NULL);
  }
  printf("Producer and Consumer Threads returned \n");
  printf("Main thread done.\n");

  //Unlink all the semaphores
  sem_unlink("mutex"); 
  sem_unlink("full"); 
  sem_unlink("empty"); 

  return 0; 
} 
