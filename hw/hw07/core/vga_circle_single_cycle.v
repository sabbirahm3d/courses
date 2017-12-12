`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date:    18:33:21 09/16/2017
// Design Name:
// Module Name:    vga_circle
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
//////////////////////////////////////////////////////////////////////////////

module vga_circle(
        input wire clk,
        input wire reset,
        input wire [9:0] pos_h,
        input wire [9:0] pos_v,
        input wire blank,
        output reg red,
        output reg green,
        output reg blue
    );

    // additional intermediate logic signal wires
    wire in_circle;  // high only when over circle
    wire [9:0] x, y;  // traditional cartesean coordinates

    assign x = pos_h;
    assign y = 480 - pos_v;

    single_cycle_comp single_cycle_uut(
        .clk(clk),
        .reset(reset),
        .x(pos_h),
        .y(480 - pos_v),
        .in_circle(in_circle)
    );

    always @(posedge clk) begin

        // cyan circle on black background
        red <= ~in_circle & blank;
        green <= in_circle & ~blank;
        blue <= in_circle & ~blank;

    end

endmodule
