module pong_controller1(Clock, iRESET, iRSRV, Q1, S, PSTATE, LCT, RCT, LSI, RSI);
	input Clock, iRESET, iRSRV;
	output reg LCT, RCT, LSI, RSI;
	output reg [9:1]PSTATE;
	output reg [1:0]S;
	parameter [9:1]sIDLE=9'b100000000;
	parameter [9:1]sRSRV=9'b000000001;
	parameter [9:1]sMOVL=9'b000000010;
	parameter [9:1]sENDL=9'b000000100;
	
	reg [9:1]NSTATE;
	output reg [3:0]Q1;
	
	always@(posedge Clock)
	begin
		case(S)
				0: Q1 <= Q1;
				1: Q1 <= {RSI,Q1[3:1]};
				2: Q1 <= {Q1[2:0],LSI};
				3: Q1 <= 4'b0000;
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
						if(iRSRV==1) NSTATE = sRSRV;
						else NSTATE = sIDLE; 
					end
			
			sRSRV:begin
						LCT=0;
						RCT=0;
						LSI=1;
						RSI=0;
						S[1]=1;
						S[0]=0;
						if(iRESET==1) NSTATE = sIDLE;
						else NSTATE = sMOVL; 
					end
			 
			sMOVL:begin
						LCT=0;
						RCT=0;
						LSI=0;
						RSI=0;
						S[1]=1;
						S[0]=0;
						if(iRESET==1) NSTATE =sIDLE;
						else if(Q1[3]==1)NSTATE = sENDL;
						else NSTATE = sMOVL; 
					end
			 
			sENDL:begin
						LCT=0;
						RCT=1;
						LSI=0;
						RSI=0;
						S[1]=0;
						S[0]=0;
						NSTATE = sIDLE;
					end
			
			default:NSTATE = sIDLE;
		endcase
	end
	
	always@(posedge Clock)
	begin
		if(iRESET==1)PSTATE<=sIDLE;
		else PSTATE<=NSTATE;
	end
	
endmodule
