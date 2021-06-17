/*
*Gagan Gupta
*COEN 12L M 5pm
*10/8/18
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "set.h"
# include <assert.h>

typedef struct set{
    int c; //count of current data in the SET
    int len; //max length the SET can have
    char **data; //double pointer that works like a 2D array that holds words
	int *flags; //0=empty, 1=full, 2=deleted
} SET;

SET *createSet(int maxElts){
    SET *sp = malloc(sizeof(SET)); //allocates memory for the SET
    sp->c=0; //current count is 0
    sp->len=maxElts; //len has its value set
    sp->data = malloc(sizeof(char*)*maxElts); //allocates the memory for the element list that is the max size of a char multiplied by maxElts
	sp->flags = malloc(sizeof(int)*maxElts);
	for(int i=0;i<maxElts;i++){
		sp->flags[i]=0;
	}
    return sp; //returns a pointer to the SET
}

unsigned strhash(char *s) {
	unsigned hash = 0;
	while (*s != '\0'){
		hash = 31 * hash + *s ++;
	}
	return hash;
}

int search(SET *sp, char *elt){
	int pos=strhash(elt)%sp->len;
	int temp=pos++;
	while(temp!=pos){
		if(sp->data[temp]==NULL || elt==NULL)return -1;
		if(sp->flags[temp]==1 && strcmp(sp->data[temp],elt)==0)return temp;
		if(sp->flags[temp]==0 || sp->flags[temp]==2)return temp;
		temp = ((temp+1) % (sp->len));
	}
	return -1;
}

void destroySet(SET *sp){
    for (int i = 0; i < (sp->len); i++) {
        free(sp->data[i]); //frees all the data individually
    }
    free(sp->data); //frees data
	free(sp->flags); //frees flags
    free(sp); //frees c and len along with the whole SET
}

int numElements(SET *sp){
    return (sp->c); //returns current element count in the SET
}

void addElement(SET *sp, char *elt){
	assert(elt!=NULL);
	int pos=search(sp,elt);
	int temp=pos;
	assert(sp->flags[temp]!=1);
	assert(temp!=-1);
	if(sp->flags[temp]==2){
		sp->data[temp]=malloc(sizeof(char));
		sp->data[temp]=elt;
		sp->flags[temp]=1;
		sp->c=sp->c+1;
	}
	if(sp->flags[temp]==0){
		sp->data[temp]=elt;
		sp->flags[temp]=1;
		sp->c=sp->c+1;
	}
	return;
}

void removeElement(SET *sp, char *elt){
	assert(elt!=NULL);
	int pos=search(sp,elt);
	assert(pos!=-1);
	if(sp->flags[pos]==1){
		free(sp->data[pos]);
		sp->flags[pos]=2;
		sp->c=sp->c-1;
		return;
	}
	return;
}

char *findElement (SET * sp, char *elt){
	assert(elt!=NULL);
	int pos=search(sp,elt);
	assert(pos!=-1);
	if(sp->flags[pos]==1){
		return elt;
	}
	return NULL;
}

char **getElements(SET *sp){
    char **copy = malloc(sizeof(char*)*sp->len); //creates copy of the size of sp->data
    memcpy(copy, sp->data, sizeof(char*)*sp->c); //copies sp->data into copy
    return copy; //returns the copy of sp->data
}
