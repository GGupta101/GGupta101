module myfulladd(A,B,CIN,SOUT,COUT);
	input A,B,CIN;
	output SOUT,COUT;
	
	assign SOUT=A^B^CIN;
	assign COUT=(A&B)|(B&CIN)|(A&CIN);
endmodule