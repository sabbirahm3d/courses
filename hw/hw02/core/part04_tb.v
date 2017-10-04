`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:09:20 10/03/2017 
// Design Name: 
// Module Name:    part04_tb 
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
module part04_tb();

    reg [3:0] x, y;
	 reg [2:0] s;
    reg clk;
    wire [3:0] q;

    part04 DUT(x, y, s, clk, q);

    initial begin

        // bitwise AND reduction
        clk = 1;
        s = 0;

        y = 4'b1010;
        x = 4'b1001;
        // y = 4'b0000;
        #1
        $display("x:%b & y:%b = %b s:%d", x, y, q, s);

        x = 4'bx111;
        // y = 4'b1111;
        #5
        $display("x:%b & y:%b = %b s:%d", x, y, q, s);

        x = 4'bz111;
        // y = 4'b1111;
        #5
        $display("x:%b & y:%b = %b s:%d", x, y, q, s);

        #1
        // clk = 0;
        #5

        // bitwise OR reduction
        clk = 1;
        s = 1;

        x = 4'b1001;
        // y = 4'b1111;
        #5
        $display("x:%b | y:%b = %b s:%d", x, y, q, s);

        x = 4'bx001;
        // y = 4'b1111;
        #5
        $display("x:%b | y:%b = %b s:%d", x, y, q, s);

        x = 4'bz001;
        // y = 4'b1111;
        #5
        $display("x:%b | y:%b = %b s:%d", x, y, q, s);
        $display("x:%b & y:%b = %b s:%d", x, y, q, s);

        #1
        // clk = 0;
        #5

        // bitwise XOR reduction
        clk = 1;
        s = 2;
		  #2

        x = 4'b1001;
        // y = 4'b1111;
        #1
        $display("x:%b ^ y:%b = %b s:%d", x, y, q, s);

        x = 4'bx000;
        // y = 4'b1111;
        #1
        $display("x:%b ^ y:%b = %b s:%d", x, y, q, s);

        x = 4'bz000;
        // y = 4'b1111;
        #1
        $display("x:%b ^ y:%b = %b s:%d", x, y, q, s);
        $display("x:%b & y:%b = %b s:%d", x, y, q, s);

        #1
        // clk = 0;
        #5

        // bitwise NAND reduction
        clk = 1;
        s = 3;
		  #2

        x = 4'b1001;
        // y = 4'b1111;
        #5
        $display("x:%b ~& y:%b = %b s:%d", x, y, q, s);
        $display("x:%b ~& y:%b = %b", x, y, (!(4'b1001 & 4'b1010)));

        x = 4'bx001;
        // y = 4'b1111;
        #1
        $display("x:%b ~& y:%b = %b s:%d", x, y, q, s);

        x = 4'b1111;
         y = 4'b1111;
        #10
        $display("x:%b ~& y:%b = %b s:%d", x, y, q, s);

        #1
        // clk = 0;
        #5

        // bitwise NOR reduction
        clk = 1;
        s = 4;

        x = 4'b1001;
        // y = 4'b1111;
        #1

        $display("x:%b ~| y:%b = %b s:%d", x, y, q, s);

        x = 4'bx001;
        // y = 4'b1111;
        #1
        $display("x:%b ~| y:%b = %b s:%d", x, y, q, s);

        x = 4'bz001;
        // y = 4'b1111;
        #1
        $display("x:%b ~| y:%b = %b s:%i", x, y, q, s);

        #1
        // clk = 0;
        #5

        #20 $finish;

    end


endmodule
