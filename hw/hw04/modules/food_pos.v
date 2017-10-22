`timescale 1ns / 1ps
`default_nettype none
///////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date:    18:33:21 09/9/2017
// Design Name:
// Module Name:    vga_rectangle
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
///////////////////////////////////////////////////////////////////////////////

module food_pos(
        input wire enable,
        input wire clk,
        input wire clr,
        output reg [8:0] x,
        output reg [8:0] y
    );

    reg [8:0] cnt_int;  // internal counter
    wire feedback;

    // polynomial for maximal LFSR of 9 bits (2^9-1 terms)
    assign feedback = ~(cnt_int[8] ^ cnt_int[4]);

    initial begin

        x = 9'b0;
        y = 9'b0;
        cnt_int = 9'b0;

    end

    always @(posedge clk) begin
        cnt_int <= {cnt_int[7:0], feedback};
    end

    always @(posedge clk, posedge clr) begin

        // if active high asynchronous reset
        if (clr) begin

            x <= 9'b0;
            y <= 9'b0;

        // if enable
        end else if (enable) begin

            x <= cnt_int;
            y <= cnt_int + cnt_int;

        end

    end

endmodule