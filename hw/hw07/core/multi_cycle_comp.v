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
    parameter ADDSQY    = 2'b01;
    parameter CMPRAD    = 2'b11;
    reg [1:0] state;

    reg [20:0] temp_flag;

    always @(posedge clk) begin

        if (reset) begin

            state <= SQX;

        end else begin

            case (state)

                SQX: begin

                    temp_flag <= x * x;
                    state <= ADDSQY;

                end

                ADDSQY: begin

                    temp_flag <= temp_flag + y * y;
                    state <= CMPRAD;

                end

                CMPRAD: begin

                    in_circle <= temp_flag < 10000;
                    state <= CMPRAD;
                    $display("DONE %d", temp_flag);

                end

            endcase

        end

    end


endmodule
