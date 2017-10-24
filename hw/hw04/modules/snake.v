`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:45:03 10/22/2017 
// Design Name: 
// Module Name:    snake
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
module snake(
        input wire clk,
        input wire direction,
        output reg [9:0] snakeX [0:31],
        output reg [8:0] snakeY [0:31]
    );

    always @(posedge clk) begin

        

    end

endmodule
