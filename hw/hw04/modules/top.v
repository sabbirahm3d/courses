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
    wire clk;

    // control signals for collision
    wire bite, dead, grow;

    // direction of movement
    wire [1:0] dir;

    // signals for vga_sync
    wire blank, clr;
    wire hsync, vsync;
    wire [9:0] hcount, vcount;
    wire  pix_clk;

    // coordinates for the food
    wire [8:0] food_x, food_y;

    // coordinates for the snake segments
    wire [8:0] snake_x31, snake_x30, snake_x29, snake_x28,
        snake_x27, snake_x26, snake_x25, snake_x24,
        snake_x23, snake_x22, snake_x21, snake_x20,
        snake_x19, snake_x18, snake_x17, snake_x16,
        snake_x15, snake_x14, snake_x13, snake_x12,
        snake_x11, snake_x10, snake_x9, snake_x8,
        snake_x7, snake_x6, snake_x5, snake_x4,
        snake_x3, snake_x2, snake_x1, snake_x0;

    wire [8:0] snake_y31, snake_y30, snake_y29, snake_y28,
        snake_y27, snake_y26, snake_y25, snake_y24,
        snake_y23, snake_y22, snake_y21, snake_y20,
        snake_y19, snake_y18, snake_y17, snake_y16,
        snake_y15, snake_y14, snake_y13, snake_y12,
        snake_y11, snake_y10, snake_y9, snake_y8,
        snake_y7, snake_y6, snake_y5, snake_y4,
        snake_y3, snake_y2, snake_y1, snake_y0;


    pacemaker pacemaker_instance(
        .clk(CLK_50MHZ),
        .boost(grow),
        .p(clk)
    );

    direction direction_instance(
        .east(BTN_EAST),
        .west(BTN_WEST),
        .reset(RESET),
        .clk(clk),
        .dir(dir)
    );

    collision collision_instance(
        .clk(clk),
        .food_x(food_x), .food_y(food_y),
        .snake_x0(snake_x0), .snake_x1(snake_x1),
        .snake_x2(snake_x2), .snake_x3(snake_x3),
        .snake_x4(snake_x4), .snake_x5(snake_x5),
        .snake_x6(snake_x6), .snake_x7(snake_x7),
        .snake_x8(snake_x8), .snake_x9(snake_x9),
        .snake_x10(snake_x10), .snake_x11(snake_x11),
        .snake_x12(snake_x12), .snake_x13(snake_x13),
        .snake_x14(snake_x14), .snake_x15(snake_x15),
        .snake_x16(snake_x16), .snake_x17(snake_x17),
        .snake_x18(snake_x18), .snake_x19(snake_x19),
        .snake_x20(snake_x20), .snake_x21(snake_x21),
        .snake_x22(snake_x22), .snake_x23(snake_x23),
        .snake_x24(snake_x24), .snake_x25(snake_x25),
        .snake_x26(snake_x26), .snake_x27(snake_x27),
        .snake_x28(snake_x28), .snake_x29(snake_x29),
        .snake_x30(snake_x30), .snake_x31(snake_x31),
        .snake_y0(snake_y0), .snake_y1(snake_y1),
        .snake_y2(snake_y2), .snake_y3(snake_y3),
        .snake_y4(snake_y4), .snake_y5(snake_y5),
        .snake_y6(snake_y6), .snake_y7(snake_y7),
        .snake_y8(snake_y8), .snake_y9(snake_y9),
        .snake_y10(snake_y10), .snake_y11(snake_y11),
        .snake_y12(snake_y12), .snake_y13(snake_y13),
        .snake_y14(snake_y14), .snake_y15(snake_y15),
        .snake_y16(snake_y16), .snake_y17(snake_y17),
        .snake_y18(snake_y18), .snake_y19(snake_y19),
        .snake_y20(snake_y20), .snake_y21(snake_y21),
        .snake_y22(snake_y22), .snake_y23(snake_y23),
        .snake_y24(snake_y24), .snake_y25(snake_y25),
        .snake_y26(snake_y26), .snake_y27(snake_y27),
        .snake_y28(snake_y28), .snake_y29(snake_y29),
        .snake_y30(snake_y30), .snake_y31(snake_y31),
        .bite(bite), .dead(dead)
    );

    food_pos food_pos_instance(
        .clk(clk),
        .enable(grow), .clr(clr),
        .food_x(food_x), .food_y(food_y)
    );

    snake_pos snake_pos_instance(
        .clk(clk), .dead(dead), .grow(grow), .dir(dir),
        .snake_x0(snake_x0), .snake_x1(snake_x1),
        .snake_x2(snake_x2), .snake_x3(snake_x3),
        .snake_x4(snake_x4), .snake_x5(snake_x5),
        .snake_x6(snake_x6), .snake_x7(snake_x7),
        .snake_x8(snake_x8), .snake_x9(snake_x9),
        .snake_x10(snake_x10), .snake_x11(snake_x11),
        .snake_x12(snake_x12), .snake_x13(snake_x13),
        .snake_x14(snake_x14), .snake_x15(snake_x15),
        .snake_x16(snake_x16), .snake_x17(snake_x17),
        .snake_x18(snake_x18), .snake_x19(snake_x19),
        .snake_x20(snake_x20), .snake_x21(snake_x21),
        .snake_x22(snake_x22), .snake_x23(snake_x23),
        .snake_x24(snake_x24), .snake_x25(snake_x25),
        .snake_x26(snake_x26), .snake_x27(snake_x27),
        .snake_x28(snake_x28), .snake_x29(snake_x29),
        .snake_x30(snake_x30), .snake_x31(snake_x31),
        .snake_y0(snake_y0), .snake_y1(snake_y1),
        .snake_y2(snake_y2), .snake_y3(snake_y3),
        .snake_y4(snake_y4), .snake_y5(snake_y5),
        .snake_y6(snake_y6), .snake_y7(snake_y7),
        .snake_y8(snake_y8), .snake_y9(snake_y9),
        .snake_y10(snake_y10), .snake_y11(snake_y11),
        .snake_y12(snake_y12), .snake_y13(snake_y13),
        .snake_y14(snake_y14), .snake_y15(snake_y15),
        .snake_y16(snake_y16), .snake_y17(snake_y17),
        .snake_y18(snake_y18), .snake_y19(snake_y19),
        .snake_y20(snake_y20), .snake_y21(snake_y21),
        .snake_y22(snake_y22), .snake_y23(snake_y23),
        .snake_y24(snake_y24), .snake_y25(snake_y25),
        .snake_y26(snake_y26), .snake_y27(snake_y27),
        .snake_y28(snake_y28), .snake_y29(snake_y29),
        .snake_y30(snake_y30), .snake_y31(snake_y31)
    );

    vga_sync vga_sync_instance(
        .clk(clk),
        .hsync(hsync), .vsync(vsync),
        .hcount(hcount), .vcount(vcount),
        .pix_clk(pix_clk),
        .blank(blank)
    );

    vga_layout layout(
        .clk(clk), .blank(blank),
        .pos_h(hsync), .pos_v(vsync),
        .food_x(food_x), .food_y(food_y),
        .snake_x0(snake_x0), .snake_x1(snake_x1),
        .snake_x2(snake_x2), .snake_x3(snake_x3),
        .snake_x4(snake_x4), .snake_x5(snake_x5),
        .snake_x6(snake_x6), .snake_x7(snake_x7),
        .snake_x8(snake_x8), .snake_x9(snake_x9),
        .snake_x10(snake_x10), .snake_x11(snake_x11),
        .snake_x12(snake_x12), .snake_x13(snake_x13),
        .snake_x14(snake_x14), .snake_x15(snake_x15),
        .snake_x16(snake_x16), .snake_x17(snake_x17),
        .snake_x18(snake_x18), .snake_x19(snake_x19),
        .snake_x20(snake_x20), .snake_x21(snake_x21),
        .snake_x22(snake_x22), .snake_x23(snake_x23),
        .snake_x24(snake_x24), .snake_x25(snake_x25),
        .snake_x26(snake_x26), .snake_x27(snake_x27),
        .snake_x28(snake_x28), .snake_x29(snake_x29),
        .snake_x30(snake_x30), .snake_x31(snake_x31),
        .snake_y0(snake_y0), .snake_y1(snake_y1),
        .snake_y2(snake_y2), .snake_y3(snake_y3),
        .snake_y4(snake_y4), .snake_y5(snake_y5),
        .snake_y6(snake_y6), .snake_y7(snake_y7),
        .snake_y8(snake_y8), .snake_y9(snake_y9),
        .snake_y10(snake_y10), .snake_y11(snake_y11),
        .snake_y12(snake_y12), .snake_y13(snake_y13),
        .snake_y14(snake_y14), .snake_y15(snake_y15),
        .snake_y16(snake_y16), .snake_y17(snake_y17),
        .snake_y18(snake_y18), .snake_y19(snake_y19),
        .snake_y20(snake_y20), .snake_y21(snake_y21),
        .snake_y22(snake_y22), .snake_y23(snake_y23),
        .snake_y24(snake_y24), .snake_y25(snake_y25),
        .snake_y26(snake_y26), .snake_y27(snake_y27),
        .snake_y28(snake_y28), .snake_y29(snake_y29),
        .snake_y30(snake_y30), .snake_y31(snake_y31),
        .red(VGA_RED), .green(VGA_GREEN), .blue(VGA_BLUE)
    );

endmodule
