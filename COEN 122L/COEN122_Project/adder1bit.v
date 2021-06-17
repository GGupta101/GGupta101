`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: adder1bit
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


module adder1bit(d0,d1,cin,sum,cout);
input d0,d1,cin;
output reg sum,cout;
always@(d0,d1,cin)
begin
    sum=d0^d1^cin;
    cout=(d0&d1)|(d0&cin)|(d1&cin);
end
endmodule
