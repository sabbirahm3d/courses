`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:00:54 10/26/2017 
// Design Name: 
// Module Name:    direction 
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
//////////////////////////////////////////////////////////////////////////////
module direction(
        input wire east,
        input wire west,
        input wire reset,  // enable
        input wire clk,
        output reg [1:0] dir
    );

    initial begin

        dir = 2'b00;

    end

    always @(posedge clk) begin

        if (reset) begin

            dir <= 2'b00;

        end else begin

            if (east && ~west) begin
                dir <= dir + 1;
            end else if (~east && west) begin
                dir <= dir - 1;
            end

        end

    end

endmodule
