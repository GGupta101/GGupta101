//Name: Gagan Gupta
//Date: 3/5/2020
//Title: Lab 9 - File Performance Measurement 
//Description: Step 3 - Testing the speed of sequential reads and writes for files of varying size

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	//Loop through the file till EOF then copy that file into a new output.txt file
	FILE *infile = fopen(argv[1], "rb");
	char buff[atoi(argv[2])];
	FILE *outfile = fopen("output.txt", "wb");
	
	while (fread(buff, atoi(argv[2]), 1, infile)){
		fwrite(buff, atoi(argv[2]), 1, outfile);	
	};
	fclose(infile);
	fclose(outfile);
	return 0;
}
