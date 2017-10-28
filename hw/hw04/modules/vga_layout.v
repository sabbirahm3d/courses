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
        input wire clk,
        input wire [9:0] pos_h,
        input wire [9:0] pos_v,
        input wire [8:0] food_x,
        input wire [8:0] food_y,
        input wire blank,
        output reg red,
        output reg green,
        output reg blue
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

    // assign flag_on_snake = (x >= 299 && x < 322 && y >= 228 && y < 240);

    assign flag_on_snake = (
        ((x >= snake_x0 && x < (snake_x0 + PIXEL_WIDTH)) &&
        ((y >= snake_y0 && y < (snake_y0 + PIXEL_WIDTH)) &&
        ((x >= snake_x1 && x < (snake_x1 + PIXEL_WIDTH)) && snake_x1) &&
        ((y >= snake_y1 && y < (snake_y1 + PIXEL_WIDTH)) && snake_y1) &&
        ((x >= snake_x2 && x < (snake_x2 + PIXEL_WIDTH)) && snake_x2) &&
        ((y >= snake_y2 && y < (snake_y2 + PIXEL_WIDTH)) && snake_y2) &&
        ((x >= snake_x3 && x < (snake_x3 + PIXEL_WIDTH)) && snake_x3) &&
        ((y >= snake_y3 && y < (snake_y3 + PIXEL_WIDTH)) && snake_y3) &&
        ((x >= snake_x4 && x < (snake_x4 + PIXEL_WIDTH)) && snake_x4) &&
        ((y >= snake_y4 && y < (snake_y4 + PIXEL_WIDTH)) && snake_y4)



    );

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
