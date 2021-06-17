module pb_clock(Resetn, Setn, MCLK);
	input Resetn, Setn;
	output reg MCLK;
	
	always@(negedge Resetn, negedge Setn)
	begin
		if(Resetn==0)
			MCLK<=0;
		else if(Setn==0)
			MCLK<=1;
		else MCLK<=0;
	end
endmodule
