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
        input wire [4:0] head_x, input wire [4:0] head_y,
        input wire [4:0] snake_x3, input wire [4:0] snake_y3,
        input wire [4:0] snake_x4, input wire [4:0] snake_y4,
        input wire [4:0] obj_x, input wire [4:0] obj_y,
        output reg is_collision
    );

    // maximum height and width of the game area
    parameter GRID_WIDTH = 500;
    parameter GRID_HEIGHT = 400;

    always @(posedge clk) begin

        // if the head and any of its segment or the fence positions overlap
        is_collision <= (
            ((head_x == obj_x) && (head_y == obj_y)) ||
            ((head_x == snake_x3) && (head_y == snake_y3))  ||
            ((head_x == snake_x4) && (head_y == snake_y4))  ||
            ((head_x == 20) && (head_y == 20)) ||
            ((head_x == GRID_WIDTH) && (head_y == GRID_HEIGHT))
        );

    end

endmodule
