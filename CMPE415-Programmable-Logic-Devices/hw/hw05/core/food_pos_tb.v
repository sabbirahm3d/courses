`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:05:21 10/22/2017 
// Design Name: 
// Module Name:    food_pos
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

module food_pos_tb;

    reg enable;
    reg clk;
    reg clr;
    wire [8:0] food_x, food_y;

    food_pos food_pos_instance(
        .clk(clk),
        .enable(enable), .clr(clr),
        .food_x(food_x), .food_y(food_y)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        // enable the module
        enable = 1;
        #10;

        #30
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        #30
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        #30
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        #80
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        #10;
        clr = 0;

        #80
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        enable = 1;
        #20
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

        clr = 0;
        #10;

        #80
        $monitor("%0t food_x:%d food_y:%d", $time, food_x, food_y);

    end

    initial #200000 $finish;

endmodule