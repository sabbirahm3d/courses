`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:53:16 10/09/2017 
// Design Name: 
// Module Name:    igniter 
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
module igniter(
        input wire [3:0] delta,
        input wire enable_jump,
        input wire sys_clk,
        input wire clr_n,
        output reg [2:0] position
    );

    initial begin

        position <= 3'b0;

    end

    always @(posedge sys_clk, enable_jump, negedge clr_n) begin

        // $display("start %b", delta);
        if (clr_n) begin

            position <= 3'b0;
            // $monitor("MAYBE %b", delta);

        end else if (enable_jump) begin

            // $display("before %b", delta);
            position <= (position + delta) % 8;
            // $monitor("HEEEEEEEEEEE %b %b", position, delta);

        end
        // $monitor("IN IGNITER pos: %b delta: %b", position, delta);

    end

endmodule
