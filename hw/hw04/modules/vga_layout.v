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

    assign flag_on_snake = (
        (   // head_x, head_y
            (x >= snake_x0 && x < (snake_x0 + PIXEL_WIDTH)) &&
            (y >= snake_y0 && y < (snake_y0 + PIXEL_WIDTH))
        )
    );
    //      && (
    //         ((x >= snake_x1 && x < (snake_x1 + PIXEL_WIDTH)) && snake_x1) &&
    //         ((y >= snake_y1 && y < (snake_y1 + PIXEL_WIDTH)) && snake_y1)
    //     ) && (
    //         ((x >= snake_x2 && x < (snake_x2 + PIXEL_WIDTH)) && snake_x2) &&
    //         ((y >= snake_y2 && y < (snake_y2 + PIXEL_WIDTH)) && snake_y2)
    //     ) && (
    //         ((x >= snake_x3 && x < (snake_x3 + PIXEL_WIDTH)) && snake_x3) &&
    //         ((y >= snake_y3 && y < (snake_y3 + PIXEL_WIDTH)) && snake_y3)
    //     ) && (
    //         ((x >= snake_x4 && x < (snake_x4 + PIXEL_WIDTH)) && snake_x4) &&
    //         ((y >= snake_y4 && y < (snake_y4 + PIXEL_WIDTH)) && snake_y4)
    //     ) && (
    //         ((x >= snake_x5 && x < (snake_x5 + PIXEL_WIDTH)) && snake_x5) &&
    //         ((y >= snake_y5 && y < (snake_y5 + PIXEL_WIDTH)) && snake_y5)
    //     ) && (
    //         ((x >= snake_x6 && x < (snake_x6 + PIXEL_WIDTH)) && snake_x6) &&
    //         ((y >= snake_y6 && y < (snake_y6 + PIXEL_WIDTH)) && snake_y6)
    //     ) && (
    //         ((x >= snake_x7 && x < (snake_x7 + PIXEL_WIDTH)) && snake_x7) &&
    //         ((y >= snake_y7 && y < (snake_y7 + PIXEL_WIDTH)) && snake_y7)
    //     ) && (
    //         ((x >= snake_x8 && x < (snake_x8 + PIXEL_WIDTH)) && snake_x8) &&
    //         ((y >= snake_y8 && y < (snake_y8 + PIXEL_WIDTH)) && snake_y8)
    //     ) && (
    //         ((x >= snake_x9 && x < (snake_x9 + PIXEL_WIDTH)) && snake_x9) &&
    //         ((y >= snake_y9 && y < (snake_y9 + PIXEL_WIDTH)) && snake_y9)
    //     ) && (
    //         ((x >= snake_x10 && x < (snake_x10 + PIXEL_WIDTH)) && snake_x10) &&
    //         ((y >= snake_y10 && y < (snake_y10 + PIXEL_WIDTH)) && snake_y10)
    //     ) && (
    //         ((x >= snake_x11 && x < (snake_x11 + PIXEL_WIDTH)) && snake_x11) &&
    //         ((y >= snake_y11 && y < (snake_y11 + PIXEL_WIDTH)) && snake_y11)
    //     ) && (
    //         ((x >= snake_x12 && x < (snake_x12 + PIXEL_WIDTH)) && snake_x12) &&
    //         ((y >= snake_y12 && y < (snake_y12 + PIXEL_WIDTH)) && snake_y12)
    //     ) && (
    //         ((x >= snake_x13 && x < (snake_x13 + PIXEL_WIDTH)) && snake_x13) &&
    //         ((y >= snake_y13 && y < (snake_y13 + PIXEL_WIDTH)) && snake_y13)
    //     ) && (
    //         ((x >= snake_x14 && x < (snake_x14 + PIXEL_WIDTH)) && snake_x14) &&
    //         ((y >= snake_y14 && y < (snake_y14 + PIXEL_WIDTH)) && snake_y14)
    //     ) && (
    //         ((x >= snake_x15 && x < (snake_x15 + PIXEL_WIDTH)) && snake_x15) &&
    //         ((y >= snake_y15 && y < (snake_y15 + PIXEL_WIDTH)) && snake_y15)
    //     ) && (
    //         ((x >= snake_x16 && x < (snake_x16 + PIXEL_WIDTH)) && snake_x16) &&
    //         ((y >= snake_y16 && y < (snake_y16 + PIXEL_WIDTH)) && snake_y16)
    //     ) && (
    //         ((x >= snake_x17 && x < (snake_x17 + PIXEL_WIDTH)) && snake_x17) &&
    //         ((y >= snake_y17 && y < (snake_y17 + PIXEL_WIDTH)) && snake_y17)
    //     ) && (
    //         ((x >= snake_x18 && x < (snake_x18 + PIXEL_WIDTH)) && snake_x18) &&
    //         ((y >= snake_y18 && y < (snake_y18 + PIXEL_WIDTH)) && snake_y18)
    //     ) && (
    //         ((x >= snake_x19 && x < (snake_x19 + PIXEL_WIDTH)) && snake_x19) &&
    //         ((y >= snake_y19 && y < (snake_y19 + PIXEL_WIDTH)) && snake_y19)
    //     ) && (
    //         ((x >= snake_x20 && x < (snake_x20 + PIXEL_WIDTH)) && snake_x20) &&
    //         ((y >= snake_y20 && y < (snake_y20 + PIXEL_WIDTH)) && snake_y20)
    //     ) && (
    //         ((x >= snake_x21 && x < (snake_x21 + PIXEL_WIDTH)) && snake_x21) &&
    //         ((y >= snake_y21 && y < (snake_y21 + PIXEL_WIDTH)) && snake_y21)
    //     ) && (
    //         ((x >= snake_x22 && x < (snake_x22 + PIXEL_WIDTH)) && snake_x22) &&
    //         ((y >= snake_y22 && y < (snake_y22 + PIXEL_WIDTH)) && snake_y22)
    //     ) && (
    //         ((x >= snake_x23 && x < (snake_x23 + PIXEL_WIDTH)) && snake_x23) &&
    //         ((y >= snake_y23 && y < (snake_y23 + PIXEL_WIDTH)) && snake_y23)
    //     ) && (
    //         ((x >= snake_x24 && x < (snake_x24 + PIXEL_WIDTH)) && snake_x24) &&
    //         ((y >= snake_y24 && y < (snake_y24 + PIXEL_WIDTH)) && snake_y24)
    //     ) && (
    //         ((x >= snake_x25 && x < (snake_x25 + PIXEL_WIDTH)) && snake_x25) &&
    //         ((y >= snake_y25 && y < (snake_y25 + PIXEL_WIDTH)) && snake_y25)
    //     ) && (
    //         ((x >= snake_x26 && x < (snake_x26 + PIXEL_WIDTH)) && snake_x26) &&
    //         ((y >= snake_y26 && y < (snake_y26 + PIXEL_WIDTH)) && snake_y26)
    //     ) && (
    //         ((x >= snake_x27 && x < (snake_x27 + PIXEL_WIDTH)) && snake_x27) &&
    //         ((y >= snake_y27 && y < (snake_y27 + PIXEL_WIDTH)) && snake_y27)
    //     ) && (
    //         ((x >= snake_x28 && x < (snake_x28 + PIXEL_WIDTH)) && snake_x28) &&
    //         ((y >= snake_y28 && y < (snake_y28 + PIXEL_WIDTH)) && snake_y28)
    //     ) && (
    //         ((x >= snake_x29 && x < (snake_x29 + PIXEL_WIDTH)) && snake_x29) &&
    //         ((y >= snake_y29 && y < (snake_y29 + PIXEL_WIDTH)) && snake_y29)
    //     ) && (
    //         ((x >= snake_x30 && x < (snake_x30 + PIXEL_WIDTH)) && snake_x30) &&
    //         ((y >= snake_y30 && y < (snake_y30 + PIXEL_WIDTH)) && snake_y30)
    //     ) && (
    //         ((x >= snake_x31 && x < (snake_x31 + PIXEL_WIDTH)) && snake_x31) &&
    //         ((y >= snake_y31 && y < (snake_y31 + PIXEL_WIDTH)) && snake_y31)
    //     )
    // );

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
