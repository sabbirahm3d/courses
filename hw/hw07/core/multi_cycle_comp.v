`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:39:24 12/10/2017 
// Design Name: 
// Module Name:    multi_cycle_comp 
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
module multi_cycle_comp(
        input wire clk,
        input wire reset,
        input wire [9:0] x,
        input wire [9:0] y,
        output reg in_circle
    );

    parameter INIT      = 2'b00;
    parameter SQX       = 2'b01;
    parameter SQY       = 2'b10;
    parameter ADDCMP    = 2'b11;
    reg [1:0] state;

    reg signed [20:0] x_reg;
    reg signed [20:0] y_reg;
    reg signed [20:0] sum_sq;
    reg signed [20:0] temp_out;

    always @(posedge clk) begin

        if (reset) begin

            state <= INIT;

        end else begin

            case (state)

                // computes (x - xc) and (y - yc)
                INIT: begin

                    x_reg <= (x - 320);
                    y_reg <= (y - 240);
                    state <= SQX;

                end

                // computes x^2
                SQX: begin

                    sum_sq <= (x_reg * x_reg);
                    state <= SQY;

                end

                // computes y^2
                SQY: begin

                    x_reg <= sum_sq;
                    sum_sq <= (y_reg * y_reg);
                    state <= ADDCMP;

                end

                // computes x^2 + y^2 < 10000
                ADDCMP: begin

                    in_circle <= ((x_reg + sum_sq) < 10000);
                    state <= INIT;

                end

            endcase

        end

    end


endmodule
