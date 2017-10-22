`timescale 1ns / 1ps
`default_nettype none
///////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////

module vga_border(
        input wire clk, 
        output vga_h_sync, 
        output vga_v_sync, 
        output reg inDisplayArea, 
        output reg [9:0] x, 
        output reg [8:0] y
    );

    wire x_max = (x == 10'h2FF);
    reg vga_HS, vga_VS;

    always @(posedge clk) begin
        if (x_max) begin
            x <= 0;
        end else begin
            x <= x + 1;
        end
    end

    always @(posedge clk) begin
        if (x_max) begin
            y <= y + 1;
        end
    end

    always @(posedge clk) begin
        // change this value to move the display horizontally
        vga_HS <= (x[9:4] == 6'h2D);
        // change this value to move the display vertically
        vga_VS <= (y == 500);
    end

    always @(posedge clk) begin
        if (inDisplayArea == 0) begin
            inDisplayArea <= (x_max) && (y < 480);
        end else begin
            inDisplayArea <= !(x == 639);
        end
    end

    assign vga_h_sync = ~vga_HS;
    assign vga_v_sync = ~vga_VS;

endmodule
