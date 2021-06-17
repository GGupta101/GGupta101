`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/29/2021 01:43:50 PM
// Design Name: 
// Module Name: buf_IFtoID
// Project Name: COEN 122L Lab 4
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


module buf_IFtoID(PCin, IMEMin, clk, PCout, IMEMout);
//2 inputs and clk for buffer
input [31:0] PCin;
input [31:0] IMEMin;
input clk;
//2 outputs
output reg [31:0] PCout;
output reg [31:0] IMEMout;

always@(posedge clk)
begin
    //Outputs are based on the current buffer register data
    PCout=PCin;
    IMEMout=IMEMin;
end
endmodule
