//Name: Gagan Gupta 
//Date: 10/01/20
//Title: COEN 146L Lab 2 - Part 1
//Description: Matrix multiplication for 1024x1024 2D arrays where there is one thread per row

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define N 1024   //Row value of Matrix A and Matrix C
#define M 1024   //Row value of Matrix B and Column value of Matrix A
#define L 1024   //Column value of Matrix B and Matrix C

//Define all three matrices using values above
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

//Thread array with the length of the number of rows in C
pthread_t threads[N];

int main() {
    int i,j;
    
    //Create Psuedo Random values for A and B
    srand(time(NULL));
    for (i = 0; i < N; i++)     
      for (j = 0; j < M; j++)
		matrixA[i][j] = rand();

    srand(time(NULL));
    for (i = 0; i < M; i++)     
      for (j = 0; j < L; j++)
		matrixB[i][j] = rand();

    for (i = 0; i < N; i++){  
      //Start the lock and create a thread (we will make N in total)
        pthread_create(&threads[i], NULL, go, (void*)(size_t)i);
    }

    for (i = 0; i < N; i++) {
      //Join the threads
        pthread_join(threads[i],NULL);
    }
	
	// for (i = 0; i < N; i++){   
		// printf("\n");
      // for (j = 0; j < L; j++)
		// printf("%e",matrixC[i][j]);
	// }
    //When we are done join all the threads back together, we only have the main thread left
    printf("Main thread done.\n");

    return 0;
}
//This is the start routine for the pthread_create
void *go(void *arg) {
  int j,k;
  int i=(int)(size_t)arg;
  double temp;
  //Each thread handles row i for matrix C computations
  for (j = 0; j < L; j++){     
    temp = 0;     
    for (k = 0; k < M; k++){         
      temp += matrixA[i][k] * matrixB[k][j];           
    }
    matrixC[i][j] = temp;       
  }
  return 0;
}


