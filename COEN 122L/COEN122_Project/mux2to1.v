`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: 2to1mux
// Project Name: COEN 122L Lab 2
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


module mux2to1(d0,d1,s,out);
input s;
input [31:0] d0,d1;
output reg [31:0] out;

always@(d0,d1,s)
begin
    if(s==0) out=d0;
    else if(s==1) out=d1;
end
endmodule
