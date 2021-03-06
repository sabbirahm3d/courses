`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:30:32 10/09/2017 
// Design Name: 
// Module Name:    candle_controller 
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
module candle_controller(
        input wire [2:0] pos_to_set,
        input wire set_enable,
        input wire [2:0] pos_to_clear,
        input wire clear_enable,
        input wire sys_clk,
        input wire clr_async,
        output reg [7:0] candle_state
    );

    initial begin
        // initialize all the LEDs by setting them all to 0
        candle_state <= 8'b0;
    end

    always @(posedge sys_clk, posedge clr_async) begin

        if (clr_async) begin
            // asynchronous reset
            candle_state <= 8'b0;

        // if set is high and reset is don't care
        end else if (set_enable) begin

            // set the position indicated to 1
            case (pos_to_set)

                0: candle_state[0] <= 1'b1;
                1: candle_state[1] <= 1'b1;
                2: candle_state[2] <= 1'b1;
                3: candle_state[3] <= 1'b1;
                4: candle_state[4] <= 1'b1;
                5: candle_state[5] <= 1'b1;
                6: candle_state[6] <= 1'b1;
                7: candle_state[7] <= 1'b1;
                default: candle_state[0] <= 1'b1;

            endcase  // pos_to_set

        // if set is low and clear is high
        end else if (~set_enable && clear_enable) begin

            // set the position indicated to 0
            case (pos_to_clear)

                0: candle_state[0] <= 1'b0;
                1: candle_state[1] <= 1'b0;
                2: candle_state[2] <= 1'b0;
                3: candle_state[3] <= 1'b0;
                4: candle_state[4] <= 1'b0;
                5: candle_state[5] <= 1'b0;
                6: candle_state[6] <= 1'b0;
                7: candle_state[7] <= 1'b0;
                default: candle_state[0] <= 1'b0;

            endcase  // pos_to_clear

        end

    end

endmodule