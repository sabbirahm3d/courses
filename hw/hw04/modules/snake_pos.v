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
        input wire change_dir,
        input wire grow,
        input wire [1:0] dir,
        input wire interval,
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

    initial begin

        {snake_x4,snake_x3,snake_x2,snake_x1,snake_x0} = 5'b0;
        {snake_y4,snake_y3,snake_y2,snake_y1,snake_y0} = 5'b0;
        // snake_x = {31'b0, 1'b1};  // right
        // snake_y = {31'b0, 1'b1};  // right

    end

    always @(posedge clk) begin

        if (change_dir) begin

            if (dir == 0) begin

                next_x = snake_x0 + 1;
                next_y = snake_y0;
                $display("RIGHT %d", dir);

            end else if (dir == 1) begin

                next_x = snake_x0;
                next_y = snake_y0 - 1;
                $display("DOWN %d", dir);

            end else if (dir == 2) begin

                next_x = snake_x0 - 1;
                next_y = snake_y0;
                $display("LEFT %d", dir);

            end else if (dir == 3) begin

                next_x = snake_x0;
                next_y = snake_y0 + 1;
                $display("UP %d", dir);

            end

        end

        {snake_x4,snake_x3,snake_x2,snake_x1,snake_x0} <= 
            {snake_x3,snake_x2,snake_x1,snake_x0, next_x};

        {snake_y4,snake_y3,snake_y2,snake_y1,snake_y0} <= 
            {snake_y3,snake_y2,snake_y1,snake_y0, next_y};

    end

endmodule
