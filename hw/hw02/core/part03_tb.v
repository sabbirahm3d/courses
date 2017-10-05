`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:28:52 10/03/2017 
// Design Name: 
// Module Name:    part03_tb 
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
module part03_tb();

	reg [3:0] x; 
	reg [2:0] s;
	wire y;

	part03 DUT(x, s, y);

	initial begin

        // bitwise AND reduction
        s = 0;

        x = 4'b1001;
        #1
        $display(" & %b = %b", x, y);

        x = 4'b1111;
        #1
        $display(" & %b = %b", x, y);

        x = 4'b1110;
        #1
        $display(" & %b = %b\n", x, y);


        // bitwise OR reduction
        s = 1;

        x = 4'b1001;
        #1
        $display(" | %b = %b", x, y);

        x = 4'b0000;
        #1
        $display(" | %b = %b", x, y);

        x = 4'b1110;
        #1
        $display(" | %b = %b\n", x, y);

        // bitwise XOR reduction
        s = 2;

        x = 4'b1001;
        #1
        $display(" ^ %b = %b", x, y);

        x = 4'b1111;
        #1
        $display(" ^ %b = %b", x, y);

        x = 4'b1110;
        #1
        $display(" ^ %b = %b\n", x, y);

        // bitwise NAND reduction
        s = 3;

        x = 4'b1001;
        #1
        $display(" ~& %b = %b", x, y);

        x = 4'b1111;
        #1
        $display(" ~& %b = %b", x, y);

        x = 4'b1110;
        #1
        $display(" ~& %b = %b\n", x, y);

        // bitwise NOR reduction
        s = 4;

        x = 4'b1001;
        #1

        $display(" ~| %b = %b", x, y);

        x = 4'b0000;
        #1
        $display(" ~| %b = %b", x, y);

        x = 4'b1110;
        #1
        $display(" ~| %b = %b\n", x, y);

	end
	
	initial #16 $finish;

endmodule
