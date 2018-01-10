`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:57:06 10/05/2017 
// Design Name: 
// Module Name:    part11_struct 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module part11_struct(
        output [4:0] out,
        output c, 
        input [4:0] a,
        input [4:0] b,
        input sub
    );

    wire c0, c1, c2, c3, c4;
    wire b0, b1, b2, b3, b4;
    wire under, over;

    // the structural design of a multi-bit adder/subtractor
    xor(b0, b[0], sub);
    xor(b1, b[1], sub);
    xor(b2, b[2], sub);
    xor(b3, b[3], sub);
    xor(b4, b[4], sub);

    // two different bits for the selector and the MSB indicate underflow
    xor(under, c4, sub);
    // two different MSB carry output bits indicate an overflow
    xor(over, c4, c3);
    or(c, over, under);

    full_adder fa0(out[0], c0, a[0], b0, sub);
    full_adder fa1(out[1], c1, a[1], b1, c0);
    full_adder fa2(out[2], c2, a[2], b2, c1);
    full_adder fa3(out[3], c3, a[3], b3, c2);
    full_adder fa4(out[4], c4, a[4], b4, c3);

endmodule
