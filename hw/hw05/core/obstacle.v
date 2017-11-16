`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:34:03 11/10/2017 
// Design Name: 
// Module Name:    obstacle 
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
module obstacle(
        input wire clk,
        input wire obs_num,
        // input wire rst,
        output reg [4:0] obs_x,
        output reg [4:0] obs_y
    );

    integer i;

    always @(posedge clk) begin

        obs_x <= obs_num + 1;
        obs_y <= obs_num * 10 + 1;

    end

endmodule
