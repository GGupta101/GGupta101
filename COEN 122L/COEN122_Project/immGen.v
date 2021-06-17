`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 06/02/2021 11:10:21 PM
// Design Name: 
// Module Name: immGen
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


module immGen(instruction, immExt);
input [31:0] instruction;
output reg [31:0] immExt;
always@(*)
begin
    if(instruction[31:28]==4'b1111) immExt={{20{instruction[21]}},instruction[21:10]};
    else if(instruction[31:28]==4'b0101) immExt={{26{instruction[15]}}, instruction[15:10]};
end
endmodule
