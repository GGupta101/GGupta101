`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/22/2021 02:07:52 PM
// Design Name: 
// Module Name: dataMem
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


module dataMem(address,writeData,memWrite,memRead,clk,readData);
//4 inputs and CLK for data memory
input [31:0] address;
input [31:0] writeData;
input memWrite,memRead,clk;

//1 output for data memory
output reg [31:0] readData;

//Reg to hold all the instructions stored within the data memory
reg [31:0] data [31:0];

//Prefill some of the values for the Testbench
initial
begin
    //1,-4,6,0,5
    data[0]=1;
    data[1]=-4;
    data[2]=6; //max for length 5
    data[3]=0;
    data[4]=5;
    data[5]=20123;
    data[6]=18833;
    data[7]=39041;
    data[8]=-16424;
    data[9]=36453;
    data[10]=11705;
    data[11]=-49943;
    data[12]=58324; //max for length 25
    data[13]=-35654;
    data[14]=-37822;
    data[15]=-2700;
    data[16]=2050;
    data[17]=46716;
    data[18]=-40214;
    data[19]=-19144;
    data[20]=-26370;
    data[21]=-17979;
    data[22]=-26735;
    data[23]=-29557;
    data[24]=14800;
end

//Postive Edge CLK Always block
always@(negedge clk)
begin
    //Can only read or write in a clock cycle where reads take prority over writes
    //If the read flag is high, then read the data in the corresponding location in data
    if(memRead==1) readData=data[address[15:0]];
    //If the write flag is high, then write the data to the corresponding location in data
    else if(memWrite==1) data[address[15:0]]=writeData;
end
endmodule
