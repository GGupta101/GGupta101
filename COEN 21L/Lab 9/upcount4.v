module upcount4(CLK, iRESET, CT, count);
	input CLK, iRESET, CT;
	output reg [3:0]count;
	
	always@(posedge CLK)
	begin
		if(CT==1)count<=count+1;
		else if(iRESET==1)count<=4'b0000;
		else count<=count;
	end
endmodule
	