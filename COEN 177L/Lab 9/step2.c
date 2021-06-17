//Name: Gagan Gupta
//Date: 3/5/2020
//Title: Lab 9 - File Performance Measurement 
//Description: Step 2 -  Testing read file with variable buffer size

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	//Loop through the file till EOF with the variable buffer size passed in through argv[2]
	FILE* fp = fopen(argv[1], "rb");
	int BUFFSIZE = atoi(argv[2]);
	char* buff=(char*)malloc(BUFFSIZE);
	while (fread(buff,1,BUFFSIZE,fp)>1){};
	fclose(fp);
	return 0;
}
