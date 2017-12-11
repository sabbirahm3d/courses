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

    parameter SQX       = 2'b00;
    parameter SQY       = 2'b01;
    parameter ADDXY     = 2'b11;
    parameter CMPRAD    = 2'b10;
    reg [1:0] state;

    reg [20:0] sqx_reg;
    reg [20:0] temp_out;

    always @(posedge clk) begin

        if (reset) begin

            state <= SQX;

        end else begin

            case (state)

                // computes x^2
                SQX: begin

                    temp_out <= (x * x);
                    state <= SQY;

                end

                // computes x^2
                SQY: begin

                    $display("before %d", temp_out);
                    sqx_reg <= temp_out;
                    temp_out <= y * y;
                    state <= ADDXY;

                end

                // computes x^2 + y^2
                ADDXY: begin

                    $display("after %d", temp_out);
                    temp_out <= sqx_reg + temp_out;
                    state <= CMPRAD;

                end

                // compares x^2 + y^2 to 10000
                CMPRAD: begin

                    $display("final %d", temp_out);
                    in_circle <= (temp_out < 10000);
                    state <= CMPRAD;

                end

            endcase

        end

    end


endmodule
