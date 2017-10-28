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
    parameter [8:0] zeros = {9{1'b0}};
    parameter [8:0] ones = {9{1'b1}};

    initial begin

        {snake_x4,snake_x3,snake_x2,snake_x1,snake_x0} = {{4{zeros}}, {1{ones}}};
        {snake_y4,snake_y3,snake_y2,snake_y1,snake_y0} = {{4{zeros}}, {1{ones}}};
        size = 0;
        {mask[4],mask[3],mask[2],mask[1],mask[0]} = {{4{zeros}}, {1{ones}}};

    end

    always @(posedge clk) begin

        if (~grow) begin

            if (dir == 0) begin

                next_x = snake_x0 + 1;
                next_y = snake_y0;
                // $display("RIGHT %d", dir);

            end else if (dir == 1) begin

                next_x = snake_x0;
                next_y = snake_y0 - 1;
                // $display("DOWN %d", dir);

            end else if (dir == 2) begin

                next_x = snake_x0 - 1;
                next_y = snake_y0;
                // $display("LEFT %d", dir);

            end else if (dir == 3) begin

                next_x = snake_x0;
                next_y = snake_y0 + 1;
                // $display("UP %d", dir);

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

        end else if (grow) begin

            size = size + 1;
            mask[size] = {9{1'b1}};

        end

    end

endmodule
