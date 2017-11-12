`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:47:45 10/27/2017 
// Design Name: 
// Module Name:    collision 
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
module collision(
        input wire clk,
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
        output reg bite, output reg dead
    );

    // maximum height and width of the game area
    parameter GRID_WIDTH = 500;
    parameter GRID_HEIGHT = 400;

    always @(posedge clk) begin

        // if the head and the food positions overlap
        bite <= ~((snake_x0 ^ food_x) && (snake_y0 ^ food_y));

        // if the head and any of its segment or the fence positions overlap
        dead <= (
            ((snake_x0 == snake_x3)  && (snake_y0 == snake_y3))  ||
            ((snake_x0 == snake_x4)  && (snake_y0 == snake_y4))  ||
            ((snake_x0 == snake_x5)  && (snake_y0 == snake_y5))  ||
            ((snake_x0 == snake_x6)  && (snake_y0 == snake_y6))  ||
            ((snake_x0 == snake_x7)  && (snake_y0 == snake_y7))  ||
            ((snake_x0 == snake_x8)  && (snake_y0 == snake_y8))  ||
            ((snake_x0 == snake_x9)  && (snake_y0 == snake_y9))  ||
            ((snake_x0 == snake_x10) && (snake_y0 == snake_y10)) ||
            ((snake_x0 == snake_x11) && (snake_y0 == snake_y11)) ||
            ((snake_x0 == snake_x12) && (snake_y0 == snake_y12)) ||
            ((snake_x0 == snake_x13) && (snake_y0 == snake_y13)) ||
            ((snake_x0 == snake_x14) && (snake_y0 == snake_y14)) ||
            ((snake_x0 == snake_x15) && (snake_y0 == snake_y15)) ||
            ((snake_x0 == snake_x16) && (snake_y0 == snake_y16)) ||
            ((snake_x0 == snake_x17) && (snake_y0 == snake_y17)) ||
            ((snake_x0 == snake_x18) && (snake_y0 == snake_y18)) ||
            ((snake_x0 == snake_x19) && (snake_y0 == snake_y19)) ||
            ((snake_x0 == snake_x20) && (snake_y0 == snake_y20)) ||
            ((snake_x0 == snake_x21) && (snake_y0 == snake_y21)) ||
            ((snake_x0 == snake_x22) && (snake_y0 == snake_y22)) ||
            ((snake_x0 == snake_x23) && (snake_y0 == snake_y23)) ||
            ((snake_x0 == snake_x24) && (snake_y0 == snake_y24)) ||
            ((snake_x0 == snake_x25) && (snake_y0 == snake_y25)) ||
            ((snake_x0 == snake_x26) && (snake_y0 == snake_y26)) ||
            ((snake_x0 == snake_x27) && (snake_y0 == snake_y27)) ||
            ((snake_x0 == snake_x28) && (snake_y0 == snake_y28)) ||
            ((snake_x0 == snake_x29) && (snake_y0 == snake_y29)) ||
            ((snake_x0 == snake_x30) && (snake_y0 == snake_y30)) ||
            ((snake_x0 == snake_x31) && (snake_y0 == snake_y31)) ||
            ((snake_x0 == 20) && (snake_y0 == 20)) ||
            ((snake_x0 == GRID_WIDTH) && (snake_y0 == GRID_HEIGHT))
        );

    end

endmodule
