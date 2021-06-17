//Name: Gagan Gupta 
//Date: 10/06/20
//Title: COEN 171 - HW 1
//Description: Quicksort in C, Translated from Pascal

#include <stdio.h>
#include <stdlib.h>
#define high 8
typedef int numbers[high];
numbers a;

//Read values into the numbers array a
void readarray(){
	int i;
	for(i=0;i<high;i++){
		scanf("%d",&a[i]);
	}
}

//Print the elements of the numbers array a
void writearray(){
	int i;
	for(i=0;i<high;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

//Call by Reference Swap function
void exchange(int* a, int* b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

//Partition used in Quicksort
int partition(numbers a, int y, int z){
	int i,j,x;
	x=a[y];
	i=y-1;
	j=z+1;
	
	while(i < j){
		do
			j=j-1;
		while(a[j] > x);
		do
			i=i+1;
		while(a[i] < x);
		if(i < j){
			exchange(&a[i], &a[j]);
		}
	}
	
	return j;
}

//Main Recurrsive Quicksort function
void quicksort(numbers a, int m, int n){
	int i;
	if(n > m){
		i = partition(a, m, n);
		printf("%d\n",i);
		writearray();
		quicksort(a, m, i);
		quicksort(a, i + 1, n);
	}
}

int main(){
	//Populate array a with values
    readarray();
	//Sort array a
    quicksort(a,0,high-1);
	//Print out the sorted array a
    writearray();
    return 0;
}
