`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:30:32 10/09/2017 
// Design Name: 
// Module Name:    candle_controller 
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
module candle_controller(
        input wire [2:0] pos_to_set,
        input wire set_enable,
        input wire [2:0] pos_to_clear,
        input wire clear_enable,
        input wire sys_clk,
        input wire clr_async,
        output reg [7:0] candle_state
    );

    initial begin

        candle_state <= 8'b0;

    end

    always @(posedge sys_clk, clr_async, set_enable, pos_to_set) begin

        if (clr_async) begin
            candle_state <= 8'b0;
        end else if (set_enable) begin
            candle_state[pos_to_set] <= 1'b1;
        end
        $monitor("IN CANDLES candle: %b pos_set: %b active: %b", candle_state, pos_to_set, set_enable);

    end

    always @(posedge sys_clk, clr_async, clear_enable, pos_to_clear) begin

        if (clr_async) begin
            candle_state <= 8'b0;
        end else if (clear_enable) begin
            candle_state[pos_to_clear] <= 1'b0;
        end
        $monitor("IN CANDLES candle: %b pos_clear: %b active: %b", candle_state, pos_to_clear, clear_enable);

    end

endmodule
