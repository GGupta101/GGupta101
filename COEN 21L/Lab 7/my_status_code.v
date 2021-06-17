module my_status_code(PB1, EQ, codeS);
	input PB1, EQ;
	output reg [3:0] codeS;
	
	always@(*)
	begin
		if(PB1==0)codeS=4'b1111;
		if(PB1==1 && EQ==1)codeS=4'b1101;
		if(PB1==1 && EQ==0)codeS=4'b1110;
	end
endmodule