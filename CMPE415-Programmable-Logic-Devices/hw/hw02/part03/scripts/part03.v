`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:12:55 10/03/2017 
// Design Name: 
// Module Name:    part03 
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
module part03(
		input [3:0] x,
		input [2:0] s,
		output reg y
	);

	always @(x or s) begin

		case(s)

			0: y <= &x;
			1: y <= |x;
			2: y <= ^x;
			3: y <= ~&x;
			4: y <= ~|x;
			default: $display("Error in selection");

		endcase

	end

endmodule
