`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:56:19 10/03/2017 
// Design Name: 
// Module Name:    part05_tb 
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
module part05_tb();

    reg [63:0] x;
    reg clk;
    wire [63:0] u;

    part05 DUT(x, clk, u);

    always begin
        #1 clk = ~clk;
    end

    initial begin
    
        clk = 1;

        x = {32{2'b01}};

        #3
        $display("x = %b when clk = %d", x, clk);
        $display("u = %b when clk = %d", u, clk);

        x = {16{4'b1101}};

        #2
        $display("x = %b when clk = %d", x, clk);
        $display("u = %b when clk = %d", u, clk);

        #1  // to demonstrate the swapping of bits only at posedge of clk
        $display("x = %b when clk = %d", x, clk);
        $display("u = %b when clk = %d", u, clk);

        x = {16{4'b0010}};

        #3
        $display("x = %b when clk = %d", x, clk);
        $display("u = %b when clk = %d", u, clk);

    end

    initial #10 $finish;

endmodule