`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:56:19 10/03/2017 
// Design Name: 
// Module Name:    part05_tb 
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
module part05_tb();

	reg [63:0] x;
	reg clk;
	wire [63:0] u;

	part05 DUT(x, clk, u);

	always begin
		#1 clk = ~clk;
	end

	initial begin
	
		clk = 1;
		x = {32{2'b01}};
		#3;
		$display($time, " x = %b %d", x, clk);
		$display($time, " u = %b %d", u, clk);

		x = {32{2'b10}};
		#1;
		$display($time, " x = %b %d", x, clk);
		$display($time, " u = %b %d", u, clk);
		#1
		$display($time, " x = %b %d", x, clk);
		$display($time, " u = %b %d", u, clk);

	end

	initial #40 $finish;

endmodule
