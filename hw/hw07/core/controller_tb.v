`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Ryan Robucci
//
// Create Date:   20:02:27 04/13/2016
// Design Name:   controller
// Module Name:
// Project Name:  uart
// Target Device:  
// Tool versions:  
// Description: 
//
//
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////

module controller_tb;

    // Inputs
    reg clk;
    reg reset;
    reg rx_empty, tx_empty;
    integer byte_i;
    reg [7:0] rx_data;
    wire [7:0] tx_data;

    // Instantiate the Unit Under Test (UUT)
    controller uut(
        .clk(clk), 
        .reset(reset), 
        .rx_empty(rx_empty), 
        .tx_empty(tx_empty), 
        .rx_data(rx_data), 
        .tx_data(tx_data)
    );

    initial begin
        clk = 0;
        rx_empty = 0;
        tx_empty = 0;
        reset = 1;
    end

    always begin
        #20 clk = ~clk;
    end

    reg [7:0] memory_buffer [31:0]; // 2 entries 8 bit #'s

    initial begin

        #30;
        reset = 0;
        // init memory_buff from file
        $readmemh("memory_hex_in.txt", memory_buffer);

        for (byte_i = 0; byte_i < 31; byte_i = byte_i + 1) begin

            #20;
            rx_data = memory_buffer[byte_i];
            #200;

        end

    end

    initial #20000 $finish;

endmodule
