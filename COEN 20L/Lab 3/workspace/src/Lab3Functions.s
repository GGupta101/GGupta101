/*
Gagan Gupta
COEN 20L
Lab 3 Functions
10/15/19
*/		

		.syntax		unified
		.cpu		cortex-m4
		.text
		
		.global		UseLDRB
		.thumb_func
UseLDRB:
	.rept		512				//Repeat copying 1 byte 512 times
	LDRB		R2,[R1],1		//Call LDRB and STRB but shifted by 1 byte
	STRB		R2,[R0],1	
	.endr						//End the repeat
	BX			LR
	
		.global		UseLDRH
		.thumb_func
UseLDRH:
	.rept		256				//Repeat copying 2 byte 256 times
	LDRH		R2,[R1],2		//Call LDRH and STRH but shifted by 2 bytes
	STRH		R2,[R0],2	
	.endr						//End the repeat
	BX			LR
	
		.global		UseLDR
		.thumb_func
UseLDR:
	.rept		128				//Repeat copying 4 byte 128 times
	LDR			R2,[R1],4		//Call LDR and STR but shifted by 4 bytes
	STR			R2,[R0],4	
	.endr						//End the repeat
	BX			LR
	
		.global		UseLDRD
		.thumb_func
UseLDRD:
	.rept		64				//Repeat copying 8 byte 64 times
	LDRD		R2,[R1],8		//Call LDRD and STRD but shifted by 8 bytes
	STRD		R2,[R0],8	
	.endr						//End the repeat
	BX			LR
	
		.global		UseLDM
		.thumb_func
UseLDM:
	PUSH		{R4-R11}		//Push Registers 4 through 11 to be used in the program
	.rept		16				//Repeat copying 32 byte 16 times
	LDMIA		R1!,{R2-R9}		//Call LDMIA with 8 registers and with the write-back flag 
	STMIA		R0!,{R2-R9}		//Call STMIA with 8 registers and with the write-back flag 
	.endr						//End the repeat 
	POP			{R4-R11}		//Popped the pushed registers
	BX			LR
	
		.end