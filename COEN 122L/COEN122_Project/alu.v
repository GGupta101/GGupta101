`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: alu
// Project Name: COEN 122L Project
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


module alu(A,B,sel,out,z,n);
input [31:0] A,B;
input [2:0] sel;
output [31:0] out;
output reg z,n;
reg [1:0] selB;
reg [1:0] selA;
wire [31:0] mux2to1out, mux3to1out, twoCompoutA, twoCompoutB;

//sel=0, ADD, NEG, SUB
//100 = B+A
//010 = -B+0
//001 = B-A
//000 = no op
//111 = 0+A
always@(A,B,sel)
begin    
    if(sel==4|sel==1)selB=0;
    else if(sel==0|sel==7)selB=1;
    else selB=2;
    
    if(sel==4|sel==7)selA=0;
    else if(sel==0|sel==2)selA=1;
    else selA=2;
end

mux3to1 f1(B,0,twoCompoutB,selB,mux2to1out);
twoComp f2(A,twoCompoutA);
mux3to1 f3(A,0,twoCompoutA,selA,mux3to1out);
adder32bit f4(mux2to1out,mux3to1out,out);

always@(out)
begin
    if(out==0) z=1;
    else z=0;
    n=out[31];
end
endmodule
