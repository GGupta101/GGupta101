`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Santa Clara University
// Engineer: Gagan Gupta, Siddharth Venkatesh, Jonathan Yezalaleul
// 
// Create Date: 04/15/2021 01:02:06 PM
// Design Name: 
// Module Name: adder32bit
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


module adder32bit(d0,d1,sum);
input [31:0] d0;
input [31:0] d1;
output wire [31:0] sum;
wire [31:0] carrys;
adder1bit f0(d0[0], d1[0], 0, sum[0], carrys[0]);
adder1bit f1(d0[1], d1[1], carrys[0], sum[1], carrys[1]);
adder1bit f2(d0[2], d1[2], carrys[1], sum[2], carrys[2]);
adder1bit f3(d0[3], d1[3], carrys[2], sum[3], carrys[3]);
adder1bit f4(d0[4], d1[4], carrys[3], sum[4], carrys[4]);
adder1bit f5(d0[5], d1[5], carrys[4], sum[5], carrys[5]);
adder1bit f6(d0[6], d1[6], carrys[5], sum[6], carrys[6]);
adder1bit f7(d0[7], d1[7], carrys[6], sum[7], carrys[7]);
adder1bit f8(d0[8], d1[8], carrys[7], sum[8], carrys[8]);
adder1bit f9(d0[9], d1[9], carrys[8], sum[9], carrys[9]);
adder1bit f10(d0[10], d1[10], carrys[9], sum[10], carrys[10]);
adder1bit f11(d0[11], d1[11], carrys[10], sum[11], carrys[11]);
adder1bit f12(d0[12], d1[12], carrys[11], sum[12], carrys[12]);
adder1bit f13(d0[13], d1[13], carrys[12], sum[13], carrys[13]);
adder1bit f14(d0[14], d1[14], carrys[13], sum[14], carrys[14]);
adder1bit f15(d0[15], d1[15], carrys[14], sum[15], carrys[15]);
adder1bit f16(d0[16], d1[16], carrys[15], sum[16], carrys[16]);
adder1bit f17(d0[17], d1[17], carrys[16], sum[17], carrys[17]);
adder1bit f18(d0[18], d1[18], carrys[17], sum[18], carrys[18]);
adder1bit f19(d0[19], d1[19], carrys[18], sum[19], carrys[19]);
adder1bit f20(d0[20], d1[20], carrys[19], sum[20], carrys[20]);
adder1bit f21(d0[21], d1[21], carrys[20], sum[21], carrys[21]);
adder1bit f22(d0[22], d1[22], carrys[21], sum[22], carrys[22]);
adder1bit f23(d0[23], d1[23], carrys[22], sum[23], carrys[23]);
adder1bit f24(d0[24], d1[24], carrys[23], sum[24], carrys[24]);
adder1bit f25(d0[25], d1[25], carrys[24], sum[25], carrys[25]);
adder1bit f26(d0[26], d1[26], carrys[25], sum[26], carrys[26]);
adder1bit f27(d0[27], d1[27], carrys[26], sum[27], carrys[27]);
adder1bit f28(d0[28], d1[28], carrys[27], sum[28], carrys[28]);
adder1bit f29(d0[29], d1[29], carrys[28], sum[29], carrys[29]);
adder1bit f30(d0[30], d1[30], carrys[29], sum[30], carrys[30]);
adder1bit f31(d0[31], d1[31], carrys[30], sum[31], carrys[31]);
endmodule
