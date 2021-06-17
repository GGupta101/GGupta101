//Name: Gagan Gupta 
//Date: 02/27/20
//Title: Lab8 - Memory Management  
//Description: First in First Out for Memory Management (FIFO)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{     
	int pageno;
}ref_page;

int main(int argc, char *argv[]) {
	int C_SIZE=atoi(argv[1]);
	ref_page cache[C_SIZE]; 
	char pageCache[100]; 
	int totalFaults=0; 
	int page_num;
	int totalRequests=0;
	int cachePos=0;
	int i;	
	for(i=0;i<C_SIZE;i++){
		cache[i].pageno=-1;
	}

	while(fgets(pageCache, 100, stdin)){
		page_num = atoi(pageCache);
		totalRequests++;
		for(i = 0; i < C_SIZE; i++) {
		     //If found then break out of the for
		     if (cache[i].pageno == page_num) {
		          break;
		     }
		     if(i==C_SIZE-1) {
		          printf("Page %d caused a fault\n", page_num);
			  totalFaults++;
			  cache[cachePos].pageno=page_num;
			  cachePos++;
			  if(cachePos==C_SIZE)cachePos=0;
		     }
		}
	}

	printf("%d Total Page Faults with %d Total Page Requests\n", totalFaults, totalRequests);
	printf("FIFO Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
	return 0;
}

