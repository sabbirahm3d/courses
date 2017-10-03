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
	reg s;
	wire y;

	part03 DUT(x, s, y);

	initial begin

        // bitwise AND reduction
        s = 0;

        x = 4'b1001;
        #1
        $display(" & 4'b1001 = %b", y);

        x = 4'bx111;
        #1
        $display(" & 4'bx111 = %b", y);

        x = 4'bz111;
        #1
        $display(" & 4'bz111 = %b", y);


        // bitwise OR reduction
        s = 1;

        x = 4'b1001;
        #1
        $display(" | 4'b1001 = %b", y);

        x = 4'bx001;
        #1
        $display(" | 4'bx001 = %b", y);

        x = 4'bz001;
        #1
        $display(" | 4'bz001 = %b", y);

        // bitwise XOR reduction
        s = 2;

        x = 4'b1001;
        #1
        $display(" ^ 4'b1001 = %b", y);

        x = 4'bx000;
        #1
        $display(" ^ 4'bx000 = %b", y);

        x = 4'bz000;
        #1
        $display(" ^ 4'bz000 = %b", y);

        // bitwise NAND reduction
        s = 3;

        x = 4'b1001;
        #1
        $display(" ~& 4'b1001 = %b", y);

        x = 4'bx001;
        #1
        $display(" ~& 4'bx001 = %b", y);

        x = 4'bz001;
        #1
        $display(" ~& 4'bz001 = %b", y);

        // bitwise NOR reduction
        s = 4;

        x = 4'b1001;
        #1

        $display(" ~| 4'b1001 = %b", y);

        x = 4'bx001;
        #1
        $display(" ~| 4'bx001 = %b", y);

        x = 4'bz001;
        #1
        $display(" ~| 4'bz001 = %b", y);

        #2 $finish;
	end

endmodule
