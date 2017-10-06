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

    integer dump_file;
    reg clk;
    reg rst;
    wire [15:0] out;
    part10_linear_shift_reg DUT(clk, rst, out);

    initial begin

        dump_file = $fopen("linear_shift_reg_dump.txt", "w");
        clk = 0;
        rst = 1;
        #1;
        rst = 0;

        // open file to dump test bench output
        $fmonitor(dump_file, "%b", out);
        $monitor("%b", out);

        // wait long enough for at least 2 full cycles
        // #266000

        // close file

        // terminate test bench simulation
        $fclose(dump_file);

    end

    always begin
        #1;
        clk = ~clk;
    end

    // initial #266000 $fclose(dump_file);
    initial #266000 $finish;

endmodule
