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
    reg [8:0] snake_x31, snake_x30, snake_x29, snake_x28,
        snake_x27, snake_x26, snake_x25, snake_x24,
        snake_x23, snake_x22, snake_x21, snake_x20,
        snake_x19, snake_x18, snake_x17, snake_x16,
        snake_x15, snake_x14, snake_x13, snake_x12,
        snake_x11, snake_x10, snake_x9, snake_x8,
        snake_x7, snake_x6, snake_x5, snake_x4,
        snake_x3, snake_x2, snake_x1, snake_x0;
    reg [8:0] snake_y31, snake_y30, snake_y29, snake_y28,
        snake_y27, snake_y26, snake_y25, snake_y24,
        snake_y23, snake_y22, snake_y21, snake_y20,
        snake_y19, snake_y18, snake_y17, snake_y16,
        snake_y15, snake_y14, snake_y13, snake_y12,
        snake_y11, snake_y10, snake_y9, snake_y8,
        snake_y7, snake_y6, snake_y5, snake_y4,
        snake_y3, snake_y2, snake_y1, snake_y0;
    wire bite, dead;

    collision collision_instance(
        .clk(clk),
        .food_x(food_x), .food_y(food_y),
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
        .snake_y30(snake_y30), .snake_y31(snake_y31),
        .bite(bite), .dead(dead)
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

        {
            snake_x31, snake_x30, snake_x29, snake_x28,
            snake_x27, snake_x26, snake_x25, snake_x24,
            snake_x23, snake_x22, snake_x21, snake_x20,
            snake_x19, snake_x18, snake_x17, snake_x16,
            snake_x15, snake_x14, snake_x13, snake_x12,
            snake_x11, snake_x10, snake_x9, snake_x8,
            snake_x7, snake_x6, snake_x5
        } = {27{{9{1'b0}}}};

        {
            snake_y31, snake_y30, snake_y29, snake_y28,
            snake_y27, snake_y26, snake_y25, snake_y24,
            snake_y23, snake_y22, snake_y21, snake_y20,
            snake_y19, snake_y18, snake_y17, snake_y16,
            snake_y15, snake_y14, snake_y13, snake_y12,
            snake_y11, snake_y10, snake_y9, snake_y8,
            snake_y7, snake_y6, snake_y5
        } = {27{{9{1'b0}}}};

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
            // , ~(
            // ((snake_x0 ^ snake_x3) && (snake_y0 ^ snake_y3)) ||
            // ((snake_x0 ^ snake_x4) && (snake_y0 ^ snake_y4)) ||
            // ((snake_x0 ^ snake_x5) && (snake_y0 ^ snake_y5)) ||
            // ((snake_x0 ^ snake_x6) && (snake_y0 ^ snake_y6)) ||
            // ((snake_x0 ^ snake_x7) && (snake_y0 ^ snake_y7)) ||
            // ((snake_x0 ^ snake_x8) && (snake_y0 ^ snake_y8)) ||
            // ((snake_x0 ^ snake_x9) && (snake_y0 ^ snake_y9)) ||
            // ((snake_x0 ^ snake_x10) && (snake_y0 ^ snake_y10)) ||
            // ((snake_x0 ^ snake_x11) && (snake_y0 ^ snake_y11)) ||
            // ((snake_x0 ^ snake_x12) && (snake_y0 ^ snake_y12)) ||
            // ((snake_x0 ^ snake_x13) && (snake_y0 ^ snake_y13)) ||
            // ((snake_x0 ^ snake_x14) && (snake_y0 ^ snake_y14)) ||
            // ((snake_x0 ^ snake_x15) && (snake_y0 ^ snake_y15)) ||
            // ((snake_x0 ^ snake_x16) && (snake_y0 ^ snake_y16)) ||
            // ((snake_x0 ^ snake_x17) && (snake_y0 ^ snake_y17)) ||
            // ((snake_x0 ^ snake_x18) && (snake_y0 ^ snake_y18)) ||
            // ((snake_x0 ^ snake_x19) && (snake_y0 ^ snake_y19)) ||
            // ((snake_x0 ^ snake_x20) && (snake_y0 ^ snake_y20)) ||
            // ((snake_x0 ^ snake_x21) && (snake_y0 ^ snake_y21)) ||
            // ((snake_x0 ^ snake_x22) && (snake_y0 ^ snake_y22)) ||
            // ((snake_x0 ^ snake_x23) && (snake_y0 ^ snake_y23)) ||
            // ((snake_x0 ^ snake_x24) && (snake_y0 ^ snake_y24)) ||
            // ((snake_x0 ^ snake_x25) && (snake_y0 ^ snake_y25)) ||
            // ((snake_x0 ^ snake_x26) && (snake_y0 ^ snake_y26)) ||
            // ((snake_x0 ^ snake_x27) && (snake_y0 ^ snake_y27)) ||
            // ((snake_x0 ^ snake_x28) && (snake_y0 ^ snake_y28)) ||
            // ((snake_x0 ^ snake_x29) && (snake_y0 ^ snake_y29)) ||
            // ((snake_x0 ^ snake_x30) && (snake_y0 ^ snake_y30)) ||
            // ((snake_x0 ^ snake_x31) && (snake_y0 ^ snake_y31)))
            // );

    end

    initial #2000 $finish;

endmodule
