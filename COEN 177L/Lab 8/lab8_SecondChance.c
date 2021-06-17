//Name: Gagan Gupta 
//Date: 02/27/20
//Title: Lab8 - Memory Management  
//Description: Second Chance for Memory Management

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
	char charCache[1000];
	int totalFaults=0; 
	int page_num;
	int totalRequests=0;
	int i, j, k;
	int m=0;
	int notFound;
	for(i=0;i<C_SIZE;i++){
		cache[i].pageno=-1;
		cache[i].age=0;
	}
	
	while(fgets(charCache, 100, stdin)){
		page_num = atoi(charCache);
		totalRequests++;
		for(i=0;i<C_SIZE;i++) {
		     if (cache[i].pageno == page_num) {
			  cache[i].age=1;
			  notFound=0;
		          break;
		     }
		     if(i==C_SIZE-1) {
		          notFound=1;
		     }
		}
		if(notFound){
		     printf("Page %d caused a fault\n", page_num);
		     totalFaults++;
		     for(k=m;k<C_SIZE;k++){
		          if(cache[k].age==1){
			       cache[k].age=0;
			       m++;
			       if(m==C_SIZE){
			            m=0;
				    k=-1;
			       }
			  }
			  else{
			       cache[k].pageno=page_num;
			       cache[k].age=0;
			       m++;
			       if(m==C_SIZE){
				    m=0;
			       }
			       break;
			  }
		     }
		}
	}

	printf("%d Total Page Faults with %d Total Page Requests\n", totalFaults, totalRequests);
	printf("Second Chance Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
	return 0;
}

