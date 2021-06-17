module pong_game12( iRESET, iRSRV, iLSRV, iRPAD, iLPAD, SP, mclock50, Q, LSCORE, RSCORE, LSI, RSI, PSTATE, VCLK, S);
	input  iRESET, iRSRV, iLSRV, iRPAD, iLPAD, mclock50;
	input [2:0]SP;
	output LSI, RSI, VCLK;
	output [11:0]Q;
	output [3:0]LSCORE, RSCORE;
	output [9:1]PSTATE;
	output [1:0]S;
	wire LCT, RCT;
	
	var_clock A1(mclock50, SP, iRESET, VCLK);
	pong_controller2 A2(iRESET, iRSRV, iLSRV, iRPAD, iLPAD, VCLK, PSTATE, S, Q, LCT, RCT, LSI, RSI);
	upcount4 A3(VCLK, iRESET, LCT, LSCORE);
	upcount4 A4(VCLK, iRESET, RCT, RSCORE);
	
endmodule
