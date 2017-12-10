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
    wire flag_on_rect;  // high only when over rectangle
    wire [9:0] x, y;  // traditional cartesean coordinates

    // combinatorial logic to calculate x,y coordinate system
    assign x = pos_h;
    assign y = 480 - pos_v;

    single_cycle_comp single_cycle_uut(
        .clk(clk),
        .x(x), .y(y),
        .flag_on_rect(flag_on_rect)
    );

    // combinatorial logic and registers (seqential logic) that load on rising
    // clock edge
    always @(posedge clk) begin

        red <= ~flag_on_rect & blank;
        blue <= ~flag_on_rect & blank;
        green <= ~flag_on_rect & blank;

    end

endmodule
