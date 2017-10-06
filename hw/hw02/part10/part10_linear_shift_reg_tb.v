`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:05:23 10/05/2017 
// Design Name: 
// Module Name:    part10_linear_shift_reg_tb 
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
module part10_linear_shift_reg_tb;

    reg clk;
    reg rst;
    wire [15:0] out;
    part10_linear_shift_reg DUT(clk, rst, out);

    initial begin

        clk = 0;
        rst = 1;
        #1;
        rst = 0;

        // dump test bench output
        $monitor("%b", out);

    end

    always begin
        #1;
        clk = ~clk;
    end

    // initial #266000 $fclose(dump_file);
    initial #266000 $finish;

endmodule
