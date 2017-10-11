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

    initial begin

        input wire [3:0] delta,
        input wire enable_jump,
        input wire sys_clk,
        input wire clr_n,
        output reg [2:0] position


        igniter igniter_mod(
            delta,
            enable_jump,
            sys_clk,
            clr_n,
            position
        );

    end

    always @(posedge CLK_50MHZ) begin

        wire [3:0] delta;
        wire enable_jump;
        wire sys_clk;
        wire clr_n;
        reg [2:0] position;


    end

endmodule
