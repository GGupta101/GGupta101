`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: 3to1mux
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


module mux3to1(d0,d1,d2,s,out);
input [31:0] d0,d1,d2;
input [1:0] s;
output reg [31:0] out;
always@(d0,d1,d2,s)
begin
    if(s==0) out=d0;
    else if(s==1) out=d1;
    else if(s==2) out=d2;
end
endmodule
