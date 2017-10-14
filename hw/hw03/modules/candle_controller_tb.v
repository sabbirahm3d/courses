`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:58:20 10/10/2017 
// Design Name: 
// Module Name:    candle_controller_tb 
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
module candle_controller_tb;

    reg [2:0] pos_to_set, pos_to_clear;
    reg set_enable, clear_enable;
    reg clk, clr_async;
    wire [7:0] candle_state;

    candle_controller candle_controller_dut(
        .pos_to_set(pos_to_set),
        .set_enable(set_enable),
        .pos_to_clear(pos_to_clear),
        .clear_enable(clear_enable),
        .sys_clk(clk),
        .clr_async(clr_async),
        .candle_state(candle_state)
    );

    always begin

        #20  // 50 MHz
        clk <= ~clk;

    end

    initial begin

        // start off with set_enable on and clear_enable off
        clk = 0;
        set_enable = 1;
        clear_enable = 0;
        clr_async = 0;

        #20
        pos_to_set = 3'b001;

        #20
        pos_to_set = 3'b010;

        #20
        pos_to_set = 3'b101;

        #20
        set_enable = 0;
        clear_enable = 1;

        #20
        pos_to_clear = 3'b101;

        #20
        pos_to_clear = 3'b001;

        #20
        pos_to_clear = 3'b010;

        #20
        pos_to_clear = 3'b110;

        #30
        set_enable = 1;
        clear_enable = 0;

        #20
        pos_to_set = 3'b000;
          
        #30
        set_enable = 0;
        clear_enable = 1;

        #20
        clr_async = 1;

    end

    initial #1500 $finish;

endmodule
