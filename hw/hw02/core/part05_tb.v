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

	initial begin
	
		clk = 1;
		x = {32{2'b10}};
		#5;
		$display($time, " x = %b", x);
		#5;
		$display($time, " u = %b", u);

		clk = 0;
		x = {21{3'b101}};
		#5;
		$display($time, " x = %b", x);
		#5;
		$display($time, " u = %b", u);

		clk = 1;
		x = {21{3'b101}};
		#5;
		$display($time, " x = %b", x);
		#5;
		$display($time, " u = %b", u);

		clk = 0;

	end

	initial #40 $finish;

endmodule
