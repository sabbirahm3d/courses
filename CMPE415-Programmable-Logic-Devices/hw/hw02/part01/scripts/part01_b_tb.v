//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:16:32 10/01/2017 
// Design Name: 
// Module Name:    part01_test 
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
module part01_b_tb();

    reg a, b, c;
    wire y, z;

    part01_b DUT(a, b, c, y, z);

    initial begin

        a = 1;
        b = 1;
        c = 1;

        #1
        a = 1;
        b = 0;
        c = 0;
        
        #1
        a = 1;
        b = 1;
        c = 0;

        #1
        a = 0;
        b = 0;
        c = 0;

    end

    initial #4 $finish;

endmodule
