`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:35:07 09/29/2017 
// Design Name: 
// Module Name:    part01 
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
module part01_a(
		input a,
		input b,
		input c,
		output reg y,
		output reg z
	);

	always @(a or b or c) begin

		if (a && b && c) begin  // 111
			y <= 0;
			z <= 1;
		end else if (a && b && ~c) begin  // 110
			y <= 1;
			z <= 1;
		end else if (a && ~b && ~c) begin  // 100
			y <= 0;
			z <= 0;
		end else begin
			y <= 0;
			z <= 1'bx;
		end

	end

endmodule
