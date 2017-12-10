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

    // combinatorial logic to calculate x,y coordinate system
    assign x = pos_h;
    assign y = 480 - pos_v;

    single_cycle_comp single_cycle_uut(
        .clk(clk),
        .x(x), .y(y),
        .in_circle(in_circle)
    );

    // combinatorial logic and registers (sequential logic) that load on rising
    // clock edge
    always @(posedge clk) begin

        red <= ~in_circle & blank;
        blue <= ~in_circle & blank;
        green <= ~in_circle & blank;

    end

endmodule
