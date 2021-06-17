//Name: Gagan Gupta
//Date: 3/5/2020
//Title: Lab 9 - File Performance Measurement 
//Description: Step 4 - Multi-threaded file read and copy

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

char input_name[20];
int BUFFSIZE, NTHREADS;
 
void *go(void *arg) {
	//Each thread will copy a file and name that file outputX.txt where X is the thread number
	char output_name[20];
    char buffer[BUFFSIZE];
    sprintf(output_name, "output%d.txt", (int)arg);
    FILE *infile=fopen(input_name, "r");
    FILE *outfile=fopen(output_name, "w");
	
    while(fread(buffer, sizeof(char), 1, infile) > 0) {
        fwrite(buffer, sizeof(char), 1, outfile);
    };
    fclose(infile);
    fclose(outfile);
}

int main (int argc, char *argv[]){
	//Multi-threaded implementation for file read and copy
	//argv[1]=input file name, argv[2]=Buffer Size, argv[3]=Number of Threads
	strcpy(input_name, argv[1]);
    BUFFSIZE = atoi(argv[2]);
    NTHREADS = atoi(argv[3]);
    pthread_t threads[NTHREADS];

	int i;
    for(i=0;i<NTHREADS;i++){
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
	}
    for(i=0;i<NTHREADS;i++) {
        pthread_join(threads[i],NULL);
    }
    return 0;
}

