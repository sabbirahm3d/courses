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

module part11_behave(out, c, a, b, sub);

    output reg [4:0] out;
    output reg c;  // carry out indicates over-/underflow
    input [4:0] a;
    input [4:0] b;
    input sub;

    always @(a, b, sub) begin

        if (~sub) begin
            {c, out} = a + b;
        end else if (sub) begin
            {c, out} = a - b;
        end

    end

endmodule
