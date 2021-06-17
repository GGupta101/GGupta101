`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 05/20/2021 03:35:14 PM
// Design Name: 
// Module Name: ControlBlock
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

//Description of Control Block Elements
//Input
//ID
//EX
//WB
//M
module ControlBlock(opcode, clk, 
RegWrt, 
MemWrt, MemRead, SVPCFlag, ALUsrc, ALUOp, 
Jump, JumpMem, BRZ, BRN, 
MemToReg);
 
input [3:0] opcode;
input clk;
output reg RegWrt;
output reg MemToReg;
output reg [2:0] ALUOp;
output reg MemRead;
output reg MemWrt;
output reg BRN;
output reg BRZ;
output reg Jump;
output reg JumpMem;
output reg SVPCFlag;
output reg ALUsrc;

always@(negedge clk)
begin
    RegWrt=0;
    MemToReg=0;
    ALUOp=0;
    MemRead=0;
    MemWrt=0;
    BRN=0;
    BRZ=0;
    Jump=0;
    JumpMem=0;
    SVPCFlag=0;
    ALUsrc=0;
     
    //SavePC
    if(opcode==4'b1111)
        begin
        ALUOp=3'b001;
        RegWrt=1;
        MemToReg=1;
        MemRead=1;
        ALUsrc=1;
        SVPCFlag=1;
        end
    //Load
    else if(opcode==4'b1110)
        begin
        RegWrt=1;
        MemToReg=1;
        MemRead=1;
        ALUsrc=1;
        end
    //Store
    else if (opcode==4'b0011)
        begin
        MemToReg=1;
        MemWrt=1;
        ALUsrc=1;
        end
    //Add
    else if(opcode==4'b0100)
        begin
        ALUOp=3'b100;
        RegWrt=1;
        end
    //Increment
    else if(opcode==4'b0101)
        begin
        RegWrt=1;
        ALUOp=3'b100;
        ALUsrc=1;
        end
    //Negate
    else if(opcode==4'b0110)
        begin
        RegWrt=1;
        ALUOp=3'b010;
        end
    //Subtract
    else if(opcode==4'b0111)
        begin
        RegWrt=1;
        ALUOp=3'b001;
        end
    //Jump
    else if(opcode==4'b1000)
        begin
        Jump=1;
        end
    //BranchifZero
    else if(opcode==4'b1001)
        begin
        BRZ=1;
        end
    //JumpMemory
    else if(opcode==4'b1010)
        begin
        MemRead=1;
        JumpMem=1;
        end
    //BranchifNegitive
    else if(opcode==4'b1011)
        begin
        BRN=1;
        end
end

endmodule

