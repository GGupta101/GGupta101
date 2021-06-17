/*
*Gagan Gupta
*COEN 12L M 5pm
*11/5/18
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include "set.h"

typedef struct set{
    int c; //count of current data in the SET
    int len; //max length the SET can have
    void **data; //double pointer that works like a 2D array that holds words
	int *flags; //0=empty, 1=full, 2=deleted
    int (*compare)();
    unsigned (*hash)();
} SET;

SET *createSet(int maxElts,int (*compare)(), unsigned (*hash)()){ //O(n)
    SET *sp = malloc(sizeof(SET)); //allocates memory for the SET
    sp->c=0; //current count is 0
    sp->len=maxElts; //len has its value set
    sp->data = malloc(sizeof(void*)*maxElts); //allocates the memory for the element list that is the max size of a void multiplied by maxElts
    sp->flags = malloc(sizeof(int)*maxElts);  //allocates memory for the flags list that indicates the status of a position (0=empty, 1=full, 2=removed)
    for(int i=0;i<maxElts;i++){ //sets all the flags to 0 which is empty
        sp->flags[i]=0;
    }
    sp->compare=compare; //sets sp->compare to the compare function that is given
    sp->hash=hash; //sets sp->hash to the hash function that is given
    return sp; //returns a pointer to the SET
}

int search(SET *sp, char *elt){ //O(n)
    int pos=((*sp->hash)(elt))%sp->len; //hash mod the length to find starting positon for the search
    int del=-1; //variable to store the first deleted
    int temp;
    for(int i=0;i<sp->len;i++){
        temp = pos+i % (sp->len);
        if(sp->flags[temp]==0){
            if(del==-1){
                return temp; //if element empty and there were no deleted positon before, it returns the current empty spot
            }
            else{
                return del; //else it returns the first deleted spot
            }
        }
        else if(sp->flags[temp]==1){
            if(((*sp->compare)(sp->data[temp],elt))==0){
                return temp; //if element is full and the same as elt, it returns the current position
            }
        }
        else if(sp->flags[temp]==2){
            if(del==-1){
                del=temp; //sets del to first deleted position found
            }
        }
    }
    return -1;
}

void destroySet(SET *sp){ //O(1)
    free(sp->data); //frees data
	free(sp->flags); //frees flags
    free(sp); //frees c and len along with the whole SET
}

int numElements(SET *sp){
    return (sp->c); //returns current element count in the SET
}

void addElement(SET *sp, void *elt){ //O(n)
	int pos=search(sp,elt);
    if(sp->flags[pos]!=1){
        sp->data[pos]=elt; //shifts pointer to elt
        sp->flags[pos]=1; // sets flag at that position to full=1
        sp->c=sp->c+1; //increments count by 1
	}
	return;
}

void removeElement(SET *sp, void *elt){ //O(n)
	int pos=search(sp,elt);
	if(sp->flags[pos]==1){
        sp->data[pos]=NULL; //sets element pos to null
        sp->flags[pos]=2; //sets flag at that position to deleted=2
        sp->c=sp->c-1; //decrements count by 1
	}
	return;
}

void *findElement (SET * sp, void *elt){ //O(n)
	int pos=search(sp,elt);
	if(sp->flags[pos]==1){
		return sp->data[pos]; //returns sp->data[pos] if found
	}
	return NULL; //else returns NULL is not
}

void swap(void **a,int i,int j){ //O(1)
    void *t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int partition(SET *sp,void **a,int l,int h){ //O(n)
    void *piv=a[h]; //pivot is last element (with sorted data this becomes a problem)
    int i=(l-1);
    for(int j=l;j<=h-1;j++){
        if(((*sp->compare)(a[j],piv))<=0){
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,h); //swaps pivot with first element of larger implict array
    return (i+1);
}

void quickSort(SET *sp,void **a,int l,int h){ //O(n)*//O(log(n))=O(nlog(n))
    //patition runs in n time and quicksort runs recursively log(n) times
    if(l<h){ //goes until implicit size of the array is 1
        int pi=partition(sp,a,l,h);
        quickSort(sp,a,l,pi-1); //recursively calls quickSort for the new two halfs
        quickSort(sp,a,pi+1,h);
    }
}

void *getElements(SET *sp){ //O(n+nlog(n))
    void **copy = malloc(sizeof(void*)*sp->c); //creates copy of the size of sp->c time the size of a char pointer
    int pos=0;
    for(int i=0;i<sp->len;i++){ //copies over full elements only
        if(sp->flags[i]==1){
            copy[pos]=sp->data[i];
            pos++;
        }
    }
    quickSort(sp,copy,0,pos-1); //sorts the full new copy in O(nlog(n)) time
    return copy; //returns the copy of sp->data elements in a more condensed void double pointer
}

