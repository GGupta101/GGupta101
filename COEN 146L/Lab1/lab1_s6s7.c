//Name: Gagan Gupta 
//Date: 09/24/20
//Title: COEN 146L : Lab 1 steps 6 and 7
//Description: Calculates varous probabilites for Circuit Switching and Packet Switching Scenarios     

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

double factorial(double n){
	if(n<=1) return 1;
	else return (n*factorial(n-1));
}

int main(int argc, char *argv[]){
	int linkBandwidth=atoi(argv[1]);
	int userBandwidth=atoi(argv[2]);
	double tPSusers=atof(argv[3]);
	int nPSusers=atoi(argv[4]);
	
	double pPSusersBusy, pPSusersNotBusy;
	
	int nCSusers=linkBandwidth/userBandwidth;
	printf("CS Scenario: %d users\n",nCSusers);
	
	printf("PS Scenario: \n");
	double pPSusers=tPSusers;
	printf("The probability that a given (specific) user is busy transmitting: %f\n",pPSusers);
	
	pPSusersNotBusy=1-pPSusers;
	printf("The probability that one specific other user is not busy: %f\n",pPSusersNotBusy);
	
	double pAllNB=pow(1-pPSusers,nPSusers-1);
	printf("The probability that all of the other specific other users are not busy: %f\n",pAllNB);
	
	double p1B=pPSusers*pow(pPSusersNotBusy,nPSusers-1);
	printf("The probability that one specific user is transmitting and the remaining users are not transmitting: %f\n",p1B);
	
	double pExact1B=nPSusers*pPSusers*pow(pPSusersNotBusy,nPSusers-1);
	printf("The probability that exactly one (any one) of the nPSusers users is busy: %f\n",pExact1B);
	
	double p10B=pow(pPSusers,10)*pow(pPSusersNotBusy, nPSusers-10);
	printf("The probability that 10 specific users of nPSusers are transmitting and the others are idle: %e\n",p10B);
	
	double pAny10B=((factorial(nPSusers))/((factorial(10))*(factorial(nPSusers-10))))*
					pow(pPSusers,10)*pow(pPSusersNotBusy,nPSusers-10);
	printf("The probability that any 10 users of nPSusers are transmitting and the others are idle: %e\n",pAny10B);
	
	double p10plusB=0.0;
	int i;
	for(i=11;i<=nPSusers;i++){
		p10plusB+=(factorial(nPSusers)/(factorial(i)*
					factorial(nPSusers-1)))*pow(pPSusers,i)*pow(pPSusersNotBusy,pPSusers-1);
	}
	printf("The probability that more than 10 users of nPSusers are transmitting and the others are idle: %e\n",p10plusB);
	
	return 0;
}
	
