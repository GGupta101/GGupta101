module pong_controller2(iRESET, iRSRV, iLSRV, iRPAD, iLPAD, VCLK, PSTATE, S, Q1, LCT, RCT, LSI, RSI);
	input iRESET, iRSRV, iLSRV, iRPAD, iLPAD, VCLK;
	output reg LCT, RCT, LSI, RSI;
	output reg [9:1]PSTATE;
	output reg [1:0]S;
	parameter [9:1]sIDLE=9'b100000000, sRSRV=9'b000000001, sMOVL=9'b000000010, sENDL=9'b000000100, sMISL=9'b000001000, sLSRV=9'b000010000, sMOVR=9'b000100000, sENDR=9'b001000000, sMISR=9'b010000000;
	reg [9:1]NSTATE;
	output reg [11:0]Q1;
	
	always@(posedge VCLK)
	begin
		case(S)
				0: Q1 <= Q1;
				1: Q1 <= {RSI,Q1[11:1]};
				2: Q1 <= {Q1[10:0],LSI};
				3: Q1 <= 12'd0;
		endcase
	end
	
	always@(*)
	begin	
		case(PSTATE)
			sIDLE:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=1;
						S[0]=1;
						if(iRSRV==1)NSTATE=sRSRV;
						else if(iLSRV==1)NSTATE=sLSRV;
						else NSTATE=sIDLE;
					end
			
			sRSRV:begin
						LCT=0;
						RCT=0;
						LSI=1;
						RSI=0;
						S[1]=1;
						S[0]=0;
						if(iRESET==1)NSTATE=sIDLE;
						else NSTATE=sMOVL;
					end
			 
			sMOVL:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=1;
						S[0]=0;
						if(iRESET==1)NSTATE=sIDLE;
						else if(Q1[11]==1 && iLPAD==0)NSTATE=sENDL;
						else if(Q1[11]==0 && iLPAD==1)NSTATE=sMISL;
						else if(Q1[11]==1 && iLPAD==1)NSTATE=sMOVR;
						else NSTATE=sMOVL;
					end
			 
			sENDL:begin
						LCT=0;
						RCT=1;
						LSI=0;
						RSI=0;
						S[1]=0;
						S[0]=0;
						NSTATE=sIDLE;
					end
					
			sMISL:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=1;
						S[0]=0;
						if(iRESET==1)NSTATE=sIDLE;
						else if(iRESET==0 && Q1[11]==1)NSTATE=sENDL;
						else NSTATE=sMISL;
					end
			sLSRV:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=1;
						S[1]=0;
						S[0]=1;
						if(iRESET==1)NSTATE=sIDLE;
						else NSTATE=sMOVR;
					end
					
			sMOVR:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=0;
						S[0]=1;
						if(iRESET==1)NSTATE=sIDLE;
						else if(Q1[0]==1 && iRPAD==0)NSTATE=sENDR;
						else if(Q1[0]==0 && iRPAD==1)NSTATE=sMISR;
						else if(Q1[0]==1 && iRPAD==1)NSTATE=sMOVL;
						else NSTATE=sMOVR;
					end
					
			sENDR:begin
						LCT=1;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=0;
						S[0]=0;
						NSTATE=sIDLE;
					end
					
			sMISR:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=0;
						S[0]=1;
						if(iRESET==1)NSTATE=sIDLE;
						else if(iRESET==0 && Q1[0]==1)NSTATE=sENDR;
						else NSTATE=sMISR;
					end
			
			default:NSTATE=sIDLE;
			
		endcase
	end
	
	always@(posedge VCLK)
	begin
		if(iRESET==1)PSTATE<=sIDLE;
		else PSTATE<=NSTATE;
	end
	
endmodule
