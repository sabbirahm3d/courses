`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:43:21 10/09/2017 
// Design Name: 
// Module Name:    extinguisher_tb 
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
module extinguisher_tb;

    reg enable;
    reg clk;
    reg clr_n;
    wire active;
    wire [2:0] position;

    extinguisher extinguisher_dut(
        .enable(enable),
        .clk(clk),
        .clr_n(clr_n),
        .active(active),
        .position(position)
    );

    always begin

        #20;
        clk <= ~clk;

    end

    initial begin

        clk = 0;
        enable = 1;
        clr_n = 1;
        #10;
        clr_n = 0;

        enable = 0;
        #30
        $monitor("%0t %b %d", $time, position, active);

        #30
        $monitor("%0t %b %d", $time, position, active);

        enable = 0;
        #30
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 1;
        #10;
        clr_n = 0;

        enable = 1;
        #80
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 1;
        #30
        clr_n = 0;
        $monitor("%0t %b %d", $time, position, active);

        enable = 1;
        #20
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 1;
        #10;
        clr_n = 0;

        enable = 1;
        #80
        $monitor("%0t %b %d", $time, position, active);

        enable = 0;
        #20
        $monitor("%0t %b %d", $time, position, active);

        enable = 1;
        #20
        $monitor("%0t %b %d", $time, position, active);

    end

    initial #200000 $finish;

endmodule
