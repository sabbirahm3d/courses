`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:20:25 09/10/2010 
// Design Name: 
// Module Name:    pacemaker 
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
module pacemaker(
        input wire clk,
        input wire boost,
        output reg p
    );

    parameter PERIOD = 8;
    parameter PULSE_WIDTH = 10000000;

    reg [32:0] count;
    reg [5:0] size;

    initial begin
        count <= 10000000;
    end

    always @(posedge clk) begin

        if (count == (PERIOD - 1)) begin
            count <= 0;
        end else begin
            count <= count + 1;
        end

        if (boost) begin
            size <= size + 1;
        end

    end

    always @(posedge clk) begin
        p <= count < PULSE_WIDTH - ((size - 32) * 100);
    end

endmodule
