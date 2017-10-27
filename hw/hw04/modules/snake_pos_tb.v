`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:05:50 10/22/2017 
// Design Name: 
// Module Name:    snake_tb 
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
module snake_pos_tb;

    // reg enable;
    reg clk;
    reg [1:0] interval, dir;
    reg change_dir, grow;
    // wire [8:0] snake_x, snake_y;
    wire [8:0] snake_x0;
    wire [8:0] snake_x1;
    wire [8:0] snake_x2;
    wire [8:0] snake_x3;
    wire [8:0] snake_x4;
    wire [8:0] snake_y0;
    wire [8:0] snake_y1;
    wire [8:0] snake_y2;
    wire [8:0] snake_y3;
    wire [8:0] snake_y4;
    // wire snake_x, snake_y;

    snake_pos snake_pos_instance(
        .clk(clk),
        .dir(dir),
        .interval(interval),
        .change_dir(change_dir),
        .grow(grow),
        // .snake_x(snake_x),
        // .snake_y(snake_y)
        .snake_x0(snake_x0),
        .snake_x1(snake_x1),
        .snake_x2(snake_x2),
        .snake_x3(snake_x3),
        .snake_x4(snake_x4),
        .snake_y0(snake_y0),
        .snake_y1(snake_y1),
        .snake_y2(snake_y2),
        .snake_y3(snake_y3),
        .snake_y4(snake_y4)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        #10;
        change_dir = 1;
        dir = 0;

        $monitor("x4: %d x3: %d x2: %d x1: %d x0 %d y4: %d y3: %d y2: %d y1: %d y0 %d",
         snake_x4, snake_x3, snake_x2, snake_x1, snake_x0, snake_y4, snake_y3, snake_y2, snake_y1, snake_y0);

        #70
        dir = 3;

        $monitor("x4: %d x3: %d x2: %d x1: %d x0 %d y4: %d y3: %d y2: %d y1: %d y0 %d",
         snake_x4, snake_x3, snake_x2, snake_x1, snake_x0, snake_y4, snake_y3, snake_y2, snake_y1, snake_y0);

        #200
        change_dir = 0;

    end

    initial #5000 $finish;

endmodule
