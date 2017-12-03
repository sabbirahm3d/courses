`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sabbir Ahmed
// 
// Create Date:    19:10:51 12/01/2017 
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
//////////////////////////////////////////////////////////////////////////////
module top(
        input wire clk,
        input wire reset,
        input wire rxd,
        output wire txd,
        output wire [7:0] loopbackdataout
    );

    wire [7:0] loopbackdata;
    wire flagnewdata_n;
    reg [3:0] state;
    wire tx_empty;
    reg ld_tx_data;

    uart uart_unit(
        .clk(clk),
        .reset(reset),
        .ld_tx_data(ld_tx_data),        // initiate load 8 bits and send if
                                        // ready to send
        .tx_data(loopbackdata),         // internal data 8 bit to send
        .tx_enable(1'b1),               // typically just set to 1
        .tx_out(txd),                   // external communication line 1 bit 
        .tx_empty(tx_empty),            // indicated finished any previous 
                                        // send and ready to send new value
                                        // move new internal data to show up
                                        // on rx_data
        .uld_rx_data(~flagnewdata_n),
        .rx_data(loopbackdata),         // internal data 8 bit receive
        .rx_enable (1'b1),              // usually just set to 1
        .rx_in(rxd),                    // external communication line 1 bit 
        .rx_empty(flagnewdata_n)        // recieved serial data has been
                                        // unloaded to rx_data output
                                        // register, leaving room for new
                                        // input serial byte
    );

    defparam uart_unit.CLK_DIVISION = 443;

    controller controller_unit(
        .clk(clk),
        .reset(reset),
        .rx_empty(~flagnewdata_n),
        .tx_empty(tx_empty),
        .rx_data(loopbackdata),
        .tx_data(loopbackdataout)
    );

    always @(posedge clk) begin

        if (reset) begin

            state <= 0;
            ld_tx_data <= 0;

        end else begin

            case (state)

                0: begin

                    if (~flagnewdata_n) begin

                        state <= 1;

                    end

                end

                1: begin

                    if (tx_empty) begin

                        state <= 2;
                        ld_tx_data <= 1;

                    end

                end

                2: begin

                    if (~tx_empty) begin

                        state <= 0;
                        ld_tx_data <= 0;

                    end

                end

            endcase

        end  // reset else

    end

endmodule
