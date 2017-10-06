`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:05:44 10/04/2017 
// Design Name: 
// Module Name:    part06_tb 
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
module part08_tb();

    reg a, b, clk;
    wire [1:0] y, z;

    part08 DUT(a, b, clk, y, z);

    always begin
        #1 clk = ~clk;
    end

    initial begin

        clk = 1;

        #1;
        $display("  time     a   b     y     z   ");
        $display("-------------------------------");

        a = 0;
        b = 0;

        #2
        $strobe("  %0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 0;
        b = 1;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 1;
        b = 0;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 1;
        b = 1;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);


        a = 0;
        b = 0;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 0;
        b = 1;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 1;
        b = 0;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

        #5
        a = 1;
        b = 1;

        #2
        $strobe("%0t    %b   %b   %b   %b", $time, a, b, y, z);

    end

    initial #50 $finish;

endmodule
