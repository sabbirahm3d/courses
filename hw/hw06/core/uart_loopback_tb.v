`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Ryan Robucci
//
// Create Date:   20:02:27 04/13/2016
// Design Name:   top
// Module Name:   C:/CMPE-641/Study/uart/top_tb.v
// Project Name:  uart
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////

module top_tb;

    // Inputs
    reg reset;
    reg rxd;
    reg clk;
    reg baud_clk;
    integer bit_i, byte_i;
    reg [7:0] byte8;
    wire [7:0] loopbackdataout;

    // Outputs
    wire txd;

    // Instantiate the Unit Under Test (UUT)
    top uut(
        .reset(reset), 
        .rxd(rxd), 
        .txd(txd), 
        .clk(clk),
        .loopbackdataout(loopbackdataout)
    );

    initial clk = 0;
    always #20 clk = ~clk;

    parameter CLK_DIV = 2603;//5207/2;  //SYSTEM_CLK_RATE/BAUD_RATE/2
    initial baud_clk = 0;
    always begin
        repeat (CLK_DIV) @(posedge clk);
        baud_clk = ~baud_clk;
    end
    parameter NUM_BYTES_TO_SEND = 3;
    reg [7:0] memory_buffer [0:31]; // 2 entries 8 bit #'s
    reg [7:0] data_in;

    initial begin

        // init memory_buff from file
        $readmemh("memory_hex_in.txt", memory_buffer);

        // Initialize Inputs
        reset = 0;
        repeat (5) @(negedge clk);
        reset = 1;
        repeat (5) @(negedge clk);
        reset = 0;
        repeat (5) @(negedge clk);
        rxd = 1;

        // Wait 100 ns for global reset to finish
        #100;
        @(negedge baud_clk);
        for (byte_i = 0; byte_i < NUM_BYTES_TO_SEND;
        byte_i = byte_i + 1) begin

            rxd = 0; // start bit

            @(negedge baud_clk);

            byte8 = memory_buffer[byte_i];

            for (bit_i = 0; bit_i < 8; bit_i = bit_i + 1) begin
                rxd = byte8[bit_i];
                @(negedge baud_clk);
            end

            rxd = 1; //stopbit

            @(negedge baud_clk);

        end

    // Add stimulus here

    end

    always @(negedge baud_clk) begin
        $display("@negedge baud_clk:  rxd:%b,txd:%b", rxd, txd);
    end

    initial begin
        repeat (500) @(posedge baud_clk) ;
        $finish;
    end

endmodule
