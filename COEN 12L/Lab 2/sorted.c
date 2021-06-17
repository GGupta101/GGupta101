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
# include <assert.h>

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

int search(SET *sp, char *elt, int *found){ //Binary search with a O(log(n))
    int lo=0;
    int hi=0;
    hi=sp->c-1;
    int mid=(lo+hi)/2; //sets mid to halfway point intitially
    if(sp->c==0){
        *found=0; //found is for indicating to add and remove methods whether to run or not- 0=add, 1=remove
        return 0;
    }
    while(lo<=hi){
        mid=(lo+hi)/2; //redefines mid based on newly set values
        assert(sp->elements[mid]!=NULL);
        assert(elt!=NULL);
        if(strcmp(sp->elements[mid],elt)==0){
            *found=1; //elt found and returns its position
            return mid;
        }
        else if(strcmp(sp->elements[mid],elt)<0){
            lo=mid+1;
        }
        else if(strcmp(sp->elements[mid],elt)>0){
            hi=mid-1;
        }
    }
    *found=0; //elt not found and returns position where elt should be added
    return lo;
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
    int found=0;
    int position=search(sp,elt,&found); //sets index to the returned location and sets found to corresponding value
    if(found==1)return; //element is already in the SET and it doesn't add
    if(sp->c==0){
        sp->elements[sp->c]=tempchar; //adds element is the SET is empty and increments c
        sp->c++;
        return;
    }
    for (int i = sp->c;i>position; i--){
        sp->elements[i]=sp->elements[i-1]; //shifts elements 1 higher while going from high to low
    }
    sp->elements[position]=tempchar; //adds the element in posisiton index and increments c
    sp->c++;
    return;
}

void removeElement(SET *sp, char *elt){
    char *tempchar = strdup (elt);
    int found;
    int position=search(sp,tempchar,&found); //sets index to the returned location and sets found to corresponding value
    if (found==0)return; //element isn't in the SET and can't remove anything
    for (int i=position;i<sp->c; i++){
        sp->elements[i]=sp->elements[i+1]; //shifts elements 1 lower while going from low to high, this also writes over sp->elements[position] therefore removing it
    }
    sp->elements[sp->c-1]=NULL; //set the old last element to NULL because everything was shifted over and decrements c
    sp->c--;
    return;
}

char *findElement (SET * sp, char *elt){
    int found;
    int index=search(sp,elt,&found);
    if (found==1){
        return sp->elements[index]; //returns the element in the SET
    }
    return NULL; //returns NULL if the element isn't in the SET
}

char **getElements(SET *sp){
    char **copy = malloc(sizeof(char*)*sp->len); //creates copy of the size of sp->elements
    memcpy(copy, sp->elements, sizeof(char*)*sp->c); //copies sp->elements into copy
    return copy; //returns the copy of sp->elements
}
