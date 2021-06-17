module var_clock(mclock50, SP, iRESET, VCLK);
	input mclock50, iRESET;
	input[2:0]SP;
	output reg VCLK;
	reg[26:0] count;
	
	always@(posedge mclock50)
	count<=count+1;
	
	always@(*)
	begin
		case(SP)
			0: VCLK=count[26];
			1: VCLK=count[25];
			2: VCLK=count[24];
			3: VCLK=count[23];
			4: VCLK=count[22];
			5: VCLK=count[21];
			6: VCLK=count[20];
			7: VCLK=count[19];
		endcase
	end
endmodule
