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
        output reg circleFlag
    );

    parameter INIT    	= 2'b00;
    parameter SquareX   = 2'b01;
    parameter SquareY   = 2'b10;
    parameter Compare   = 2'b11;
    reg [1:0] state;
	 
	 parameter XLEFT = 320;
	 parameter YBOTTOM = 240;
	 parameter RADIUS = 10000;

    reg signed [19:0] subX;
    reg signed [9:0] subY;
    reg signed [19:0] sumSquared;


    always @(posedge clk) begin

        if (reset) begin

            state <= INIT;

        end else begin

            case (state)

                // computes the subtractions 
                INIT: begin

                    subX <= (x - XLEFT);
                    subY <= (y - YBOTTOM);
                    state <= SquareX;
						  

                end

                // computes x^2
                SquareX: begin

                    sumSquared <= (subX * subX);
						  subX <= subY;
                    state <= SquareY;

                end

                // computes y^2
                SquareY: begin

                    subX <=sumSquared;
                    sumSquared <= (subX * subX);
                    state <= Compare;

                end

                // compares x^2 + y^2 to 10000 and assigns the flag
                Compare: begin

                    circleFlag <= ((subX + sumSquared) < RADIUS);
                    state <= INIT;

                end

            endcase

        end

    end


endmodule
