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
        output reg [3:0] position
    );

    integer cnt_int;

    initial begin

        position = 4'b0;
        active = 0;
        cnt_int = 0;

    end

    always @(posedge clk) begin

        cnt_int <= (cnt_int + 1) % 16;

    end

    always @(cnt_int or enable or clr_n) begin

        if (clr_n) begin

            active <= 0;
            position <= 0;

        end else begin

            if (cnt_int <= 4'b0111) begin
                active <= 1;
                position <= cnt_int;
            end else begin
                active <= 0;
            end

        end

    end

endmodule
