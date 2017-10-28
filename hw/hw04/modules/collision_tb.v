`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:21:54 10/28/2017 
// Design Name: 
// Module Name:    collision_tb 
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
module collision_tb;

    reg clk;
    reg [8:0] food_x, food_y;
    reg [8:0] snake_x0, snake_x1, snake_x2, snake_x3, snake_x4, snake_y0, 
        snake_y1, snake_y2, snake_y3, snake_y4;
    wire bite, dead;

    collision collision_instance(
        .clk(clk),
        .food_x(food_x),
        .food_y(food_y),
        .snake_x0(snake_x0),
        .snake_x3(snake_x3),
        .snake_x4(snake_x4),
        .snake_y0(snake_y0),
        .snake_y3(snake_y3),
        .snake_y4(snake_y4),
        .bite(bite),
        .dead(dead)
    );

    always begin

        #20;
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        #20;

        snake_x0 = 22;
        snake_y0 = 42;

        snake_x1 = snake_x0;
        snake_y1 = snake_y0 + 20;

        snake_x2 = snake_x1 - 20;
        snake_y2 = snake_y1;

        snake_x3 = snake_x2;
        snake_y3 = snake_y2 - 20;

        snake_x4 = snake_x3;
        snake_y4 = snake_y3 - 20;

        food_x = 22;
        food_y = 42;
        #10;
        $display("bite: %b dead: %b", bite, dead);

        food_x = 42;
        food_y = 22;
        #40;
        $display("bite: %b dead: %b", bite, dead);


        snake_x0 = snake_x3;
        snake_y0 = snake_y3;

        snake_x1 = snake_x0;
        snake_y1 = snake_y0;

        snake_x2 = snake_x1;
        snake_y2 = snake_y1;

        snake_x3 = snake_x2;
        snake_y3 = snake_y2;

        snake_x4 = snake_x3;
        snake_y4 = snake_y3;

        food_x = 42;
        food_y = 22;
        #40;
        $display("bite: %b dead: %b", bite, dead);

    end

    initial #2000 $finish;

endmodule
