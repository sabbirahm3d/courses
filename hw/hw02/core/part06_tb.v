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
module part06_tb();

    reg a, b, clk;
    wire [1:0] y, z;

    part06 DUT(a, b, clk, y, z);

    always begin
        #1 clk = ~clk;
    end

    initial begin

    
        clk = 1;

        a = 1;
        b = 0;

        #4;
        $display("  time    clk  a   b   y     z   ");
        $strobe("  %0t    %d    %b   %b   %b   %b", $time, clk, a, b, y, z);
        // $strobe("%0t   %d   %b   %b   %b   %b\n", $time, clk, a, b, y, z);

        #5
        a = 0;
        b = 1;

        #2  // to demonstrate the register only updates at posedge
        $strobe("%0t    %d    %b   %b   %b   %b", $time, clk, a, b, y, z);
        // $strobe("%0t   %d   %b   %b   %b   %b\n", $time, clk, a, b, y, z);

        #1
        $strobe("%0t    %d    %b   %b   %b   %b", $time, clk, a, b, y, z);
        // $strobe("%0t   %d   %b   %b   %b   %b\n", $time, clk, a, b, y, z);

    end

    initial #15 $finish;

endmodule
