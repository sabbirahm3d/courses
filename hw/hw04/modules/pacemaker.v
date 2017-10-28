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
        input wire interval,
        output reg p
    );

    // parameter CLOCK_FREQ = 50000;
    // parameter TIME_DELAY = 6;

    // reg [31:0] count = 0;

    // assign p = (count==CLOCK_FREQ*TIME_DELAY);

    // always @(posedge clk) begin

    //    count <= count + 1'b1;

    // end

    parameter PERIOD = 50000000;   
    parameter PULSE_WIDTH = 8;

    reg [32:0] count;

    initial begin
        count <= 8;
    end   

    always @ (posedge clk) begin

        if (count == (PERIOD - 1)) begin
            count <= 0;
        end else begin
            count <= count + 1;       
        end

    end

    always @ (posedge clk) begin
        p <= count < PULSE_WIDTH;       
    end

endmodule
