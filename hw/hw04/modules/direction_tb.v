`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////
module direction_tb;

    reg RESET, BTN_EAST, BTN_WEST;
    reg clk;
    wire [1:0] dir;

    direction direction_instance(
        .east(BTN_EAST),
        .west(BTN_WEST),
        .reset(RESET),
        .clk(clk),
        .dir(dir)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;
        #10  // shuffle the enable as well
        RESET = ~RESET;

    end

    initial begin

        clk <= 0;
        RESET = 1;
        #10;
        RESET = 0;

        #30;
        BTN_WEST = 0;
        BTN_EAST = 1;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 0;
        BTN_EAST = 1;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 0;
        BTN_EAST = 1;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 0;
        BTN_EAST = 1;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 0;
        BTN_EAST = 1;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 1;
        BTN_EAST = 0;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

        #30;
        BTN_WEST = 1;
        BTN_EAST = 0;

        $display("%0t %b %b %d", $time, BTN_EAST, BTN_WEST, dir);

    end

    initial #2000 $finish;

endmodule
