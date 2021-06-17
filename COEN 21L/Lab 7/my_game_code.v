module my_game_code(SP1, SP0, C, code_value);
	input SP1, SP0;
	input [7:0] C;
	output reg [1:0] code_value;
	
	always@(*)
	case({SP1,SP0})
		0:
		begin
			code_value[1]=C[7];
			code_value[0]=C[6];
		end
		1:
		begin
			code_value[1]=C[5];
			code_value[0]=C[4];
		end
		2:
		begin
			code_value[1]=C[4];
			code_value[0]=C[3];
		end
		3:
		begin
			code_value[1]=C[1];
			code_value[0]=C[0];
		end
	endcase
endmodule
	