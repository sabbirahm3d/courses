`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:59:06 10/05/2017 
// Design Name: 
// Module Name:    full_adder
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

module full_adder(
        output sub,
        output cout,
        input a,
        input b,
        input cin
    );
    
    wire w1, w2, w3, w4;

    xor(w1, a, b);
    xor(sub, cin, w1);
    and(w2, a, b);   
    and(w3, a, cin);
    and(w4, b, cin);   
    or(cout, w2, w3, w4);

endmodule // full_adder
