`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:53:16 10/09/2017 
// Design Name: 
// Module Name:    igniter 
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
module igniter(
        input wire [3:0] delta,
        input wire enable_jump,
        input wire sys_clk,
        input wire clr_n,
        output reg [2:0] position
    );

    always @(posedge sys_clk, negedge clr_n) begin

        if (~clr_n) begin

            position <= 3'b0;

        end else if (enable_jump) begin

            position <= position + delta;

        end

    end

endmodule
