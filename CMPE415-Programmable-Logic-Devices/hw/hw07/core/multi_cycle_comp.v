`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:54:14 12/09/2017 
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
     
    // dimenstion constants
    parameter XLEFT     = 320;
    parameter YBOTTOM   = 240;
    parameter RADIUS    = 10000;

    // temporary variables
    reg signed [19:0]   coord_temp;
    reg signed [9:0]    y_temp;
    reg signed [19:0]   out_temp;


    always @(posedge clk) begin

        if (reset) begin

            state <= INIT;

        end else begin

            case (state)

                // computes and stores (x - xc) to coord_temp
                // computes and stores (y - yc) to y_temp
                INIT: begin

                    coord_temp <= (x - XLEFT);
                    y_temp <= (y - YBOTTOM);
                    state <= SQUAREX;

                end

                // computes x^2 and stores to out_temp
                // stores y_temp to coord_temp
                SQUAREX: begin

                    out_temp <= (coord_temp * coord_temp);
                    coord_temp <= y_temp;
                    state <= SQUAREY;

                end

                // computes y^2 and stores to out_temp
                // stores previous out_temp to coord_temp
                SQUAREY: begin

                    coord_temp <=out_temp;
                    out_temp <= (coord_temp * coord_temp);
                    state <= ADDCMP;

                end

                // compares x^2 + y^2 to 10000 to generate the flag
                ADDCMP: begin

                    in_circle <= ((coord_temp + out_temp) < RADIUS);
                    state <= INIT;

                end

            endcase

        end

    end


endmodule
