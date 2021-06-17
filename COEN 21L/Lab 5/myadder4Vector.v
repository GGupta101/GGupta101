module myadder4Vector(X,Y,C0,S,C4,V);
	input [3:0] X,Y;
	input C0;
	output [3:0] S;
	output C4,V;
	wire [3:1] C;
	
	myfulladd sum0(X[0],Y[0],C0,S[0],C[1]);
	myfulladd sum1(X[1],Y[1],C[1],S[1],C[2]);
	myfulladd sum2(X[2],Y[2],C[2],S[2],C[3]);
	myfulladd sum3(X[3],Y[3],C[3],S[3],C4);
	assign V=(C[3]^C4);
endmodule