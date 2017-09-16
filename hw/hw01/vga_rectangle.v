`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:33:21 09/16/2017 
// Design Name: 
// Module Name:    vga_rectangle 
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
module vga_rectangle(
    output reg red,
    output reg green,
    output reg blue,
    input [9:0] pos_h,
    input [9:0] pos_v,
    input blank,
    input clk
    );

    parameter WIDTH    =  20; 
    parameter HIEGHT   = 100; 
    parameter X_LEFT   = 320; 
    parameter Y_BOTTOM = 240; 
 
    //addinal intermediate logic signal wires 
    wire flag_on_rect;   //high only when over rectangle 
    wire [9:0] x,y;      //traditional cartesean coordinates, (left, bottom)=(0,0) 
 
    //combinatorial logic to calculate x,y coordinate system 
    assign x = pos_h; 
    assign y = 480 - pos_v; 
 
    //combinatorial logic to decide if present pixel is over a desired rectange region 
    assign flag_on_rect = x >= (X_LEFT)           && 
                          x <  (X_LEFT + WIDTH)   && 
                          y >= (Y_BOTTOM)         && 
                          y <  (Y_BOTTOM + HIEGHT); 
 
   //combinatorial logic and registers (seqential logic) that load on rising clock edge 
   always @(posedge clk) begin 
            red   <=  flag_on_rect & ~blank; 
            green <= ~flag_on_rect & ~blank; 
        blue  <=  flag_on_rect & ~blank; 
    end

endmodule
