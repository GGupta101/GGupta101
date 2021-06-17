/*
Gagan Gupta
COEN 20L
Lab 2a Functions
10/08/19
*/		
		.syntax     unified
		.cpu        cortex-m4
        .text
		
		.global		Add
		.global		Less1
		.global		Square2x
		.global		Last
		
        .thumb_func
        .align
		
Add:	
		PUSH		{LR}		//Push LR onto the stack before calling the function (So we can return to the right branch later on)
		ADD			R0,R0,R1	//Stoe the value R1+R0 to the R0 Register
		POP			{PC}		//Pop PC which will return the code to the outer branch

Less1:	
		PUSH		{LR}		//Push LR onto the stack before calling the function (So we can return to the right branch later on)
		LDR			R1,=1		//Store the constant 1 to the R0 Register
		SUB			R0,R0,R1	//Store the value R0-1 to the R0 Register
		POP			{PC}		//Pop PC to return the code to the outer branch

Square2x:
		ADD			R0,R0,R0	//Store the value 2*R0 to the R0 Register
		B	 		Square		//Store the value R0*R0 to the R0 Register

Last:
		PUSH		{R4,LR}		//Push R4 and LR onto the stack before calling the function (So we can return to the right branch later on)
		MOV			R4,R0		//Copy the current R0 value to the R4 Register for us to be able to use it later in the function
		BL 			SquareRoot	//Store the value of sqrt(R0) to the R0 Register
		ADD			R0,R0,R4	//Store the value of R1+R0 to the R0 Register
		POP			{R4,PC}		//Pop PC to return the code to the outer branch. Pop R4 to free the Register from the stack
		.end
