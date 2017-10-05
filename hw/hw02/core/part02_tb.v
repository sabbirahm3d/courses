`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:53:05 10/04/2017 
// Design Name: 
// Module Name:    part02_tb 
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
module part02_tb();

	reg x, rst;
	wire y;

	part02 DUT(x, rst, y);

	initial begin
	
		rst = 1;
		x = 0;
		#1
		x = 1;
		#1
		x = 0;

		#4
		x = 0;
		#1
		x = 1;
		#1
		x = 0;

	end
	
	initial #20 $finish;


endmodule
