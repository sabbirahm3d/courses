`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:45:03 10/22/2017 
// Design Name: 
// Module Name:    snake
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
//////////////////////////////////////////////////////////////////////////////
module snake_pos(
        input wire clk,
        input wire grow, input wire die,
        input wire enable, input wire rst,
        input wire [1:0] dir,
        output reg [4:0] head_x, output reg [4:0] head_y,
        output reg [4:0] snake_x1, output reg [4:0] snake_y1,
        output reg [4:0] snake_x2, output reg [4:0] snake_y2,
        output reg [4:0] snake_x3, output reg [4:0] snake_y3,
        output reg [4:0] snake_x4, output reg [4:0] snake_y4
    );

    reg [4:0] next_x, next_y;  // new position for the head
    reg [2:0] size;  // total size of the snake body including its head
    reg [4:0] mask [4:0];  // an array of mask
    parameter SEG_WIDTH = 20;  // width of a segment
    parameter [4:0] ZEROS = {5{1'b0}};  // array of zeros
    parameter [4:0] ONES = {5{1'b1}};  // array of ones

    // initial coordinates of the head (24)
    parameter [4:0] INIT = 5'b11000;

    initial begin

        // snake starts off at 0-length
        // the head is created after the initial clock cycle
        size = 0;

        // set all snake-x segments but the head to 0
        {
            snake_x4, snake_x3, snake_x2, snake_x1, head_x
        } = {
            {4{ZEROS}}, INIT
        };

        // set all snake-y segments but the head to 0
        {
            snake_y4, snake_y3, snake_y2, snake_y1, head_y
        } = {
            {4{ZEROS}}, INIT
        };

        // initialize all the elements of the mask to 0 except the 0th one 
        {   
            mask[4], mask[3], mask[2], mask[1], mask[0]
        } = {
            {4{ZEROS}}, {1{ONES}}
        };

    end

    always @(posedge clk) begin

        // if the snake is not die and not growing, it will continue moving in
        // the desired direction
        if (enable) begin

            if (~grow && ~die) begin

                if (dir == 0) begin

                    next_x = head_x + SEG_WIDTH;
                    next_y = head_y;
                    $display("RIGHT");

                end else if (dir == 1) begin

                    next_x = head_x;
                    next_y = head_y - SEG_WIDTH;
                    $display("DOWN");

                end else if (dir == 2) begin

                    next_x = head_x - SEG_WIDTH;
                    next_y = head_y;
                    $display("LEFT");

                end else if (dir == 3) begin

                    next_x = head_x;
                    next_y = head_y + SEG_WIDTH;
                    $display("UP");

                end

                // shift left the x segments, then mask it
                {
                    snake_x4, snake_x3, snake_x2, snake_x1, head_x
                } = ({
                        snake_x3, snake_x2, snake_x1, head_x, next_x
                    } & {
                        mask[4], mask[3], mask[2], mask[1], mask[0]
                    });

                // shift left the y segments, then mask it
                {
                    snake_y4, snake_y3, snake_y2, snake_y1, head_y
                } = ({
                        snake_y3, snake_y2, snake_y1, head_y, next_y
                    } & {
                        mask[4], mask[3], mask[2], mask[1], mask[0]
                    });

            // if the snake is growing
            end else if (grow && ~die) begin

                // increment the size
                size = size + 1;
                // mask the new segment with 1
                mask[size] = {5{ONES}};

            // if the snake is dead, do nothing with the segments
            end else begin
                $display("DEAD");
            end

        end  // enable

    end

endmodule
