`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:02:26 10/09/2017 
// Design Name: 
// Module Name:    extinguisher 
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
module extinguisher(
        input wire enable,
        input wire clk,
        input wire clr_n,
        output reg active,
        output reg [2:0] position
    );

    integer cnt_int;  // internal counter

    initial begin

        position <= 3'b0;
        cnt_int <= 0;

    end

    always @(posedge clk) begin
        cnt_int <= (cnt_int + 1) % 16;  // increment the counter at every cycle
    end

    always @(posedge clk, negedge clr_n) begin

        // if active low asynchronous reset
        if (~clr_n) begin

            active <= 0;
            position <= 3'b0;

        // if enable
        end else if (enable) begin

            // if the counter is less than or equal to 0b111
            if (cnt_int <= 4'b0111) begin
                active <= 1;
                position <= cnt_int;
            end else begin
                active <= 0;
            end

        end

    end

endmodule
