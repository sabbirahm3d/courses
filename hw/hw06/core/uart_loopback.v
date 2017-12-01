`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Ryan Robucci
// 
// Create Date:    19:37:18 04/13/2016 
// Design Name: 
// Module Name:    top 
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
module top(reset,RXD,TXD,clk_50Mhz,
	   );

   wire [7:0] loopbackdata;
   input      reset;
   output     TXD;
   input      RXD;
   input      clk_50Mhz;
   wire       flagnewdata_n;
   //reg [49:0] flagnewdata_n_delay;
   reg [3:0]  state;
   wire       tx_empty;
   reg 	      ld_tx_data;

   always @ (posedge clk_50Mhz) begin
      if (reset) begin
	 state<=0;
	 ld_tx_data <= 0;
      end else begin
	 case (state)
	   0: begin
	      if (~flagnewdata_n) begin
		 state<=1;
	      end
	   end
	   1: begin
	      if (tx_empty) begin
		 state<=2;
		 ld_tx_data <= 1;
	      end
	   end
	   2: begin
	      if (~tx_empty) begin
		 state<=0;
		 ld_tx_data <= 0;
	      end
	   end
	 endcase
      end // reset else
   end



   uart u1 (
	    .reset(reset)          ,
	    .ld_tx_data(ld_tx_data)     , // initiate load 8 bits and send if ready to send
	    .tx_data(loopbackdata)        , // internal data 8 bit to send
	    .tx_enable(1'b1)      , // typically just set to 1
	    .tx_out (TXD)        , // external communication line 1 bit 
	    .tx_empty(tx_empty)       , // indicated finished any previous send and ready to send new value
	    .clk(clk_50Mhz)            ,
	    .uld_rx_data(~flagnewdata_n)    , // move new internal data to show up on rx_data
	    .rx_data(loopbackdata)        , // internal data 8 bit receive
	    .rx_enable (1'b1)     , // usually just set to 1
	    .rx_in(RXD)
	    , // external communication line 1 bit 
	    .rx_empty(flagnewdata_n)         // recieved serial data has been unloaded to rx_data output register, leaving room for new input serial byte

	    );


endmodule