`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:05:21 10/22/2017 
// Design Name: 
// Module Name:    food_vga 
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
module food_vga(
        input wire clk,
        input wire enable,
        input wire clr,
        input wire bite,
        input wire start,
        input wire [8:0] x,
        input wire [8:0] y,
        output reg food
    );

    parameter WIDTH = 20;
    parameter HEIGHT = 100;
    parameter X_LEFT = 320;
    parameter Y_BOTTOM = 240;

    // additional intermediate logic signal wires
    wire food_in_display;  // high only when over rectangle
    reg food_in_x_flag, food_in_y_flag;
    reg food_x, food_y;

    // // combinatorial logic to calculate x, y coordinate system
    // assign x = pos_h;
    // assign y = 480 - pos_v;

    // combinatorial logic to decide if present pixel is over a desired 
    // rectangle region
    // assign food_in_display = x >= (X_LEFT) && x < (X_LEFT + WIDTH) && 
    //                     y >= (Y_BOTTOM) && y < (Y_BOTTOM + HEIGHT);


    always@(clk) begin

        if (bite) begin
            food_x = x;
            food_y = y;
        end
        if (~start) begin
            food_x = x;
            food_y = y;
        end
        
     end
    
    always @(posedge clk) begin
        food_in_x_flag <= (xCount > food_x && xCount < (food_x + 10));
        food_in_y_flag <= (yCount > food_y && yCount < (food_y + 10));
        food = food_in_x_flag && food_in_y_flag;
    end


endmodule
