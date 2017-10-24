`timescale 1ns / 1ps
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
module snake_tb;

    reg enable;
    reg clk;
    reg clr;
    wire [8:0] x, y;

    snake snake_instance(
            update,
            start,
            clk,
            snakeHead,
            snakeBody,
            xCount,
            yCount,
            x,y,z,w,h,
            size
        );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin
    end

    initial #200000 $finish;

endmodule
