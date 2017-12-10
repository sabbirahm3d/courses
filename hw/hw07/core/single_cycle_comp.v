`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:41:15 12/10/2017 
// Design Name: 
// Module Name:    single_cycle_comp 
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
module single_cycle_comp(
        input wire clk,
        input wire [9:0] x,
        input wire [9:0] y,
        output reg in_circle
    );

    parameter ONLYSTATE = 1'b0;
    reg state;

    always @(posedge clk) begin

        case (state)

            0: begin

                in_circle <= ((x * x + y * y) < 10000);
                state <= ONLYSTATE;

            end

            default: begin

                state <= ONLYSTATE;

            end

        endcase

    end


endmodule
