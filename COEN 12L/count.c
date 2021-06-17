//Gagan Gupta
//9/17/18
//COEN 12L

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argu[]){
    FILE *f;
    char words[30];
    int count = 0;
    //Initilizes the file, the word holder (Max length of a word is 30 chars), and the word counter
    f = fopen(argu[1], "r");
    //Opens file based on the path given
    
    if(f==NULL){
        printf("Error with File");
        return 0;
    }
    //Cuts out of program if file isnt vaild
    
    while( fscanf(f,"%s", words) != EOF){
        count++;
    }
    //fscanf scans for word strings(%s) and ticks the count up one when it finds one. Then it stops when it reaches the end of the file (EOF)
    
    fclose(f);
    //Closes File
    
    printf("%d %s",count," words\n");
    //Prints Count
    return count;
    //Returns Count
}
