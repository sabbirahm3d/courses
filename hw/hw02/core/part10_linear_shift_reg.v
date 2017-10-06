`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:04:34 10/05/2017 
// Design Name: 
// Module Name:    part10_linear_shift_reg 
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
module part10_linear_shift_reg(out, clk, rst);

    output reg [15:0] out;
    input clk, rst;
    wire feedback;

    // polynomial for maximal LFSR of 16 bits (2^16-1 terms)
    assign feedback = ~(out[15] ^ out[14] ^ out[12] ^ out[3]);

    always @(posedge clk, posedge rst) begin

        if (rst) begin
            out = 16'b0;  // start with a reset
        end else begin
            out = {out[14:0], feedback};
        end

        // to prevent the zero state from occuring between cycles
        if (out == 16'b0 && ~rst) begin
            out = {15'b0, 1'b1};
        end

    end

endmodule
