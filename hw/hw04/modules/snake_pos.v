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
        input wire grow,
        input wire dead,
        input wire [1:0] dir,
        output reg [8:0] snake_x0,
        output reg [8:0] snake_x1,
        output reg [8:0] snake_x2,
        output reg [8:0] snake_x3,
        output reg [8:0] snake_x4,
        output reg [8:0] snake_y0,
        output reg [8:0] snake_y1,
        output reg [8:0] snake_y2,
        output reg [8:0] snake_y3,
        output reg [8:0] snake_y4
    );

    reg [8:0] next_x, next_y;
    reg [4:0] size;
    reg [8:0] mask [4:0];
    parameter SEG_WIDTH = 20;
    parameter [8:0] ZEROS = {9{1'b0}};
    parameter [8:0] ONES = {9{1'b1}};

    initial begin

        // snake starts off at 0-length
        // the head is created after the initial clock cycle
        size = 0;

        // set all snake-x segments but the head to 0
        {
            snake_x4,
            snake_x3,
            snake_x2,
            snake_x1,
            snake_x0
        } = {
            {4{ZEROS}},  300
        };

        // set all snake-y segments but the head to 0
        {
            snake_y4,
            snake_y3,
            snake_y2,
            snake_y1,
            snake_y0
        } = {
            {4{ZEROS}}, 300
        };

        // initialize all the elements of the mask to 0 except the 0th one 
        {
            mask[4],
            mask[3],
            mask[2],
            mask[1],
            mask[0]
        } = {
            {4{ZEROS}}, {1{ONES}}
        };

    end

    always @(posedge clk) begin

        if (~grow && ~dead) begin

            if (dir == 0) begin

                next_x = snake_x0 + SEG_WIDTH;
                next_y = snake_y0;
                $display("RIGHT");

            end else if (dir == 1) begin

                next_x = snake_x0;
                next_y = snake_y0 - SEG_WIDTH;
                $display("DOWN");

            end else if (dir == 2) begin

                next_x = snake_x0 - SEG_WIDTH;
                next_y = snake_y0;
                $display("LEFT");

            end else if (dir == 3) begin

                next_x = snake_x0;
                next_y = snake_y0 + SEG_WIDTH;
                $display("UP");

            end

            {
            snake_x4,
            snake_x3,
            snake_x2,
            snake_x1,
            snake_x0
            } = ({
                    snake_x3,
                    snake_x2,
                    snake_x1,
                    snake_x0,
                    next_x
                } & {
                    mask[4],
                    mask[3],
                    mask[2],
                    mask[1],
                    mask[0]
                });

            {
            snake_y4,
            snake_y3,
            snake_y2,
            snake_y1,
            snake_y0
            } = ({
                    snake_y3,
                    snake_y2,
                    snake_y1,
                    snake_y0,
                    next_y
                } & {
                    mask[4],
                    mask[3],
                    mask[2],
                    mask[1],
                    mask[0]
                });

        end else if (grow && ~dead) begin

            size = size + 1;
            mask[size] = {9{ONES}};

        end

    end

endmodule
