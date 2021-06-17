`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 05/27/2021 04:53:45 PM
// Design Name: 
// Module Name: SCU_CPU
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


//input into IMEM and DMEM
//make testbench where we can check for "x3" aka max at the end of instructions

module SCU_CPU();

//Most important wires to look at for debugging
reg clk;
wire PCselect;
wire [31:0] NextPC;
wire [31:0] PC;
wire [31:0] IMEMout;
wire [31:0] IMEMBUFout;
wire [5:0] rs;
wire [31:0] xrs;
wire [5:0] rt;
wire [31:0] xrt;
wire [5:0] rd;
wire [5:0] rdOut1;
wire [31:0] writeData;
wire regWrtOut1;

//Other wires needed
wire [31:0] PCBranch;
wire [31:0] PCout;
wire [6:0] EXout;
wire [3:0] WBout;
wire Mout;
wire regWrtOut;
wire regWrt;
wire [31:0] immExt;
wire [31:0] PCout2;
wire [31:0] xrsBUFout;
wire [31:0] xrtBUFout;
wire [31:0] IGout;
wire [6:0] EXBUFout;
wire [3:0] WBBUFout;
wire MBUFout;
wire [31:0] PC1;
wire [31:0] Mxrs;
wire [31:0] mux1Out;
wire [31:0] mux2Out;
wire z;
wire n;
wire [31:0] ALUout;
wire [31:0] Mxrsout;
wire [31:0] ALUBUFout;
wire Zout;
wire Nout;
wire [31:0] xrsBUFout2;
wire [3:0] WBBUFout2;
wire MBUFout2;
wire zBuf;
wire nBuf;
wire [5:0] rdOut;


//IF Stage with PC adder, PC mux, PC Reg, Instruction Memory, and the buffer
adder32bit f6(PC, 1, PC1);
mux2to1 f14(PC1, PCBranch, PCselect, NextPC);
PCReg f16(NextPC, clk, PC);
instrucMem f1(PC, clk, IMEMout);
buf_IFtoID f2(PC, IMEMout, clk, 
            PCout, IMEMBUFout);


//ID Stage with Control, Register File, Immediate Generator, and the buffer
ControlBlock f3(IMEMBUFout[31:28], clk, regWrt, 
EXout[0], EXout[1], EXout[2], EXout[3], EXout[6:4], 
WBout[0], WBout[1], WBout[2], WBout[3], 
Mout);
//Used for Debugging
assign rd = IMEMBUFout[27:22];
assign rs = IMEMBUFout[21:16];
assign rt = IMEMBUFout[15:10];
regFile f4(IMEMBUFout[21:16], IMEMBUFout[15:10], rdOut1, writeData, regWrtOut1, clk, xrs, xrt);
immGen f15(IMEMBUFout, immExt);
buf_IDtoEX f5(PCout, xrs, xrt, immExt, EXout, (WBout & ~PCselect), Mout, (regWrt & ~PCselect), IMEMBUFout[27:22], clk, 
            PCout2, xrsBUFout, xrtBUFout, IGout, EXBUFout, WBBUFout, MBUFout, regWrtOut, rdOut);

//EX and MEM Stage with Data Memory, ALU Muxes, ALU, and the buffer
dataMem f7(xrsBUFout, xrtBUFout, EXBUFout[0], EXBUFout[1], clk, Mxrs);
mux2to1 f8(xrsBUFout, PCout2, EXBUFout[2], mux1Out);
mux2to1 f9(xrtBUFout, IGout, EXBUFout[3], mux2Out);
alu f10(mux2Out, mux1Out, EXBUFout[6:4], ALUout, z, n);
buf_EXtoMEM f11(Mxrs, ALUout, z, n, xrsBUFout, (WBBUFout & ~PCselect), MBUFout, (regWrtOut & ~PCselect), rdOut, clk, 
                Mxrsout, ALUBUFout, Zout, Nout, xrsBUFout2, WBBUFout2, MBUFout2, regWrtOut1, rdOut1);

//WB Stage with a Flag Buffer, PC Mux Select Logic, and Muxes
znBuf f17(Zout,Nout,clk,zBuf,nBuf);
assign PCselect=((WBBUFout2[0]===1) | (WBBUFout2[1]===1) | ((WBBUFout2[2]===1) & (zBuf===1)) | ((WBBUFout2[3]===1) & (nBuf===1)));
mux2to1 f12(xrsBUFout2, Mxrsout, WBBUFout2[1], PCBranch);
mux2to1 f13(ALUBUFout, Mxrsout, MBUFout2, writeData);

initial 
begin
    #1000
    $finish;
end

//Run clock at 1ns Clock Cycles
initial
begin
    clk = 0;
    forever #0.5 clk = ~clk;
end

endmodule
