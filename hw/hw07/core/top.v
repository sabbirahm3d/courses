`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:21:35 12/10/2017 
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
//////////////////////////////////////////////////////////////////////////////////
module top(CLK_50MHZ, 
           SW0, 
           SW1, 
           SW2, 
           VGA_BLUE, 
           VGA_GREEN, 
           VGA_HSYNC, 
           VGA_RED, 
           VGA_VSYNC);

    input CLK_50MHZ;
    input SW0;
    input SW1;
    input SW2;
   output VGA_BLUE;
   output VGA_GREEN;
   output VGA_HSYNC;
   output VGA_RED;
   output VGA_VSYNC;
   
   wire [9:0] XLXN_2;
   wire [9:0] XLXN_3;
   wire XLXN_4;
   
   vga_sync  XLXI_1 (.clk(CLK_50MHZ), 
                    .blank(XLXN_4), 
                    .hcount(XLXN_3[9:0]), 
                    .hsync(VGA_HSYNC), 
                    .pix_clk(), 
                    .vcount(XLXN_2[9:0]), 
                    .vsync(VGA_VSYNC));
   vga_rectangle  XLXI_2 (.blank(XLXN_4), 
                         .clk(CLK_50MHZ), 
                         .pos_h(XLXN_3[9:0]), 
                         .pos_v(XLXN_2[9:0]), 
                         .SW0(SW0), 
                         .SW1(SW1), 
                         .SW2(SW2), 
                         .blue(VGA_BLUE), 
                         .green(VGA_GREEN), 
                         .red(VGA_RED));
endmodule
