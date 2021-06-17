//Name: Gagan Gupta
//Date: 3/5/2020
//Title: Lab 9 - File Performance Measurement 
//Description: Step 1 - Testing read file with fixed buffer size 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFERSIZE 10000

int main(int argc, char *argv[]){
	//Loop through the file till EOF with the fixed buffer size of 10000
	char *buff[BUFFERSIZE];	
	FILE *fp=fopen(argv[1],"rb");
	while(fgets(buff, BUFFERSIZE, fp)){};
	fclose(fp);
	return 0;
}
