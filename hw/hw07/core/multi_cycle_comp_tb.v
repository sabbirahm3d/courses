`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:49:02 12/10/2017 
// Design Name: 
// Module Name:    multi_cycle_comp_tb 
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
module multi_cycle_comp_tb;

    reg clk;
    wire in_circle;  // high only when over circle
    reg [9:0] x, y;  // traditional cartesean coordinates

    multi_cycle_comp multi_cycle_uut(
        .clk(clk),
        .x(x), .y(y),
        .in_circle(in_circle)
    );

    always begin

        #20;
        clk <= ~clk;

    end

    initial begin

        clk = 0;

        #20;

        x = 1000;
        y = 1000;

        #80;

        x = 10;
        y = 10;

    end

    initial #2000 $finish;

endmodule
