`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: twoComp
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


module twoComp(in, out);
input [31:0] in;
output [31:0] out;
adder32bit f((~in),1,out);
endmodule
