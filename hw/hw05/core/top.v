`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:35:41 10/26/2017 
// Design Name: 
// Module Name:    top 
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
module top(
        input wire CLK_50MHZ,
        input wire RESET,
        input wire BTN_EAST,
        input wire BTN_WEST,
        output wire VGA_RED,
        output wire VGA_GREEN,
        output wire VGA_BLUE
    );

    // clock buffered by pacemaker
    // wire clk;

    // control signals for collision
    wire bite, die, grow, enable, rst, rst_size;

    // direction of movement
    wire [1:0] dir;

    // signals for vga_sync
    wire blank, clr;
    wire hsync, vsync;
    wire [9:0] hcount, vcount;
    wire  pix_clk;

    // coordinates for the food
    wire [4:0] food_x, food_y;
    // wire [4:0] obj_x, obj_y;

    // coordinates for the snake segments
    wire [4:0] snake_x4, snake_x3, snake_x2, snake_x1, head_x;
    wire [4:0] snake_y4, snake_y3, snake_y2, snake_y1, head_y;

    pacemaker pacemaker_instance(
        .clk(CLK_50MHZ),
        .boost(grow),
        .p(enable)
    );

    direction direction_instance(
        .east(BTN_EAST),
        .west(BTN_WEST),
        .reset(RESET),
        .clk(CLK_50MHZ),
        .dir(dir)
    );

    game_state game_state_instance(
        .clk(CLK_50MHZ), .rst(rst), .enable(enable),
        .head_x(head_x), .head_y(head_y), 
        .snake_x1(snake_x1), .snake_y1(snake_y1), 
        .snake_x2(snake_x2), .snake_y2(snake_y2),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4),
        .food_x(food_x), .food_y(food_y),
        .grow(grow), .die(die), .rst_size(rst_size)
    );

    food_pos food_pos_instance(
        .clk(CLK_50MHZ),
        .enable(grow), .clr(clr),
        .food_x(food_x), .food_y(food_y)
    );

    snake_pos snake_pos_instance(
        .clk(CLK_50MHZ),
        .grow(grow), .die(die),
        .enable(enable), .rst(rst_size),
        .dir(dir),
        .head_x(head_x), .head_y(head_y), 
        .snake_x1(snake_x1), .snake_y1(snake_y1), 
        .snake_x2(snake_x2), .snake_y2(snake_y2),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4)
    );

    vga_sync vga_sync_instance(
        .clk(CLK_50MHZ),
        .hsync(hsync), .vsync(vsync),
        .hcount(hcount), .vcount(vcount),
        .pix_clk(pix_clk),
        .blank(blank)
    );

    vga_layout layout(
        .clk(CLK_50MHZ), .blank(blank),
        .pos_h(hsync), .pos_v(vsync),
        .food_x(food_x), .food_y(food_y),
        .head_x(head_x), .head_y(head_y), 
        .snake_x1(snake_x1), .snake_y1(snake_y1), 
        .snake_x2(snake_x2), .snake_y2(snake_y2),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4),
        .red(VGA_RED), .green(VGA_GREEN), .blue(VGA_BLUE)
    );

endmodule
