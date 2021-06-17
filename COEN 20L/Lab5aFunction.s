/*
Gagan Gupta
COEN 20L
Lab 5a Function
11/05/19
*/	
		.syntax		unified
		.cpu		cortex-m4
		.text
		.global		MatrixMultiply
		.thumb_func
		
		// void MatrixMultiply(int32_t a[3][3], int32_t b[3][3], int32_t c[3][3]);
MatrixMultiply:
		PUSH		{LR, R4-R9}			//PUSH LR and registers
		MOV			R4,R0				//Store matrices in R4, R5, and R6
		MOV			R5,R1
		MOV			R6,R2
		
		MOV			R7,0				//Initally set row to 0 before loop
Row:	CMP			R7,2				//row<3
		BHI			EndFunc
	
		MOV			R8,0				//col set to 0 for every new row
Col:	CMP			R8,2				//col<2
		BHI			EndRow
		
		MOV			R3,3				//a[row][col] = 0
		MLA			R3,R3,R7,R8
		MOV			R0,0
		STR			R0,[R4,R3, LSL 2]
		
		MOV			R9,0				//k set to 0 for every new col
KFor:	CMP			R9,2				//k<3
		BHI			EndCol
		
		MOV			R3,3				//tempA = (3*row)+col and make sure to LSL 2
		MLA			R3,R3,R7,R8
		LDR			R0,[R4,R3, LSL 2]
		
		MOV			R3,3				//tempB = (3*row)+k and make sure to LSL 2
		MLA			R3,R3,R7,R9
		LDR			R1,[R5,R3, LSL 2]
		
		MOV			R3,3				//tempC = (3*k)+col and make sure to LSL 2
		MLA			R3,R3,R9,R8
		LDR			R2,[R6,R3, LSL 2]
	
		BL			MultAndAdd			//Call MultAndAdd(tempA,tempB,tempC)
		
		MOV			R3,3				//Find (3*row)+col
		MLA			R3,R3,R7,R8
		STR			R0,[R4,R3, LSL 2]	//Store result from MultAndAdd into (3*row)+col
		
		ADD			R9,R9,1				//k++
		B			KFor

EndCol:
		ADD			R8,R8,1				//col++
		B			Col
		
EndRow:
		ADD			R7,R7,1				//row++
		B			Row
EndFunc:
		POP			{PC,R4-R9}			//POP PC and registers
		.end