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
        input wire blank, input wire [9:0] pos_h, input wire [9:0] pos_v,
        input wire [8:0] food_x, input wire [8:0] food_y,
        input wire [4:0] head_x, input wire [4:0] head_y,
        input wire [4:0] snake_x1, input wire [4:0] snake_y1,
        input wire [4:0] snake_x2, input wire [4:0] snake_y2,
        input wire [4:0] snake_x3, input wire [4:0] snake_y3,
        input wire [4:0] snake_x4, input wire [4:0] snake_y4,
        output reg red, output reg green, output reg blue
    );

    parameter GRID_WIDTH = 320;
    parameter GRID_HEIGHT = 240;
    parameter FENCE_WIDTH = 10;
    parameter PIXEL_WIDTH = 20;

    // high only when over rectangles
    wire flag_on_fence;  // fence
    wire flag_on_lvl1_obs, flag_on_lvl2_obs, flag_on_lvl3_obs;  // obstacles
    wire flag_on_head, flag_on_body1, flag_on_body2, flag_on_body3,
        flag_on_body4;  // snake segments
    wire flag_on_food;  // food

    // traditional cartesean coordinates, (left, bottom)=(0, 0)
    wire [9:0] x, y;

    // combinatorial logic to calculate x,y coordinate system 
    assign x = pos_h;
    assign y = 480 - pos_v;

    // combinatorial logic to decide if present pixel is over a desired 
    // rectange regions

    // fence
    assign flag_on_fence = (
        (x >= (FENCE_WIDTH) && x < (FENCE_WIDTH + GRID_WIDTH)) &&
        (y >= (FENCE_WIDTH) && y < (FENCE_WIDTH + GRID_HEIGHT))
    );

    // head_x, head_y
    assign flag_on_head = (
        (x >= head_x && x < (head_x + PIXEL_WIDTH)) &&
        (y >= head_y && y < (head_y + PIXEL_WIDTH))
    );

    // snake_x1, snake_y1
    assign flag_on_body1 = (
        (x >= snake_x1 && x < (snake_x1 + PIXEL_WIDTH)) &&
        (y >= snake_y1 && y < (snake_y1 + PIXEL_WIDTH))
    );

    // snake_x2, snake_y2
    assign flag_on_body2 = (
        (x >= snake_x2 && x < (snake_x2 + PIXEL_WIDTH)) &&
        (y >= snake_y2 && y < (snake_y2 + PIXEL_WIDTH))
    );

    // snake_x3, snake_y3
    assign flag_on_body3 = (
        (x >= snake_x3 && x < (snake_x3 + PIXEL_WIDTH)) &&
        (y >= snake_y3 && y < (snake_y3 + PIXEL_WIDTH))
    );

    // snake_x4, snake_y4
    assign flag_on_body4 = (
        (x >= snake_x4 && x < (snake_x4 + PIXEL_WIDTH)) &&
        (y >= snake_y4 && y < (snake_y4 + PIXEL_WIDTH))
    );

    // food_x, food_y
    assign flag_on_food = (
        (x >= food_x && x < (food_x + PIXEL_WIDTH)) &&
        (y >= food_y && y < (food_y + PIXEL_WIDTH))
    );

    // obstacles of level 1
    assign flag_on_lvl1_obs = (
        (x >= 30 && x < 120) &&
        (y >= 25 && y < 70)
    );

    // obstacles of level 2
    assign flag_on_lvl2_obs = (
        (x >= 130 && x < 220) &&
        (y >= 75 && y < 120)
    );

    // obstacles of level 3
    assign flag_on_lvl3_obs = (
        (x >= 230 && x < 320) &&
        (y >= 125 && y < 170)
    );

    always @(posedge clk) begin

        // color food as red
        red <= (flag_on_food & ~blank);

        // color all snake segments as green
        green <= (
            (flag_on_head ||
            flag_on_body1 || flag_on_body2 ||
            flag_on_body3 || flag_on_body4) & ~blank
        );

        // add blue to snake head for cyan, color fence as blue
        blue <=  (
            (flag_on_head || ~flag_on_fence) & ~blank
        );

        if (level > 1) begin

            // color level 1 obstacles as magenta
            red <= red || flag_on_lvl1_obs;
            blue <= blue || flag_on_lvl1_obs;

            if (level > 2) begin

                // color level 2 obstacles as magenta
                red <= red || flag_on_lvl2_obs;
                blue <= blue || flag_on_lvl2_obs;

                if (level == 3) begin

                    // color level 3 obstacles as magenta
                    red <= red || flag_on_lvl3_obs;
                    blue <= blue || flag_on_lvl3_obs;

                end  // level 3

            end  // level 2

        end  // level 1

    end  // always block

endmodule
