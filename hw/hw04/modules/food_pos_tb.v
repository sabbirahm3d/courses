`timescale 1ns / 1ps
`default_nettype none
///////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:43:21 10/09/2017 
// Design Name: 
// Module Name:    food_pos_tb 
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
module food_pos_tb;

    reg enable;
    reg clk;
    reg clr;
    wire [8:0] x, y;

    food_pos food_pos_instance(
        .enable(enable),
        .clk(clk),
        .clr(clr),
        .x(x),
        .y(y)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        enable = 1;
        #10;

        #30
        $monitor("%0t x:%d y:%d", $time, x, y);

        #30
        $monitor("%0t x:%d y:%d", $time, x, y);

        #30
        $monitor("%0t x:%d y:%d", $time, x, y);

        #80
        $monitor("%0t x:%d y:%d", $time, x, y);

        // enable = 0;
        // clr = 1;
        #10;
        clr = 0;

        #80
        $monitor("%0t x:%d y:%d", $time, x, y);

        enable = 1;
        #20
        // enable = 0;
        $monitor("%0t x:%d y:%d", $time, x, y);

        clr = 0;
        #10;
        enable = 1;

        #80
        // enable = 0;
        $monitor("%0t x:%d y:%d", $time, x, y);

        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        enable = 1;
        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        #80
        // enable = 0;
        $monitor("%0t x:%d y:%d", $time, x, y);

        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        enable = 1;
        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        #80
        // enable = 0;
        $monitor("%0t x:%d y:%d", $time, x, y);

        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        enable = 1;
        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        #80
        // enable = 0;
        $monitor("%0t x:%d y:%d", $time, x, y);

        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

        enable = 1;
        #20
        $monitor("%0t x:%d y:%d", $time, x, y);

    end

    initial #200000 $finish;

endmodule