//Name: Gagan Gupta 
//Date: 02/27/20
//Title: Lab8 - Memory Management  
//Description: LRU for Memory Management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{     
	int pageno;
	int age;
}ref_page;

int main(int argc, char *argv[]) {
	int C_SIZE=atoi(argv[1]);
	ref_page cache[C_SIZE]; 
	char pageCache[100]; 
	int totalFaults=0; 
	int page_num;
	int totalRequests=0;
	int cachePos=0;
	int i, j, k, m;
	int oldest;
	for(i=0;i<C_SIZE;i++){
		cache[i].pageno=-1;
		cache[i].age=100;
	}

	while(fgets(pageCache, 100, stdin)){
		page_num = atoi(pageCache);
		totalRequests++;
		oldest=cache[i].age;
		for(i=0;i<C_SIZE;i++) {
		     if (cache[i].pageno == page_num) {
		          for(k=0;k<C_SIZE;k++){
			      if(cache[k].age<cache[i].age) cache[k].age++;
			  }
			  cache[i].age=0;
		          break;
		     }
		     if(i==C_SIZE-1) {
		          printf("Page %d caused a fault\n", page_num);
			  totalFaults++;
		          for(j=0;j<C_SIZE;j++){
			      cache[j].age++;
			  }
			  for(m=0;m<C_SIZE;m++){
			       if(oldest<cache[m].age){
			            oldest=cache[m].age;
				    cachePos=m;
			       }
			  }
			  cache[cachePos].pageno=page_num;
			  cache[cachePos].age=0;
		     }
		}
	}

	printf("%d Total Page Faults with %d Total Page Requests\n", totalFaults, totalRequests);
	printf("LRU Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
	return 0;
}

