module pb_clock(Resetn, Setn, MCLK);
	input Resetn, Setn;
	output reg MCLK;
	always@(*)
	begin
		if(Resetn==0 && Setn==1)MCLK=0;
		if(Resetn==1 && Setn==0)MCLK=1;
		else MCLK=0;
	end
endmodule
