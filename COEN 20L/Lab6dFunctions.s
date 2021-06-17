/*
Gagan Gupta
COEN 20L
Lab 6d Function
11/12/19
*/	
		.syntax		unified
		.cpu		cortex-m4
		.text		
		.global		GetNibble
		.thumb_func
		//                          R0                R1
		// uint32_t GetNibble(void *nibbles, uint32_t which);
GetNibble:
		LSRS	R2,R1,1			//Store which/2 in R2
		LDRB	R2,[R0, R2]		//Store (which/2)+address of nibbles
		
		AND     R1,R1,1			//R1=which&1
		CMP		R1,1			//Compare with IT block that uses UBFX commands to get the even or odd nibble and store it in the return register
		ITE		EQ
		UBFXEQ	R0,R2,4,4
		UBFXNE	R0,R2,0,4
		BX		LR		
	
		.global		PutNibble
		.thumb_func
		//                          R0                R1		  R2
		// void PutNibble(void *nibbles, uint32_t which, uint32_t value);
PutNibble:
		PUSH	{R4}			//Push extra register to store which/2
		LSRS	R4,R1,1			
		LDRB	R3,[R0, R4]		//Store (which/2)+address of nibbles
		
		AND     R1,R1,1			//R1=which&1
		CMP		R1,1			//Compare with IT block that uses BFI commands to change the bitfield of the byte of data in R3
		ITE		EQ
		BFIEQ	R3,R2,4,4
		BFINE	R3,R2,0,4
		
		STRB	R3,[R0, R4]		//Store newly changed byte of data in R3 in the correct position
		POP		{R4}
		BX		LR
		.end