`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:53:38 10/03/2017 
// Design Name: 
// Module Name:    part06 
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
module part08(a, b, clk, y, z);

    input a, b, clk;
    output reg [1:0] y, z;

    always @(posedge clk) begin
        y = 2'b00;
        $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
        if (a == 1) begin
            y[1] <= 1'b1;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
            y[0] <= 1'bx;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
            z <= 2'b01;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
        end else if (b == 1) begin
            y[0] <= 1'b0;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
            y[1] <= 1'b0;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
            z <= 2'b10;
            $display("%0t    %b   %b   %b   %b", $time, a, b, y, z);
        end
    end

endmodule
