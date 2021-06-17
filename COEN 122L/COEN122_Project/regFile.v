`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/22/2021 02:07:52 PM
// Design Name: 
// Module Name: regFile
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


module regFile(readReg1,readReg2,writeReg,writeData,regWrite,clk,readData1,readData2);
//5 inputs and CLK for register
input [5:0] readReg1;
input [5:0] readReg2;
input [5:0] writeReg;
input [31:0] writeData;
input regWrite, clk;

//2 outputs for register
output reg [31:0] readData1;
output reg [31:0] readData2;

//Reg to hold all the values stored within the register
reg [31:0] regVals [63:0];

//Prefill some of the values for the Testbench
initial
begin
    regVals[0]=0;
    regVals[1]=0;
    regVals[2]=5;
    regVals[31]=1;
    regVals[32]=32;
end

//Postive Edge CLK Always block
always@(negedge clk)
begin
    //We read before we write (assuming the wrte flag is high)
    //Get the correct readData values based on the input locations
    readData1=regVals[readReg1];
    readData2=regVals[readReg2];
    //If the write flag is high, then write the data to the corresponding location in regVals
    if(regWrite==1) regVals[writeReg]=writeData;
end
endmodule
