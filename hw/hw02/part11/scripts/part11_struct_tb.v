`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:29:42 10/05/2017 
// Design Name: 
// Module Name:    part11_struct_tb 
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
module part11_struct_tb;

    wire [4:0] out;   // The 4-bit sum/difference.
    wire   C;   // The 1-bit carry/borrow status.
    wire   V;   // The 1-bit overflow status.
    reg [4:0]  a;   // The 4-bit augend/minuend.
    reg [4:0]  b;   // The 4-bit addend/subtrahend.
    reg    sub;  // The operation: 0 => Add, 1=>Subtract.
    part11_struct alu(out, C, V, a, b, sub);

    initial begin

        a = 5'b0011;
        b = 5'b0011;
        sub = 0;
        $strobe("time = %0t, IN1=%b, IN2=%b, SUB=%d OUT=%b", $time, a, b, sub, out);
        #2

        a = 5'b0101;
        b = 5'b0010;
        sub = 1;
        $strobe("time = %0t, IN1=%b, IN2=%b, SUB=%d OUT=%b", $time, a, b, sub, out);
        #2;

        a = 5'b0101;
        b = 5'b0010;
        sub = 0;
        $strobe("time = %0t, IN1=%b, IN2=%b, SUB=%d OUT=%b", $time, a, b, sub, out);
        #2;

        a = 5'b0101;
        b = 5'b1010;
        sub = 0;
        $strobe("time = %0t, IN1=%b, IN2=%b, SUB=%d OUT=%b", $time, a, b, sub, out);
        #2;

    end

    initial #50 $finish;

endmodule
