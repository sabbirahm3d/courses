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
        input wire clk, input wire [1:0] level,
        input wire blank,
        input wire [9:0] pos_h, input wire [9:0] pos_v,
        input wire [8:0] food_x, input wire [8:0] food_y,
        input wire [4:0] head_x, input wire [4:0] head_y,
        input wire [4:0] snake_x1, input wire [4:0] snake_y1,
        input wire [4:0] snake_x2, input wire [4:0] snake_y2,
        input wire [4:0] snake_x3, input wire [4:0] snake_y3,
        input wire [4:0] snake_x4, input wire [4:0] snake_y4,
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
    wire flag_on_lvl1_obs, flag_on_lvl2_obs, flag_on_lvl3_obs;
    // traditional cartesean coordinates, (left, bottom)=(0, 0)
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
        (x >= head_x && x < (head_x + PIXEL_WIDTH)) &&
        (y >= head_y && y < (head_y + PIXEL_WIDTH))
    );

    // food_x, food_y
    assign flag_on_food = (
        (x >= food_x && x < (food_x + PIXEL_WIDTH)) &&
        (y >= food_y && y < (food_y + PIXEL_WIDTH))
    );

    // food_x, food_y
    assign flag_on_lvl1_obs = (
        (x >= 30 && x < 120) &&
        (y >= 25 && y < 70)
    );

    assign flag_on_lvl2_obs = (
        (x >= 130 && x < 220) &&
        (y >= 75 && y < 120)
    );

    assign flag_on_lvl3_obs = (
        (x >= 230 && x < 320) &&
        (y >= 125 && y < 170)
    );

    // combinatorial logic and registers (seqential logic) that load on rising
    // clock edge 
    always @(posedge clk) begin

        blue <=  ~flag_on_fence & ~blank;
        red <= flag_on_food & ~blank;
        green <= flag_on_snake & ~blank;

    end

endmodule
