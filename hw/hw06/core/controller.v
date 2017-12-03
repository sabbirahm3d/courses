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
        output reg [7:0] tx_data,

        input wire ram_ready,
        output reg ram_wea,
        output reg [11:0] ram_addr,
        output reg [15:0] ram_data_in,
        input wire [15:0] ram_data_out,

        input wire sqrt_ready,
        output reg sqrt_nd,
        input wire [15:0] sqrt_out,
        output reg [15:0] sqrt_in
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

            cur_state = state_addrhi;

        end else begin

            case(cur_state)

                state_addrhi: begin

                    if (~rx_empty) begin

                        addr_reg = rx_data;
                        cur_state = state_addrlo;

                    end else begin

                        cur_state = state_addrhi;

                    end

                end

                state_addrlo: begin

                    if (~rx_empty) begin

                        addr_reg = {addr_reg[3:0], rx_data};
                        // $display("controller2 %b", addr_reg);
                        cur_state = state_datahi;

                    end else begin

                        cur_state = state_addrlo;

                    end

                end

                state_datahi: begin

                    if (~rx_empty) begin

                        data_reg = rx_data;
                        // $display("controller3 %b", data_reg);
                        cur_state = state_datalo;

                    end else begin

                        cur_state = state_datahi;

                    end

                end

                state_datalo: begin

                    if (~rx_empty) begin

                        // send data to sqrt module
                        sqrt_in = {data_reg, rx_data};
                        sqrt_nd = 1;
                        cur_state = state_ramwr;

                    end else begin

                        cur_state = state_datalo;

                    end

                end

                state_ramwr: begin

                    // if sqrt is done
                    if (sqrt_ready) begin

                        ram_addr = addr_reg;
                        // data input to RAM
                        ram_data_in = sqrt_out;
                        ram_wea = 1;
                        cur_state = state_ramhi;

                    end else begin

                        cur_state = state_ramwr;

                    end

                end

                state_ramhi : begin

                    if (tx_empty && (^ram_data_out != 1'bx)) begin

                        tx_data = ram_data_out[15:8];
                        cur_state = state_ramlo;

                    end else begin

                        cur_state = state_ramhi;

                    end

                end

                state_ramlo : begin

                    if (tx_empty && (^ram_data_out != 1'bx)) begin

                        tx_data = ram_data_out[7:0];
                        cur_state = state_addrhi;

                    end else begin

                        cur_state = state_ramlo;

                    end

                end

            endcase

        end

    end

endmodule
