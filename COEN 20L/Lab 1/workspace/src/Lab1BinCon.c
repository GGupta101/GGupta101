/*
Gagan Gupta
09/26/19
Lab 1 Binary Conversion
*/


#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "library.h"
#include "graphics.h"

void Unsigned2Bits(uint32_t n, int8_t bits[8]){  // Opposite of Bits2Unsigned
	int q=n;				//set value of the unsugned to a variable so we can preform the mods and divison in the loop 
	for(int x=0;x<=7;x++){	//for loop to cycle through all the bits from pos 0 to pos 7
		bits[x]=(q%2);		//use modulus to find the remainder for q/2 and set that remainder (1 or 0) to position x in the bits array
		q=(q/2);			//divid by 2 when we move over a bit to find the accurate remainder (because q is an int, the division will auto-floor)
	}
}


void Increment(int8_t bits[8]){  // Add 1 to value represented by bit pattern
	for(int n=0;n<=7;n++){	//for loop to cycle through all the bits from pos 0 to pos 7
		if((bits[n]+1)==1){ //if the carry-in (1) added to the bit is 1 then we have added to a 0 position and therefore we are done and can break out of the loop
			bits[n]=1;
			break;
		}
		else bits[n]=0;		//if 1 + bit is 2 then we set it to 0 and check the next position
	}
}


uint32_t Bits2Unsigned(int8_t bits[8]){  // Convert array of bits to unsigned int
	uint32_t num=0;						//create a num to which we can add to and return
	for(int n=0, op=1;n<=7;n++,op*=2){	//for loop to cycle through all the bits from pos 0 to pos 7 and hold a 2^n value so we can preform polynomial expansion
		num += (op * bits[n]);			//increment the sum according to the bit position and value
	}
	return num;
}


int32_t Bits2Signed(int8_t bits[8]){  // Convert array of bits to signed int.
	return (int32_t) (Bits2Unsigned(bits)-2*((128)*bits[7]));	
	/*
	For calculating a 2's complement signed number we normal can take the negative polynomial evaluation of the most significant bit(if it is 1) and then add the rest of the corresponding 
	positive polynomial evaluation values to get the correct negative or positive 2's complement signed value. In this case however, if the most significant bit is 0, we can treat the 
	number as a unsigned number while calculating and therefore don't subtract anything. But if it is 1, then we have to subtract twice its amount because we added it one to the signed 
	number when we called the Bits2Unsigned function.
	*/
}
