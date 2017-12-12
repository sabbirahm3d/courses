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

    // state registers
    parameter INIT      = 2'b00;
    parameter SQUAREX   = 2'b01;
    parameter SQUAREY   = 2'b10;
    parameter ADDCMP    = 2'b11;
    reg [1:0] state;

    // dimension constants
    parameter XLEFT     = 320;
    parameter YBOTTOM   = 240;
    parameter RADIUS    = 10000;

    // temporary variables
    reg signed [20:0] x_temp;
    reg signed [20:0] y_temp;
    reg signed [20:0] mul_temp;

    always @(posedge clk) begin

        if (reset) begin

            state <= INIT;

        end else begin

            case(state)

                // computes (x - xc) and (y - yc)
                INIT: begin

                    x_temp <= (x - XLEFT);
                    y_temp <= (y - YBOTTOM);
                    state <= SQUAREX;

                end

                // computes x^2
                SQUAREX: begin

                    mul_temp <= (x_temp * x_temp);
                    state <= SQUAREY;

                end

                // computes y^2
                SQUAREY: begin

                    x_temp <= mul_temp;
                    mul_temp <= (y_temp * y_temp);
                    state <= ADDCMP;

                end

                // compares x^2 + y^2 to 10000
                ADDCMP: begin

                    in_circle <= ((x_temp + mul_temp) < RADIUS);
                    state <= INIT;

                end

            endcase

        end

    end


endmodule
