`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:00:00 09/17/2017 
// Design Name: 
// Module Name:    vga_layout 
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
module vga_layout(
        input wire clk, input wire blank,
        input wire [9:0] pos_h, input wire [9:0] pos_v,
        input wire [8:0] food_x, input wire [8:0] food_y,
        input wire [8:0] snake_x0, input wire [8:0] snake_x1,
        input wire [8:0] snake_x2, input wire [8:0] snake_x3,
        input wire [8:0] snake_x4, input wire [8:0] snake_x5,
        input wire [8:0] snake_x6, input wire [8:0] snake_x7,
        input wire [8:0] snake_x8, input wire [8:0] snake_x9,
        input wire [8:0] snake_x10, input wire [8:0] snake_x11,
        input wire [8:0] snake_x12, input wire [8:0] snake_x13,
        input wire [8:0] snake_x14, input wire [8:0] snake_x15,
        input wire [8:0] snake_x16, input wire [8:0] snake_x17,
        input wire [8:0] snake_x18, input wire [8:0] snake_x19,
        input wire [8:0] snake_x20, input wire [8:0] snake_x21,
        input wire [8:0] snake_x22, input wire [8:0] snake_x23,
        input wire [8:0] snake_x24, input wire [8:0] snake_x25,
        input wire [8:0] snake_x26, input wire [8:0] snake_x27,
        input wire [8:0] snake_x28, input wire [8:0] snake_x29,
        input wire [8:0] snake_x30, input wire [8:0] snake_x31,
        input wire [8:0] snake_y0, input wire [8:0] snake_y1,
        input wire [8:0] snake_y2, input wire [8:0] snake_y3,
        input wire [8:0] snake_y4, input wire [8:0] snake_y5,
        input wire [8:0] snake_y6, input wire [8:0] snake_y7,
        input wire [8:0] snake_y8, input wire [8:0] snake_y9,
        input wire [8:0] snake_y10, input wire [8:0] snake_y11,
        input wire [8:0] snake_y12, input wire [8:0] snake_y13,
        input wire [8:0] snake_y14, input wire [8:0] snake_y15,
        input wire [8:0] snake_y16, input wire [8:0] snake_y17,
        input wire [8:0] snake_y18, input wire [8:0] snake_y19,
        input wire [8:0] snake_y20, input wire [8:0] snake_y21,
        input wire [8:0] snake_y22, input wire [8:0] snake_y23,
        input wire [8:0] snake_y24, input wire [8:0] snake_y25,
        input wire [8:0] snake_y26, input wire [8:0] snake_y27,
        input wire [8:0] snake_y28, input wire [8:0] snake_y29,
        input wire [8:0] snake_y30, input wire [8:0] snake_y31,
        output reg red, output reg green, output reg blue
    );

    parameter GRID_WIDTH = 500;
    parameter GRID_HEIGHT = 400;
    parameter FENCE_WIDTH = 10;
    parameter PIXEL_WIDTH = 20;

    // additional intermediate logic signal wires 
    wire flag_on_fence;  // high only when over rectangle 
    wire flag_on_snake;
    wire flag_on_food;
    // traditional cartesean coordinates, (left, bottom)=(0,0)
    wire [9:0] x, y;

    // combinatorial logic to calculate x,y coordinate system 
    assign x = pos_h;
    assign y = 480 - pos_v;

    // combinatorial logic to decide if present pixel is over a desired 
    // rectange region 
    assign flag_on_fence = (
        (x >= (FENCE_WIDTH) && x < (FENCE_WIDTH + GRID_WIDTH)) &&
        (y >= (FENCE_WIDTH) && y < (FENCE_WIDTH + GRID_HEIGHT))
    );

    // head_x, head_y
    assign flag_on_snake = (
        (x >= snake_x0 && x < (snake_x0 + PIXEL_WIDTH)) &&
        (y >= snake_y0 && y < (snake_y0 + PIXEL_WIDTH))
    );

    // food_x, food_y
    assign flag_on_food = (
        (x >= food_x && x < (food_x + PIXEL_WIDTH)) &&
        (y >= food_y && y < (food_y + PIXEL_WIDTH))
    );

   // combinatorial logic and registers (seqential logic) that load on rising
   // clock edge 
   always @(posedge clk) begin 

        blue <=  ~flag_on_fence & ~blank;
        red <= flag_on_food & ~blank;
        green <= flag_on_snake & ~blank;

    end

endmodule
