module USR4(X, RS1, LS1, CLK, S, Q);
	input [3:0] X;
	input [1:0] S;
	input RS1,LS1,CLK;
	output reg [3:0] Q;

	always @(posedge CLK)
		case(S)
			0: Q = Q;
			1: Q = {RS1,Q[3:1]};
			2: Q = {Q[2:0],LS1};
			3: Q = X;
	endcase
endmodule
