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
        output wire LED7, output wire LED6,
        output wire LED5, output wire LED4,
        output wire LED3, output wire LED2,
        output wire LED1, output wire LED0
    );

    wire active, enable;
    wire [2:0] pos_to_set, pos_to_clear;

    debounce_and_oneshot debounce_and_oneshot_instance(
        .debounced_out(enable),
        .btn(BTN_NORTH),
        .clk(CLK_50MHZ),
        .rst(RESET)
    );

    igniter igniter_instance(
        .delta({SW3, SW2, SW1, SW0}),
        .enable_jump(BTN_NORTH),
        .sys_clk(CLK_50MHZ),
        .clr_n(RESET),
        .position(pos_to_set)
    );

    extinguisher extinguisher_instance(
        .enable(BTN_NORTH),
        .clk(CLK_50MHZ),
        .clr_n(RESET),
        .active(active),
        .position(pos_to_clear)
    );

    candle_controller candle_controller_instance(
        .pos_to_set(pos_to_set),
        .set_enable(BTN_NORTH),
        .pos_to_clear(pos_to_clear),
        .clear_enable(active),
        .sys_clk(CLK_50MHZ),
        .clr_async(RESET),
        .candle_state({LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0})
    );

endmodule
