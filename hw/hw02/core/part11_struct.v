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
        input [1:0] a,
        input [1:0] b,
        input sub,
        output reg [1:0] y,
        output reg c
    );

    primitive addtable(
            output out,
            input cin, 
            input in1,
            input in2
        );

        table
            // cin in1  in2  : out
                0   0    0   : 0;
                0   0    1   : 1;
                0   1    0   : 1;
                0   1    1   : 0;
                1   0    0   : 1;
                1   0    1   : 0;
                1   1    0   : 0;
                1   1    1   : 1;
        endtable

    endprimitive

    // wire  w0, w1, w2, w3, w4, o0, o1;
    // xor(w3, b[0], sub);
    // xor(w0, a[0], b[0]);
    // xor(o0, w0, 0);

    // and(w1, w0, cin);
    // and(w2, a[0], b[0]);
    // or(w4, w1, w2);

    // // 2nd bit
    // xor(b[1], b[1], sub);
    // xor(w0, a[1], b[1]);
    // xor(o1, w0, w4);

    // and(w1, w0, cin);
    // and(w2, a[1], b[1]);
    // or(w4, w1, w2);

//	 y[0] = o0;
//	 y[1] = o1;

endmodule
