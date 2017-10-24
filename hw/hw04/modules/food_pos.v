`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:05:21 10/22/2017 
// Design Name: 
// Module Name:    food_pos
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

module food_pos(
        input wire clk,
        input wire enable,
        input wire clr,
        output reg [8:0] x,
        output reg [8:0] y
    );

    reg [8:0] internal_ctr, lfsr;  // internal counter
    wire feedback;

    // polynomial for maximal LFSR of 9 bits (2^9-1 terms)
    assign feedback = ~(lfsr[8] ^ lfsr[4]);

    initial begin

        x = 9'b0;
        y = 9'b0;
        lfsr = 9'b0;
        internal_ctr = 9'b0;

    end

    always @(posedge clk) begin

        lfsr <= {lfsr[7:0], feedback};
        internal_ctr <= internal_ctr + 1;

    end

    always @(posedge clk, posedge clr) begin

        // if active high asynchronous reset
        if (clr) begin

            x <= 9'b0;
            y <= 9'b0;

        // if enable
        end else if (enable) begin

            x <= lfsr;
            y <= lfsr + internal_ctr;

        end

    end

endmodule