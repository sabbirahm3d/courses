`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////
module collision(
        input wire clk,
        input reg [8:0] food_x,
        input reg [8:0] food_y,
        input wire [8:0] snake_x0,
        input wire [8:0] snake_x1,
        input wire [8:0] snake_x2,
        input wire [8:0] snake_x3,
        input wire [8:0] snake_x4,
        input wire [8:0] snake_y0,
        input wire [8:0] snake_y1,
        input wire [8:0] snake_y2,
        input wire [8:0] snake_y3,
        input wire [8:0] snake_y4,
        output reg bite,
        output reg dead
    );

    always @(posedge clk) begin

        bite <= ~((snake_x0 ^ food_x) && (snake_y0 ^ food_y));

    end

endmodule
