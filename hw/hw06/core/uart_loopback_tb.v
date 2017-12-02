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
    integer bitIndex, byteIndex;
    reg [7:0] byte8;

    // Outputs
    wire txd;

    // Instantiate the Unit Under Test (UUT)
    top uut(
        .reset(reset), 
        .rxd(rxd), 
        .txd(txd), 
        .clk(clk)
    );

    initial clk = 0;
    always #20 clk = ~clk;

    //parameter CLK_DIV = 217 ;//433/2;
    parameter CLK_DIV = 2603;//5207/2;  //SYSTEM_CLK_RATE/BAUD_RATE/2
    initial baud_clk = 0;
    always begin
        repeat (CLK_DIV) @(posedge clk);
        baud_clk = ~baud_clk;
    end
    parameter NUM_BYTES_TO_SEND = 3;
    reg [7:0] memory_buffer [10:0]; // 2 entries 8 bit #'s
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
        for (byteIndex = 0; byteIndex < NUM_BYTES_TO_SEND;
        byteIndex = byteIndex + 1) begin

            rxd = 0; // start bit

            @(negedge baud_clk);

            byte8 = memory_buffer[byteIndex];

            for (bitIndex = 0; bitIndex < 8; bitIndex = bitIndex + 1) begin
                rxd = byte8[bitIndex];
                @(negedge baud_clk);
            end

            rxd = 1; //stopbit

            @(negedge baud_clk);

        end

    // Add stimulus here

    end

    always @(negedge baud_clk) begin
        $display("@negedge baud_clk:  rxd:%b,txd:%b",rxd,txd);
    end

    initial begin
        repeat (500) @(posedge baud_clk) ;
        $finish;
    end

endmodule
