`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:05:50 10/22/2017 
// Design Name: 
// Module Name:    snake_pos_tb 
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
module snake_pos_tb;

    reg sys_clk, clk, grow, die;

    // direction
    reg [1:0] dir;

    // coordinates for the snake segments
    wire [8:0] snake_x4, snake_x3, snake_x2, snake_x1, head_x;
    wire [8:0] snake_y4, snake_y3, snake_y2, snake_y1, head_y;


    pacemaker pacemaker_instance(
        .clk(sys_clk),
        .boost(grow),
        .p(clk)
    );

    snake_pos snake_pos_instance(
        .clk(clk), .die(die), .grow(grow), .enable(enable),
        .dir(dir),
        .head_x(head_x), .head_y(head_y), 
        .snake_x1(snake_x1), .snake_y1(snake_y1), 
        .snake_x2(snake_x2), .snake_y2(snake_y2),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        clk = 0;

        #10;

        // move snake right
        dir = 0;
        grow = 0;
        die = 0;

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);


        #70

        // grow the snake
        grow = 1;
        #30
        grow = 0;

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);


        #100
        // move the snake up
        dir = 3;

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);


        #100
        // move the snake right
        dir = 0;

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);


        #100
        // kill the snake
        dir = 1;
        die = 1;

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);


        #100
        // snake is dead and therefore will not move

        $display("(%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)",
        snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1,
        snake_y1, head_x, head_y);

    end

    initial #1100 $finish;

endmodule
