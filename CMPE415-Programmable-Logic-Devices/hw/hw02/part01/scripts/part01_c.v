`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:29:08 10/03/2017 
// Design Name: 
// Module Name:    part01_c 
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
module part01_c(
		input a,
		input b,
		input c,
		output reg y,
		output reg z
	);

	always @(a or b or c) begin

		case({a, b, c})
		
			3'b111: begin
				y <= 1'b0;
				z <= 1'b1;
			end
		
			3'b110: begin
				y <= 1'b1;
				z <= 1'b1;
			end
			
			3'b100: begin
				y <= 1'b0;
				z <= 1'b0;
			end
			
			default begin
				y <= 1'b0;
				z <= 1'bx;
			end
		
		endcase

	end

endmodule
