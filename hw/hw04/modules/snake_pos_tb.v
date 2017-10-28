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

    reg sys_clk, clk, grow, dead;
    reg [1:0] dir;
    wire [8:0] snake_x31, snake_x30, snake_x29, snake_x28,
        snake_x27, snake_x26, snake_x25, snake_x24,
        snake_x23, snake_x22, snake_x21, snake_x20,
        snake_x19, snake_x18, snake_x17, snake_x16,
        snake_x15, snake_x14, snake_x13, snake_x12,
        snake_x11, snake_x10, snake_x9, snake_x8,
        snake_x7, snake_x6, snake_x5, snake_x4,
        snake_x3, snake_x2, snake_x1, snake_x0

    wire [8:0] snake_y31, snake_y30, snake_y29, snake_y28,
        snake_y27, snake_y26, snake_y25, snake_y24,
        snake_y23, snake_y22, snake_y21, snake_y20,
        snake_y19, snake_y18, snake_y17, snake_y16,
        snake_y15, snake_y14, snake_y13, snake_y12,
        snake_y11, snake_y10, snake_y9, snake_y8,
        snake_y7, snake_y6, snake_y5, snake_y4,
        snake_y3, snake_y2, snake_y1, snake_y0


    pacemaker pacemaker_instance(
        .clk(sys_clk),
        .boost(grow),
        .p(clk)
    );

    snake_pos snake_pos_instance(
        .clk(clk), .dead(dead), .grow(grow), .dir(dir),
        .snake_x0(snake_x0), .snake_x1(snake_x1),
        .snake_x2(snake_x2), .snake_x3(snake_x3),
        .snake_x4(snake_x4), .snake_x5(snake_x5),
        .snake_x6(snake_x6), .snake_x7(snake_x7),
        .snake_x8(snake_x8), .snake_x9(snake_x9),
        .snake_x10(snake_x10), .snake_x11(snake_x11),
        .snake_x12(snake_x12), .snake_x13(snake_x13),
        .snake_x14(snake_x14), .snake_x15(snake_x15),
        .snake_x16(snake_x16), .snake_x17(snake_x17),
        .snake_x18(snake_x18), .snake_x19(snake_x19),
        .snake_x20(snake_x20), .snake_x21(snake_x21),
        .snake_x22(snake_x22), .snake_x23(snake_x23),
        .snake_x24(snake_x24), .snake_x25(snake_x25),
        .snake_x26(snake_x26), .snake_x27(snake_x27),
        .snake_x28(snake_x28), .snake_x29(snake_x29),
        .snake_x30(snake_x30), .snake_x31(snake_x31),
        .snake_y0(snake_y0), .snake_y1(snake_y1),
        .snake_y2(snake_y2), .snake_y3(snake_y3),
        .snake_y4(snake_y4), .snake_y5(snake_y5),
        .snake_y6(snake_y6), .snake_y7(snake_y7),
        .snake_y8(snake_y8), .snake_y9(snake_y9),
        .snake_y10(snake_y10), .snake_y11(snake_y11),
        .snake_y12(snake_y12), .snake_y13(snake_y13),
        .snake_y14(snake_y14), .snake_y15(snake_y15),
        .snake_y16(snake_y16), .snake_y17(snake_y17),
        .snake_y18(snake_y18), .snake_y19(snake_y19),
        .snake_y20(snake_y20), .snake_y21(snake_y21),
        .snake_y22(snake_y22), .snake_y23(snake_y23),
        .snake_y24(snake_y24), .snake_y25(snake_y25),
        .snake_y26(snake_y26), .snake_y27(snake_y27),
        .snake_y28(snake_y28), .snake_y29(snake_y29),
        .snake_y30(snake_y30), .snake_y31(snake_y31)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        #10;
        dir = 0;
        grow = 0;
        dead = 0;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);


        #70
        grow = 1;
        dir = 3;
        #30
        grow = 0;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);

        #100
        dir = 1;
        dead = 1;

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);

        #100

        $display("%0t: (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d), (%0d, %0d)", $time, snake_x4, snake_y4, snake_x3, snake_y3, snake_x2, snake_y2, snake_x1, snake_y1, snake_x0, snake_y0);

    end

    initial #500000 $finish;

endmodule
