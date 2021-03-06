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

        #20  // 50 MHz
        clk <= ~clk;
        #10  // shuffle the enable as well
        enable = ~enable;

    end

    initial begin

        clk = 0;
        enable = 1;
        clr_n = 0;
        #10;

        #30
        $monitor("%0t %b %d", $time, position, active);

        #30
        $monitor("%0t %b %d", $time, position, active);

        #30
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 0;
        #10;
        clr_n = 1;

        #80
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 0;
        #30
        clr_n = 1;
        $monitor("%0t %b %d", $time, position, active);

        #20
        $monitor("%0t %b %d", $time, position, active);

        clr_n = 0;
        #10;
        clr_n = 1;

        #80
        $monitor("%0t %b %d", $time, position, active);

        #20
        $monitor("%0t %b %d", $time, position, active);

        #20
        $monitor("%0t %b %d", $time, position, active);

    end

    initial #200000 $finish;

endmodule
