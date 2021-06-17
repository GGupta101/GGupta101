/*
Gagan Gupta
COEN 20L
Lab 4c Functions
10/22/19
*/		
		.syntax     unified
		.cpu        cortex-m4
        .text
		
		.global		MxPlusB
        .thumb_func
        .align
		
		
		// int32_t MxPlusB(int32_t x, int32_t mtop, int32_t mbtm, int32_t b);
		// Equation: y = mx + b, where m = mtop / mbtm.	
MxPlusB:
		PUSH	{R4,R5}				//Push registers to use as temps in the operations
		
		MUL		R1,R0,R1			//temp=dvnd*x
		MUL		R4,R1,R2			//temp*dvsr
		ASR		R4,R4,31			//(temp*dvsr)>>31
		MUL		R4,R4,R2			//((temp*dvsr)>>31)*dvsr
		LSL		R4,R4,1				//(((temp*dvsr)>>31)*dvsr)<<1
		ADD		R4,R4,R2			//((((temp*dvsr)>>31)*dvsr)<<1)+dvsr
		LDR		R5,=2				//Set a register to the constant 2 to use for the SDIV
		SDIV	R4,R4,R5			//(((((temp*dvsr)>>31)*dvsr)<<1)+dvsr)/2 = final rounding number
		ADD		R5,R4,R1			//((dvnd*x)+rounding)
		SDIV	R5,R5,R2			//((dvnd*x)+rounding)/dsvr = m*x in the y=mx+b
		
		ADD		R5,R5,R3			//Add the m*x above to the b given
		MOV		R0,R5				//Move the calculated value to the R0 register
		POP		{R4,R5}				//Pop the pushed registers
		BX		LR
		.end