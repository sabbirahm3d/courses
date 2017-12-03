`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:10:51 12/01/2017 
// Design Name: 
// Module Name:    controller 
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
module controller(
        input wire clk,
        input wire reset,
        input wire rx_empty,
        input wire tx_empty,
        input wire [7:0] rx_data,
        output reg [7:0] tx_data
    );


    // --------------- SQRT MODULE ---------------

    reg         nd = 0;
    reg [15:0]  x_in;
    wire [8:0]  x_out;
    wire rdy;

    sqrt sqrt_unit(
        .clk(clk), // input clk
        .nd(nd), // input nd
        .x_in(x_in), // input [15 : 0] x_in
        .x_out(x_out), // output [8 : 0] x_out
        .rdy(rdy) // output rdy
    );


    // --------------- RAM MODULE ---------------

    reg         wea = 1'b1;
    reg [11:0]  addra;
    reg [15:0]  dina;
    wire [15:0] douta;

    ram ram_unit(
        .clka(clk), // input clka
        .wea(wea), // input [0 : 0] wea
        .addra(addra), // input [11 : 0] addra
        .dina(dina), // input [15 : 0] dina
        .douta(douta) // output [15 : 0] douta
    );


    // --------------- INTERNAL VARIABLES ---------------

    reg [11:0]  addr_reg;
    reg [15:0]  data_reg;
    reg [2:0]   cur_state;

    parameter state_addrhi  = 3'b000;
    parameter state_addrlo  = 3'b001;
    parameter state_datahi  = 3'b010;
    parameter state_datalo  = 3'b011;
    parameter state_ramwr   = 3'b100;
    parameter state_ramhi   = 3'b101;
    parameter state_ramlo   = 3'b110;

    always @(posedge clk) begin

        if (reset) begin

            cur_state <= state_addrhi;

        end else begin

            $display("state %b", cur_state);

            case(cur_state)

                state_addrhi: begin

                    if (~rx_empty) begin

                        $display("controller %b", rx_data);
                        addr_reg <= rx_data;
                        cur_state <= state_addrlo;

                    end else begin

                        cur_state <= state_addrhi;

                    end

                end

                state_addrlo: begin

                    if (~rx_empty) begin

                        addr_reg <= {addr_reg[3:0], rx_data};
                        cur_state <= state_datahi;

                    end else begin

                        cur_state <= state_addrlo;

                    end

                end

                state_datahi: begin

                    if (~rx_empty) begin

                        data_reg <= rx_data;
                        cur_state <= state_datalo;

                    end else begin

                        cur_state <= state_datahi;

                    end

                end

                state_datalo: begin

                    if (~rx_empty) begin

                        // send data to sqrt module
                        x_in <= {data_reg, rx_data};
                        addra <= addr_reg;
                        cur_state <= state_ramwr;

                    end else begin

                        cur_state <= state_datalo;

                    end

                end

                state_ramwr: begin

                    // if sqrt is done
                    if (rdy) begin

                        addra <= addr_reg;
                        // data input to RAM
                        dina <= x_out;
                        wea <= 1;
                        cur_state <= state_ramhi;

                    end else begin

                        cur_state <= state_ramwr;

                    end

                end

                state_ramhi : begin

                    if (tx_empty && (^douta != 1'bx)) begin

                        tx_data <= douta[15:8];
                        cur_state <= state_ramlo;

                    end else begin

                        cur_state <= state_ramhi;

                    end

                end

                state_ramlo : begin

                    if (tx_empty && (^douta != 1'bx)) begin

                        tx_data <= douta[7:0];
                        cur_state <= state_addrhi;

                    end else begin

                        cur_state <= state_ramlo;

                    end

                end

            endcase

        end

    end

endmodule
