/**************************
*   Lab3 - pipe() for ls to buffer to read from buffer
**************************/

//Name: Gagan Gupta 
//Date: 01/23/20
//Title: Lab3 - Pthreads and the inter-process Communication - Pipes
//Description: Pipe function where the output from ls is fed into a buffer

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   //Setup the pipe, buffer for the pipes to use, and the nessary variables
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       //This is the Upstream which pushs the output from the shell function ls to the buffer for the downstream to print
       dup2(fds[1], 1);
       close(fds[0]);
       execlp("ls", "ls", 0);
       exit(0);
   }
   else if(fork()==0){
       //This is the Downstream that reads each arguement from the buffer and places a space between each char and a newline between each arguement
       //In this case the arguments are the filenames from ls
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
               write(1," ",1);
           }
           printf("\n");
       }
	   
       exit(0);
    }
   else{     
      // Parent waits for the children to finish before exiting automatically at the end of main
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
