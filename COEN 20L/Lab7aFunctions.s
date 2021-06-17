/*
Gagan Gupta
COEN 20L
Lab 7a Functions
11/19/19
*/	
		.syntax		unified
		.cpu		cortex-m4
		.text
		
		.global		Zeller1
		.thumb_func
		
		//f=k+((13m-1)/5)+D+(D/4)-2C+(C/4)
		
		//                           R0          R1          R2          R3
		// uint32_t Zeller1(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
		// This function can use multiply and divide instructions.
Zeller1:
		PUSH	{R4}
		LDR		R4,=13			
		MUL		R4,R1,R4		//f=(13x-1)/5
		SUB		R4,R4,1			
		LDR		R1,=5
		UDIV	R4,R4,R1
		
		ADD		R4,R4,R0		//f=f+k+D+(D/4)+(C/4)-2C
		ADD		R4,R4,R2
		ADD		R4,R4,R2,LSR 2
		ADD		R4,R4,R3,LSR 2
		SUB		R4,R4,R3,LSL 1
		
		LDR		R1,=7
		SDIV	R2,R4,R1		//f/7
		MLS		R0,R2,R1,R4		//R0=f-7(f/7)
		LDR		R1,=0			//Check if less than 0
		CMP		R0,R1
		IT		LT
		ADDLT	R0,R0,7
		POP		{R4}
		BX LR
		
		.global		Zeller2
		.thumb_func
		//                           R0          R1          R2          R3
		// uint32_t Zeller2(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
		// This function CANNOT use divide instructions (SDIV or UDIV).
Zeller2:
		PUSH	{R4}
		LDR		R4,=13
		MUL		R4,R1,R4		//13*x
		SUB		R4,R4,1			//13x-1
		LDR		R1,=858993459	//(2^32)/5
		SMULL	R1,R4,R4,R1		//((2^32)/5)*(13x-1) and only taking most significant half aka the quotient
		
		ADD		R4,R4,R0		//+k
		ADD		R4,R4,R2		//+D
		ADD		R4,R4,R2,LSR 2	//+D/4
		ADD		R4,R4,R3,LSR 2	//+C/4
		SUB		R4,R4,R3,LSL 1	//-2C
		
		LDR		R1,=613566757	//(2^32)/7
		SMULL	R1,R2,R4,R1		//((2^32)/7)*f and only taking the most significant half aka the quotient
		LDR		R1,=7			
		MLS		R0,R2,R1,R4		//R0=f-(((2^32)/7)*f)
		LDR		R1,=0			//Check if less than 0
		CMP		R0,R1
		IT		LT
		ADDLT	R0,R0,7
		POP		{R4}
		BX LR
		
		.global		Zeller3
		.thumb_func
		//                           R0          R1          R2          R3
		// uint32_t Zeller3(uint32_t k, uint32_t m, uint32_t D, uint32_t C);
		// This function CANNOT use multiply instructions (MUL, MLS, etc.).
Zeller3:
		PUSH	{R4}
		MOV		R4,R1			//16x - 3x = 13x
		LSL		R4,R4,4
		ADD		R1,R1,R1,LSL 1
		SUB		R4,R4,R1
		
		SUB		R4,R4,1			//13x - 1
		LDR		R1,=5
		UDIV	R4,R4,R1		//(13x-1) / 5
		
		ADD		R4,R4,R0		//+k
		ADD		R4,R4,R2		//+D
		ADD		R4,R4,R2,LSR 2	//+D/4
		ADD		R4,R4,R3,LSR 2	//+C/4
		SUB		R4,R4,R3,LSL 1	//-2C
		
		LDR		R1,=7			
		SDIV	R2,R4,R1		//f/7
		RSB		R2,R2,R2,LSL 3	// 8(f/7) - (f/7) = 7(f/7)
		SUB		R0,R4,R2		//R0=f-7(f/7)
		LDR		R1,=0			//Check if less than 0
		CMP		R0,R1
		IT		LT
		ADDLT	R0,R0,7
		POP		{R4}
		BX LR
		
		.end