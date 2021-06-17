`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/29/2021 01:43:50 PM
// Design Name: 
// Module Name: buf_EXtoMEM
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


module buf_EXtoMEM(RDMemin, ALUin, Zin, Nin, RD1in, WBin, Min, regWrt, rd, clk, 
                    RDMemout, ALUout, Zout, Nout, RD1out, WBout, Mout, regWrtOut, rdOut);
input [31:0] RDMemin;
input [31:0] ALUin;
input Zin;
input Nin;
input [31:0] RD1in;
input clk;
//control
//Jump, JumpFlag, BRZ, BRN
input [3:0] WBin;
//MemtoReg
input Min;
input regWrt;
input [5:0] rd;
output reg  [31:0] RDMemout;
output reg  [31:0] ALUout;
output reg  Zout;
output reg  Nout;
output reg  [31:0] RD1out;
output reg [3:0] WBout;
output reg Mout;
output reg regWrtOut;
output reg [5:0] rdOut;

always@(posedge clk)
begin
    RDMemout=RDMemin;
    ALUout=ALUin;
    Zout=Zin;
    Nout=Nin;
    RD1out=RD1in;
    WBout=WBin;
    Mout=Min;
    regWrtOut=regWrt;
    rdOut=rd;
end
endmodule
