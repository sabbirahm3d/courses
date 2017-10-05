`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:04:52 10/03/2017 
// Design Name: 
// Module Name:    part04 
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
module part04(
		input [3:0] x,
		input [3:0] y,
		input [2:0] s,
		input clk,
		output reg [3:0] q
	);

	integer i;
	always @(posedge clk) begin

		case(s)

			0: q <= (x & y);
			1: q <= x | y;
			2: q <= x ^ y;
			3: q <= ~(x & y);
			4: q <= ~(x | y);

		endcase

	end


endmodule
