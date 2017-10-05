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

	 always begin
		  #1 clk = ~clk;
	 end

    initial begin

        // bitwise AND reduction
        clk = 1;
        s = 0;
		#3

        y = 4'b1010;
        x = 4'b1001;
        // y = 4'b0000;
        #2
        $display("x:%b & y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bx111;
        // y = 4'b1111;
        #2
        $display("x:%b & y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bz111;
        // y = 4'b1111;
        #2
        $display("x:%b & y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        // bitwise OR reduction
        s = 1;

        x = 4'b1001;
        // y = 4'b1111;
        #2
        $display("x:%b | y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bx001;
        // y = 4'b1111;
        #2
        $display("x:%b | y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bz001;
        // y = 4'b1111;
        #2
        $display("x:%b | y:%b = %b s:%d clk:%d", x, y, q, s, clk);
        $display("x:%b & y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        // bitwise XOR reduction
        s = 2;
		#2

        x = 4'b1001;
        // y = 4'b1111;
        #2
        $display("x:%b ^ y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bx000;
        // y = 4'b1111;
        #2
        $display("x:%b ^ y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bz000;
        // y = 4'b1111;
        #2
        $display("x:%b ^ y:%b = %b s:%d clk:%d", x, y, q, s, clk);
        $display("x:%b & y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        // bitwise NAND reduction
        s = 3;
		#2

        x = 4'b1001;
        // y = 4'b1111;
        #2
        $display("x:%b ~& y:%b = %b s:%d clk:%d", x, y, q, s, clk);
        $display("x:%b ~& y:%b = %b", x, y, (!(4'b1001 & 4'b1010)));

        x = 4'bx001;
        // y = 4'b1111;
        #2
        $display("x:%b ~& y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'b1111;
         // y = 4'b1111;
        #2
        $display("x:%b ~& y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        // bitwise NOR reduction
        s = 4;

        x = 4'b1001;
        #2

        $display("x:%b ~| y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bx001;
        #2
        $display("x:%b ~| y:%b = %b s:%d clk:%d", x, y, q, s, clk);

        x = 4'bz001;
        #2
        $display("x:%b ~| y:%b = %b s:%i clk:%d", x, y, q, s, clk);

        #2 $finish;

    end


endmodule
