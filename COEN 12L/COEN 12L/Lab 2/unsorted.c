/*
*Gagan Gupta
*COEN 12L M 5pm
*10/5/18
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "set.h"

typedef struct set{
    int c; //count of current elements in the SET
    int len; //max length the SET can have
    char **elements; //double pointer that works like a 2D array that holds words
} SET;

SET *createSet(int maxElts){
    SET *sp = malloc(sizeof(SET)); //allocates memory for the SET
    sp->c=0; //current count is 0
    sp->len=maxElts; //len has its value set
    sp->elements = malloc(sizeof(char*)*maxElts); //allocates the memory for the element list that is the max size of a char multiplied by maxElts
    return sp; //returns a pointer to the SET
}

int search(SET *sp,char *el,int *found){ //Linear search with O(n)
    for (int i = 0; i < sp->c; i++) {
        if(sp->elements[i]!=NULL){
            if(strcmp(elt,sp->elements[i])==0){
                return i;
            }
        }
    }
    return -1;
}

void destroySet(SET *sp){
    for (int i = 0; i < (sp->c); i++) {
        free(sp->elements[i]); //frees all the elements individually
    }
    free(sp->elements); //frees elements
    free(sp); //frees c and len along with the whole SET
}

int numElements(SET *sp){
    return (sp->c); //returns current element count in the SET
}

void addElement(SET *sp, char *elt){
    char *tempchar=strdup(elt);
    if(search(sp,tempchar,&found)!=-1) return; //if elt is in the SET it breaks out else it continues
    if(sp->c>=sp->len) return; //checks to see if SET is at maxElts
    sp->elements[sp->c]=tempchar; //adds new elt to the end of the SET
    sp->c++; //increments SET count by 1
}

void removeElement(SET *sp, char *elt){
	if(search(sp,elt,&found)>-1){ //if elt is isn't the SET it breaks out else it continues
		sp->elements[search(sp,elt,&found)]=sp->elements[(sp->c-1)]; //sets last element over the removed element
		sp->elements[(sp->c-1)]=NULL; //sets the last element to NULL
		sp->c=(sp->c-1); //decrements SET count by 1
	}
}

char *findElement(SET *sp, char *elt){
    char *tempchar=strdup(elt);
	if(search(sp,tempchar,&found)>-1){ //if elt is found it returns elt else it returns NULL
		return tempchar;
	}
	return NULL;
}

char **getElements(SET *sp){
    char **copy = malloc(sizeof(char*)*sp->len); //creates copy of the size of sp->elements
    memcpy(copy, sp->elements, sizeof(char*)*sp->c); //copies sp->elements into copy
    return copy; //returns the copy of sp->elements
}
