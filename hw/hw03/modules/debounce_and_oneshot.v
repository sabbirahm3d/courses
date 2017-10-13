`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:29:41 02/13/2016 
// Design Name: 
// Module Name:    debounce_and_oneshot 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
module debounce_and_oneshot(
        output reg debounced_out,
        input wire btn,
        input wire clk,
        input wire rst
    );

    parameter MINWIDTH = 50; //how many cycles must the btn be pressed
    parameter COUNTERWIDTH = 32;

    reg [COUNTERWIDTH - 1:0] counter;

    reg shot;

    always @(posedge clk, posedge rst) begin

        if (rst) begin

            counter <= 0;
            debounced_out <= 1'b0;
            shot <= 1'b0;

        end else begin

            if (~btn) begin
                counter <= 0;
                debounced_out <= 1'b0;
                shot <= 1'b0;
            end else if (counter != MINWIDTH) begin
                counter <= counter + 1;
                debounced_out <= 1'b0;
                shot <= 1'b0;
            end else begin // we have reached MINWIDTH
                counter <= counter;
                if (shot == 0) begin
                    shot <= 1'b1;
                    debounced_out <= 1'b1;
                end else begin 
                    shot <= shot;
                    debounced_out <= 1'b0;
                end
            end

        end

    end //end always


endmodule