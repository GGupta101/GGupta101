module myALU4(A,B,P,C0,R,C4,V,Z);
	input [3:0] A,B,P;
	input C0;
	output [3:0] R;
	output V,Z,C4;
	reg [3:0] O2;	
	
	always@(*)
		case({P[2:1]})
			0: O2=B;
			1: O2={~B[3],~B[1],~B[2],~B[0]};
			2: O2=4'b0000;
			3: O2=4'b1111;
		endcase
	
	myadder4 add(A,O2,P[0],R,C4,V);
	assign Z=~R[3]&~R[2]&~R[1]&~R[0];
endmodule