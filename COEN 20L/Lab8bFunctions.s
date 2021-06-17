/*
Gagan Gupta
COEN 20L
Lab 8b Functions
12/3/19
*/

				.syntax		unified
				.cpu		cortex-m4
				.text		
				.global		Discriminant
				.thumb_func
				// float Discriminant(float a, float b, float c);
Discriminant:
				VMOV			S3,4			//Load a 4.0 into S3
				VMUL.F32		S1,S1,S1		//b^2
				VMUL.F32		S0,S0,S2		//a*c
				VMLS.F32		S1,S0,S3		//b^2-4.0*a*c stored in S1
				VMOV			S0,S1			//Move the data from S1 into S0
				BX 				LR
			
			
			
				.global		Quadratic
				.thumb_func
				// float Quadratic(float x, float a, float b, float c);
Quadratic:
				VMUL.F32		S4,S0,S0		//x^2 stored in S4
				VMLA.F32		S3,S1,S4		//c+a*x^2
				VMLA.F32		S3,S0,S2		//(c+a*x^2)+b*x stored in S3
				VMOV			S0,S3			//Move the data from S3 into S0
				BX LR
			
			
			
				.global		Root1
				.thumb_func
				// float Root1(float a, float b, float c);
Root1:
				PUSH			{LR}
				VMOV			S4,S0			//Store a and b before calling Discriminant
				VMOV			S5,S1
				BL				Discriminant
				VSQRT.F32		S0,S0			//sqrt of Discriminant
				VNEG.F32		S5,S5			//-b
				VMOV			S1,2			//Load a 2.0 into S1
				VMUL.F32		S4,S4,S1		//2.0*a
				VADD.F32		S0,S5,S0		//-b+sqrt
				VDIV.F32		S0,S0,S4		//(-b+sqrt)/(2.0*a)
				POP				{PC}
				
				
				.global		Root2
				.thumb_func
				// float Root2(float a, float b, float c);
Root2:
				PUSH			{LR}
				VMOV			S4,S0			//Store a and b before calling Discriminant
				VMOV			S5,S1
				BL				Discriminant
				VSQRT.F32		S0,S0			//sqrt of Discriminant
				VNEG.F32		S5,S5			//-b
				VMOV			S1,2			//Load a 2.0 into S1
				VMUL.F32		S4,S4,S1		//2.0*a
				VSUB.F32		S0,S5,S0		//-b-sqrt
				VDIV.F32		S0,S0,S4		//(-b+sqrt)/(2.0*a)
				POP				{PC}
				.end
				