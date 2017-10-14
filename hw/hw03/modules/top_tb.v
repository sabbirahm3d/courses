`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:20:27 10/11/2017 
// Design Name: 
// Module Name:    top_tb 
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
module top_tb;

    reg CLK_50MHZ;
    reg SW3, SW2, SW1, SW0;
    reg BTN_NORTH, RESET;
    wire LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0;

    top top_dt(
        .CLK_50MHZ(CLK_50MHZ),
        .SW3(SW3), .SW2(SW2),
        .SW1(SW1), .SW0(SW0),
        .BTN_NORTH(BTN_NORTH),
        .RESET(RESET),
        .LED7(LED7), .LED6(LED6),
        .LED5(LED5), .LED4(LED4),
        .LED3(LED3), .LED2(LED2),
        .LED1(LED1), .LED0(LED0)
    );

    always begin

        #20  // 50 MHz
        CLK_50MHZ <= ~CLK_50MHZ;

    end

    initial begin

        CLK_50MHZ = 0;
        RESET = 1;
        {SW3, SW2, SW1, SW0} = 4'b0101;
        BTN_NORTH = 1;
        #10
        RESET = 0;

        #20;
        {SW3, SW2, SW1, SW0} = 4'b0100;
        $monitor("%0t CANDLES: %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

        #20
        RESET = 0;

        #20;
        {SW3, SW2, SW1, SW0} = 4'b0101;
        $monitor("%0t CANDLES: %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

        #20
        RESET = 0;

        #20;
        {SW3, SW2, SW1, SW0} = 4'b0101;
        $monitor("%0t CANDLES: %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

        #20;
        {SW3, SW2, SW1, SW0} = 4'b0111;
        $monitor("%0t CANDLES: %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

        #20
        RESET = 0;

        #20;
        {SW3, SW2, SW1, SW0} = 4'b0101;
        $monitor("%0t CANDLES: %b", $time, {LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0});

        #80
        RESET = 1;

    end

    initial #2000 $finish;

endmodule
