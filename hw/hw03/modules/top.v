`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:51:31 10/11/2017 
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
module top(
        input wire CLK_50MHZ,
        input wire SW3, input wire SW2,
        input wire SW1, input wire SW0,
        input wire BTN_NORTH, input wire RESET,
        output reg LED7, output reg LED6,
        output reg LED5, output reg LED4,
        output reg LED3, output reg LED2,
        output reg LED1, output reg LED0
    );

    reg active;
    wire [2:0] pos_to_set, pos_to_clear;
    // wire [7:0] candle_state;

    igniter igniter_dut(
        .delta({SW3, SW2, SW1, SW0}),
        .enable_jump(BTN_NORTH),
        .sys_clk(CLK_50MHZ),
        .clr_n(RESET),
        .position(pos_to_set)
    );

    initial begin

        // pos_to_set <= 3'bx;
        // pos_to_clear <= 3'bx;
        active <= 0;
        {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0} <= 8'b0;

    end

    extinguisher extinguisher_dut(
        .enable(BTN_NORTH),
        .clk(CLK_50MHZ),
        .clr_n(RESET),
        .active(active),
        .position(pos_to_clear)
    );

    candle_controller candle_controller_dut(
        .pos_to_set(pos_to_set),
        .set_enable(BTN_NORTH),
        .pos_to_clear(pos_to_clear),
        .clear_enable(active),
        .sys_clk(CLK_50MHZ),
        .clr_async(RESET),
        .candle_state({LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0})
    );

    always @(posedge CLK_50MHZ) begin

        $display("DELTA %b set: %b clear: %b", {SW3, SW2, SW1, SW0}, pos_to_set, pos_to_clear);
        // $display("ACTIVE %b", active);
        // $display("CANDLES %b", candle_state);
        $display("%0t YOOOOOOOOOO %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

    end


endmodule
