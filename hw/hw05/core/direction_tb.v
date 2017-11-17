`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:13:42 10/26/2017 
// Design Name: 
// Module Name:    direction_tb 
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

module direction_tb;

    reg reset, east, west;
    reg clk;
    wire [1:0] dir;

    direction direction_instance(
        .east(east),
        .west(west),
        .reset(reset),
        .clk(clk),
        .dir(dir)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;
        #10  // shuffle the enable as well
        reset = ~reset;

    end

    initial begin

        clk <= 0;
        reset = 1;
        #10;
        reset = 0;

        #30;
        // start by moving right
        west = 0;
        east = 1;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move down
        west = 0;
        east = 1;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move left
        west = 0;
        east = 1;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move up
        west = 0;
        east = 1;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move right again
        west = 0;
        east = 1;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move up again
        west = 1;
        east = 0;

        $display("%0t %b %b %d", $time, east, west, dir);

        #30;
        // move left again
        west = 1;
        east = 0;

        $display("%0t %b %b %d", $time, east, west, dir);

    end

    initial #2000 $finish;

endmodule
