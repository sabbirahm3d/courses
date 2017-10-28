`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////
module snake_pos_tb;

    reg sys_clk, clk, grow;
    reg [1:0] dir;
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

    pacemaker pacemaker_instance(
        .clk(sys_clk),
        .boost(grow),
        .p(clk)
    );

    snake_pos snake_pos_instance(
        .clk(sys_clk),
        .dir(dir),
        .grow(grow),
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
        sys_clk <= ~sys_clk;

    end

    initial begin

        sys_clk = 0;
        #10;
        dir = 0;
        grow = 0;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);


        #70
        grow = 1;
        dir = 3;
        #30
        grow = 0;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);

        #200
        dir = 1;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);

        $display("heheheh%d jjjjj %b", 18^19, 18^18);

    end

    initial #500000 $finish;

endmodule
