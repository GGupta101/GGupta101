`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/22/2021 02:07:52 PM
// Design Name: 
// Module Name: instrucMem
// Project Name: COEN 122L Lab 3
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


module instrucMem(instrucAddress,clk,instruc);
//1 input and CLK for instruction memory
input [31:0] instrucAddress;
input clk;

//1 output for instruction memory
output reg [31:0] instruc;

//wire to hold all the instructions stored within the instruction memory
wire [31:0] instrucData [31:0];

//Instructions for the Testbench
assign instrucData[0]=32'b11100000000000010000000000000000; //LD    x0, x1
//loop
assign instrucData[1]=32'b01010000010000010000010000000000; //INC   x1, x1, 1
assign instrucData[2]=32'b0;                                //NOP
assign instrucData[3]=32'b0;                                //NOP
assign instrucData[4]=32'b0;                                //NOP
assign instrucData[5]=32'b01110001000000100000010000000000; //SUB   x4, x2, x1   
assign instrucData[6]=32'b10010000001000000000000000000000; //BRZ   exit
assign instrucData[7]=32'b11100001000000010000000000000000; //LD    x4, x1
assign instrucData[8]=32'b0;                                //NOP
assign instrucData[9]=32'b0;                                //NOP
assign instrucData[10]=32'b0;                               //NOP
assign instrucData[11]=32'b01110001000001000000000000000000;//SUB   x4, x4, x0   
assign instrucData[12]=32'b10110000000111110000000000000000;//BRN   loop
assign instrucData[13]=32'b11100000000000010000000000000000;//LD    x0, x1
assign instrucData[14]=32'b10000000000111110000000000000000;//J     loop
assign instrucData[15]=32'b0;                               //NOP
assign instrucData[16]=32'b0;                               //NOP
assign instrucData[17]=32'b0;                               //NOP
assign instrucData[18]=32'b0;                               //NOP
assign instrucData[19]=32'b0;                               //NOP
//exit
assign instrucData[32]=32'b0;                               //NOP

//Postive Edge CLK Always block
always@(posedge clk)
begin
    //Get the correct instrucData value based on the input location
    instruc=instrucData[instrucAddress];
end
endmodule
