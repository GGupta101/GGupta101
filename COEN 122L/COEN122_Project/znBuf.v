`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 06/03/2021 03:06:22 AM
// Design Name: 
// Module Name: znBuf
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


module znBuf(z,n,clk,zout,nout);
input z;
input n;
input clk;
output reg zout;
output reg nout;

initial
begin
    zout=0;
    nout=0;
end

always@(posedge clk)
begin
    zout=z;
    nout=n;
end
endmodule
