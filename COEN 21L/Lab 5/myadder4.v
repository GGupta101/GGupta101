module myadder4(X0,X1,X2,X3,Y0,Y1,Y2,Y3,CO,S0,S1,S2,S3,C4,V);
	input X0,X1,X2,X3,Y0,Y1,Y2,Y3,CO;
	output S0,S1,S2,S3,C4,V;
	wire C1,C2,C3;
	
	myfulladd sum0(X0,Y0,C0,S0,C1);
	myfulladd sum1(X1,Y1,C1,S1,C2);
	myfulladd sum2(X2,Y2,C2,S2,C3);
	myfulladd sum3(X3,Y3,C3,S3,C4);
	assign V=(C3^C4);
endmodule