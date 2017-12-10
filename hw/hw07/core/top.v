`timescale 1ns / 1ps
`default_nettype none
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
module top(
        input wire CLK_50MHZ,
        input wire RESET,
        output wire VGA_BLUE, 
        output wire VGA_GREEN, 
        output wire VGA_HSYNC, 
        output wire VGA_RED, 
        output wire VGA_VSYNC
   );

    wire [9:0] XLXN_2;
    wire [9:0] XLXN_3;
    wire blank;

    wire CLK0_OUT;  // 50 MHz
    wire CLK2X_OUT;  // 100 MHz


    // Instantiate the module
    dcm dcm_uut(
        .CLKIN_IN(CLK_50MHZ), 
        .RST_IN(RESET), 
        .CLK0_OUT(CLK0_OUT), 
        .CLK2X_OUT(CLK2X_OUT)
    );

    vga_sync  vga_sync_uut(
        .clk(CLK2X_OUT), 
        .blank(blank), 
        .hcount(XLXN_3[9:0]), 
        .hsync(VGA_HSYNC), 
        .pix_clk(), 
        .vcount(XLXN_2[9:0]), 
        .vsync(VGA_VSYNC)
    );

    vga_circle  vga_circle_uut(
        .blank(blank), 
        .clk(CLK0_OUT), 
        .pos_h(XLXN_3[9:0]), 
        .pos_v(XLXN_2[9:0]), 
        .blue(VGA_BLUE), 
        .green(VGA_GREEN), 
        .red(VGA_RED)
    );

endmodule
