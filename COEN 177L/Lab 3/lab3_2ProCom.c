/**************************
*   Lab3 - pipe()
**************************/

//Name: Gagan Gupta 
//Date: 01/23/20
//Title: Lab3 - Pthreads and the inter-process Communication - Pipes
//Description: Pipe function to read in the inputs given on cmd line
//	       and passes them to the other side of the pipe to be 
//             places in a buffer

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       close(fds[0]);
       char str[100]="Hello I am the Producer";
       write(fds[1],(const void*)str,(size_t)strlen(str));
       exit(0);
   }
   else if(fork()==0){
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0){
	 //printf("Reading from downstream: \n");
           for(i=0;i<count;i++){
               write(1,buff+i,1);
           }
           printf("\nResponding:\nHello Producer, I am Consumer \n");
       }
       exit(0);
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
