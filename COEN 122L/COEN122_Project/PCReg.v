`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 06/02/2021 11:45:16 PM
// Design Name: 
// Module Name: PCReg
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


module PCReg(NextPC, clk, PC);
input [31:0] NextPC;
input clk;
output reg [31:0] PC;

initial
begin
    PC=0;
end

always@(posedge clk)
begin
    PC=NextPC;
end
endmodule
