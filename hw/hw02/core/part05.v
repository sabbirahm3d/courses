`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:46:18 10/03/2017 
// Design Name: 
// Module Name:    part05 
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
module part05(
		 input [63:0] x,
		 input clk,
		 output reg [63:0] u
    );
	 
	integer i;

	always @(posedge clk) begin

		for (i = 0; i < 63; i = i + 1) begin

			u[i + 1] = x[i];
			u[i] = x[i + 1];

		end
	
	end


endmodule
