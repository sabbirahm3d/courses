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

    reg clk, reset;
    wire in_circle;  // high only when over circle
    reg [9:0] x, y;  // traditional cartesean coordinates

    multi_cycle_comp multi_cycle_uut(
        .clk(clk),
        .reset(reset),
        .x(x),
        .y(y),
        .in_circle(in_circle)
    );

    always begin

        #20;
        clk <= ~clk;

    end

    initial begin

        clk = 1;
        reset = 1;
        #20;
        reset = 0;
        #20;

        // (360, 240) - inside the circle
        x = 360;
        y = 240;

        #480;

        reset = 1;

        #20;
        reset = 0;

        // (10, 10) - outside the circle
        x = 10;
        y = 10;

    end

    initial #2000 $finish;

endmodule
