`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:29:42 10/05/2017 
// Design Name: 
// Module Name:    part11_behave_tb 
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
module part11_behave_tb;

    wire [4:0] out;   // 4-bit output
    wire c;   // 1-bit overflow status
    reg [4:0] a, b;   // the 4-bit inputs
    reg sub;  // if sub == 0 => add, else if == 1 => subtract

    part11_behave alu(out, c, a, b, sub);

    initial begin

        $strobe("a                  b                    sub    c    out");
        a = 5'b0011;
        b = 5'b0011;
        sub = 0;
        $strobe("%b (%d)   %b (%d)       %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2

        a = 5'b0101;
        b = 5'b0010;
        sub = 1;
        $strobe("%b (%d)   %b (%d)       %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2;

        a = 5'b0101;
        b = 5'b0010;
        sub = 0;
        $strobe("%b (%d)   %b (%d)       %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2;

        a = 5'b0101;
        b = 5'b1010;
        sub = 0;
        $strobe("%b (%d)   %b (%d)       %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2;

        a = 5'b1111;
        b = 5'b1110;
        sub = 0;
        $strobe("%b (%d)   %b (%d)      %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2;

        a = 5'b0000;
        b = 5'b1110;
        sub = 1;
        $strobe("%b (%d)   %b (%d)       %d    %b    %b (%d)", a, a, b, b, sub, c, out, out);
        #2;

    end

    initial #15 $finish;

endmodule
