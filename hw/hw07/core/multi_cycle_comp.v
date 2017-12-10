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
        input wire [9:0] x,
        input wire [9:0] y,
        output reg in_circle
    );

    parameter SQUAREX       = 2'b00;
    parameter ADDSQUAREY    = 2'b01;
    parameter CMPRAD        = 2'b11;
    reg state;

    reg [9:0] temp_flag;

    always @(posedge clk) begin

        case (state)

            SQUAREX: begin

                temp_flag = x * x;
                state = ADDSQUAREY;

            end

            ADDSQUAREY: begin

                $monitor("before %b", state);
                temp_flag = y * y;
                state = CMPRAD;
                $monitor("HERERR %b", state);

            end

            CMPRAD: begin

                in_circle = temp_flag < 10000;
                state = CMPRAD;

            end

            default: begin

                state = SQUAREX;

            end

        endcase

    end


endmodule
