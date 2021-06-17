`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/29/2021 01:43:50 PM
// Design Name: 
// Module Name: buf_IDtoEX
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module buf_IDtoEX(PCin, RD1in, RD2in, IGin, EXin, WBin, Min, regWrt, rd, clk, 
                PCout, RD1out, RD2out, IGout, EXout, WBout, Mout, regWrtOut, rdOut);
input [31:0] PCin;
input [31:0] RD1in;
input [31:0] RD2in;
input [31:0] IGin;
input clk;
//control
//MemWrite, MemRead, ALUOp (3bit), ALUSrc, SVPCFlag
input [6:0] EXin;
//Jump, JumpFlag, BRZ, BRN
input [3:0] WBin;
//MemtoReg
input Min;
input regWrt;
input [5:0] rd;
output reg [31:0] PCout;
output reg [31:0] RD1out;
output reg [31:0] RD2out;
output reg [31:0] IGout;
output reg [3:0] WBout;
output reg Mout;
output reg [7:0] EXout;
output reg regWrtOut;
output reg [5:0] rdOut;

always@(posedge clk)
begin
    PCout=PCin;
    RD1out=RD1in;
    RD2out=RD2in;
    IGout=IGin;
    WBout=WBin;
    Mout=Min;
    EXout=EXin;
    regWrtOut=regWrt;
    rdOut=rd;
end
endmodule
