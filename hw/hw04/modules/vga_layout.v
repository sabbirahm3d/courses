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
        input wire blank,
        output reg red,
        output reg green,
        output reg blue
    );

    parameter WIDTH = 598; 
    parameter HIEGHT = 456; 
    parameter X_LEFT = 10; 
    parameter Y_BOTTOM = 10; 

    // additional intermediate logic signal wires 
    wire flag_on_fence;  // high only when over rectangle 
    wire flag_on_snake;
    wire flag_on_food;
    wire [9:0] x, y;  // traditional cartesean coordinates, (left, bottom)=(0,0)

    //combinatorial logic to calculate x,y coordinate system 
    assign x = pos_h; 
    assign y = 480 - pos_v; 

    // combinatorial logic to decide if present pixel is over a desired 
    // rectange region 
    assign flag_on_fence = (
        x >= (X_LEFT) && 
        x <  (X_LEFT + WIDTH)   && 
        y >= (Y_BOTTOM)         && 
        y <  (Y_BOTTOM + HIEGHT)
    );

    assign flag_on_snake = (x >= 299 && x < 322 && y >= 228 && y < 240);
    assign flag_on_food = (x >= 200 && x < 223 && y >= 200 && y < 212);

   //combinatorial logic and registers (seqential logic) that load on rising
   // clock edge 
   always @(posedge clk) begin 

        blue <=  ~flag_on_fence & ~blank; 
        red <= flag_on_food & ~blank;
        green <= flag_on_snake & ~blank;

    end

endmodule
