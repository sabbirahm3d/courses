`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:50:30 10/04/2017 
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
module part02(
		input x,
		input rst,
		output reg y
    );

	always @(x) begin

		if (rst) begin

			y <= 0;

		end

		y <= #5 x;

	end


endmodule
