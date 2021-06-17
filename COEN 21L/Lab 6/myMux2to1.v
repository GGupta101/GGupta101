module myMux2to1(En,S,W1,W0,Z);
	input En,S;
	input [3:0] W1,W0;
	output reg [3:0] Z;
	
	always@(*)
	begin
		if(En==1 && S==0) Z=W0;
		if(En==1 && S==1) Z=W1;
	end
	
endmodule
