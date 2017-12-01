`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////

module top_tb;

   // Inputs
   reg reset;
   reg RXD;
   reg clk_50Mhz;
   reg baud_clk;
   integer bitIndex,byteIndex;
   reg [7:0] byte8;

   // Outputs
   wire      TXD;

   // Instantiate the Unit Under Test (UUT)
   top uut (
	    .reset(reset), 
	    .RXD(RXD), 
	    .TXD(TXD), 
	    .clk_50Mhz(clk_50Mhz)
	    );



   initial clk_50Mhz=0;
   always #20 clk_50Mhz =~clk_50Mhz;

   //parameter CLK_DIV = 217 ;//433/2;
   parameter CLK_DIV = 2603;//5207/2;  //SYSTEM_CLK_RATE/BAUD_RATE/2
   initial baud_clk =0;
   always begin
      repeat (CLK_DIV) @(posedge clk_50Mhz);
      baud_clk=~baud_clk;
   end
   parameter NUM_BYTES_TO_SEND =3;
   reg [7:0] memory_buffer [10:0]; // 2 entries 8 bit #'s
   reg [7:0] data_in;

   initial begin
      $readmemh("memory_hex_in.txt", memory_buffer); //init memory_buff from file

      // Initialize Inputs
      reset = 0;
      repeat (5) @(negedge clk_50Mhz);
      reset = 1;
      repeat (5) @(negedge clk_50Mhz);
      reset = 0;
      repeat (5) @(negedge clk_50Mhz);
      RXD = 1;


      // Wait 100 ns for global reset to finish
      #100;
      @(negedge baud_clk);
      for(byteIndex=0;byteIndex<NUM_BYTES_TO_SEND;byteIndex=byteIndex+1) begin
	 RXD =0; //startbit
	 @(negedge baud_clk);
	 byte8 = memory_buffer[byteIndex];
	 for(bitIndex=0;bitIndex<8;bitIndex=bitIndex+1) begin
	    RXD = byte8[bitIndex];
	    @(negedge baud_clk);
	 end
	 RXD = 1; //stopbit
	 @(negedge baud_clk);
      end
      
      // Add stimulus here

   end
   always @(negedge baud_clk) begin
      $display("@negedge baud_clk:  RXD:%b,TXD:%b",RXD,TXD);
   end
   initial begin
      repeat (500) @(posedge baud_clk) ;
      $finish;
   end


endmodule
