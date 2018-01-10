`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:35:07 09/29/2017 
// Design Name: 
// Module Name:    part02 
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
module part01_b(
		input a,
		input b,
		input c,
		output reg y,
		output reg z
	);

	always @(a or b or c) begin

		y <= a && b && ~c;
		z <= b;

	end

endmodule
