`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
module single_cycle_comp(
        input wire clk,
        input wire reset,
        input wire [9:0] x,
        input wire [9:0] y,
        output reg in_circle
    );

    // state registers
    parameter INIT      = 2'b00;
    parameter COMPUTE   = 2'b01;
    reg [1:0] state;

    // dimension constants
    parameter XLEFT     = 320;
    parameter YBOTTOM   = 240;
    parameter RADIUS    = 10000;

    always @(posedge clk) begin

        if (reset) begin

            in_circle <= 0;
            state <= INIT;

        end else begin

            case (state)

                INIT: begin

                    state <= COMPUTE;

                end

                COMPUTE: begin

                    // (x - xc)^2 + (y - yc)^2 < 10000
                    in_circle <= (
                        ((x - XLEFT) * (x - XLEFT) +
                            (y - YBOTTOM) * (y - YBOTTOM)) < RADIUS
                    );
                    state <= INIT;

                end

            endcase

        end

    end


endmodule
