`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:29:42 10/05/2017 
// Design Name: 
// Module Name:    part11_struct_tb 
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
module part11_struct_tb;

    // reg [1:0] a, b;
    // reg sub;
    // wire [1:0] y;
    // wire c;

    part11_struct alu(a, b, sub, y, c);

    initial begin

        a = 2'b01;
        b = 2'b01;
        sub = 0;
        // carryin = 2'b01;
        #20; a = 2'b11;
        #20; b = 2'b11;
        #20; a = 2'b01;
        // #20; carryin =1;
        sub = 1;
        #20; b = 2'b01;
        #20; a = 2'b11; 
        #20; b = 2'b11;
        #40;

    end

    initial begin
        $monitor("time = %0t, IN1=%1b, IN2=%1b, OUT=%1b", $time, b, a, y);
    end

endmodule
