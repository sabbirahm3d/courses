`timescale 1ns / 1ps
///////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date:    18:33:21 09/16/2017
// Design Name:
// Module Name:    vga_rectangle
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
///////////////////////////////////////////////////////////////////////////////
module vga_rectangle(
            output reg red,
            output reg green,
            output reg blue,
            input [9:0] pos_h,
            input [9:0] pos_v,
            input blank,
            input clk,
            input SW0,
            input SW1,
            input SW2
        );

    parameter WIDTH = 20;
    parameter HEIGHT = 100;
    parameter X_LEFT = 320;
    parameter Y_BOTTOM = 240;

    // additional intermediate logic signal wires
    wire flag_on_rect;  // high only when over rectangle
    wire [9:0] x, y;  // traditional cartesean coordinates

    // combinatorial logic to calculate x,y coordinate system
    assign x = pos_h;
    assign y = 480 - pos_v;

    // combinatorial logic to decide if present pixel is over a desired 
    // rectangle region
    assign flag_on_rect = x >= (X_LEFT) && x < (X_LEFT + WIDTH) && 
                            y >= (Y_BOTTOM) && y < (Y_BOTTOM + HEIGHT);

    // combinatorial logic and registers (seqential logic) that load on rising
    // clock edge
    always @(posedge clk) begin

        if (~SW2 && ~SW1 && SW0) begin
            red <= ~flag_on_rect & ~blank;
            green <= ~flag_on_rect & ~blank;
        end else if (~SW2 && SW1 && ~SW0) begin
            blue <= ~flag_on_rect & ~blank;
            green <= ~flag_on_rect & ~blank;
        end else if (SW2 && ~SW1 && ~SW2) begin
            red <= ~flag_on_rect & ~blank;
            blue <= ~flag_on_rect & ~blank;
        end else begin
            red <= flag_on_rect & ~blank;
            blue <= flag_on_rect & ~blank;
            green <= flag_on_rect & ~blank;
        end

    end

endmodule
