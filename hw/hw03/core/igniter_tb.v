`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:23:55 10/10/2017 
// Design Name: 
// Module Name:    igniter_tb 
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
module igniter_tb;

    reg [3:0] delta;
    reg enable_jump, clk, clr_n;
    wire [2:0] position;

    igniter igniter_reg(
        .delta(delta),
        .enable_jump(enable_jump),
        .sys_clk(clk),
        .clr_n(clr_n),
        .position(position)
    );

    always begin

        #20;
        clk <= ~clk;
        #25
        enable_jump <= ~enable_jump;

    end

    initial begin

        delta = 4'b0;
        clk = 0;
        enable_jump = 0;
        #20

        delta = 4'b0010;
        #40

        delta = 4'b0011;
        #40

        delta = 4'b0110;
        #40

        delta = 4'b0010;
        #40

        delta = 4'b0010;
        #40

        delta = 4'b0010;
        #40

        delta = 4'b0010;
        #40;

    end

    initial #1000 $finish;

endmodule
