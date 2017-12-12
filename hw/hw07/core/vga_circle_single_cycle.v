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

module vga_circle_single_cycle(
        input wire clk,
        input wire reset,
        input wire [9:0] pos_h,
        input wire [9:0] pos_v,
        input wire blank,
        output reg red,
        output reg green,
        output reg blue
    );

    wire in_circle;  // high only when over circle

    single_cycle_comp single_cycle_uut(
        .clk(clk),
        .reset(reset),
        .x(pos_h),
        .y(480 - pos_v),
        .in_circle(in_circle)
    );

    always @(posedge clk) begin

        // yellow circle on black background
        red <= flag_on_rect & ~blank;
        green <= flag_on_rect & ~blank;
        blue <= ~flag_on_rect & blank;

    end

endmodule
