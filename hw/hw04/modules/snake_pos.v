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
        input wire clk, input wire grow, input wire dead,
        input wire [1:0] dir,
        output reg [8:0] snake_x0, output reg [8:0] snake_x1,
        output reg [8:0] snake_x2, output reg [8:0] snake_x3,
        output reg [8:0] snake_x4, output reg [8:0] snake_x5,
        output reg [8:0] snake_x6, output reg [8:0] snake_x7,
        output reg [8:0] snake_x8, output reg [8:0] snake_x9,
        output reg [8:0] snake_x10, output reg [8:0] snake_x11,
        output reg [8:0] snake_x12, output reg [8:0] snake_x13,
        output reg [8:0] snake_x14, output reg [8:0] snake_x15,
        output reg [8:0] snake_x16, output reg [8:0] snake_x17,
        output reg [8:0] snake_x18, output reg [8:0] snake_x19,
        output reg [8:0] snake_x20, output reg [8:0] snake_x21,
        output reg [8:0] snake_x22, output reg [8:0] snake_x23,
        output reg [8:0] snake_x24, output reg [8:0] snake_x25,
        output reg [8:0] snake_x26, output reg [8:0] snake_x27,
        output reg [8:0] snake_x28, output reg [8:0] snake_x29,
        output reg [8:0] snake_x30, output reg [8:0] snake_x31,
        output reg [8:0] snake_y0, output reg [8:0] snake_y1,
        output reg [8:0] snake_y2, output reg [8:0] snake_y3,
        output reg [8:0] snake_y4, output reg [8:0] snake_y5,
        output reg [8:0] snake_y6, output reg [8:0] snake_y7,
        output reg [8:0] snake_y8, output reg [8:0] snake_y9,
        output reg [8:0] snake_y10, output reg [8:0] snake_y11,
        output reg [8:0] snake_y12, output reg [8:0] snake_y13,
        output reg [8:0] snake_y14, output reg [8:0] snake_y15,
        output reg [8:0] snake_y16, output reg [8:0] snake_y17,
        output reg [8:0] snake_y18, output reg [8:0] snake_y19,
        output reg [8:0] snake_y20, output reg [8:0] snake_y21,
        output reg [8:0] snake_y22, output reg [8:0] snake_y23,
        output reg [8:0] snake_y24, output reg [8:0] snake_y25,
        output reg [8:0] snake_y26, output reg [8:0] snake_y27,
        output reg [8:0] snake_y28, output reg [8:0] snake_y29,
        output reg [8:0] snake_y30, output reg [8:0] snake_y31
    );

    reg [8:0] next_x, next_y;
    reg [4:0] size;
    reg [8:0] mask [31:0];
    parameter SEG_WIDTH = 20;
    parameter [8:0] ZEROS = {9{1'b0}};
    parameter [8:0] ONES = {9{1'b1}};

    initial begin

        // snake starts off at 0-length
        // the head is created after the initial clock cycle
        size = 0;

        // set all snake-x segments but the head to 0
        {
            snake_x31, snake_x30, snake_x29, snake_x28,
            snake_x27, snake_x26, snake_x25, snake_x24,
            snake_x23, snake_x22, snake_x21, snake_x20,
            snake_x19, snake_x18, snake_x17, snake_x16,
            snake_x15, snake_x14, snake_x13, snake_x12,
            snake_x11, snake_x10, snake_x9, snake_x8,
            snake_x7, snake_x6, snake_x5, snake_x4,
            snake_x3, snake_x2, snake_x1, snake_x0
        } = {
            {30{ZEROS}},  300
        };

        // set all snake-y segments but the head to 0
        {
            snake_y31, snake_y30, snake_y29, snake_y28,
            snake_y27, snake_y26, snake_y25, snake_y24,
            snake_y23, snake_y22, snake_y21, snake_y20,
            snake_y19, snake_y18, snake_y17, snake_y16,
            snake_y15, snake_y14, snake_y13, snake_y12,
            snake_y11, snake_y10, snake_y9, snake_y8,
            snake_y7, snake_y6, snake_y5, snake_y4,
            snake_y3, snake_y2, snake_y1, snake_y0
        } = {
            {30{ZEROS}}, 300
        };

        // initialize all the elements of the mask to 0 except the 0th one 
        {
            mask[31], mask[30], mask[29], mask[28],
            mask[27], mask[26], mask[25], mask[24],
            mask[23], mask[22], mask[21], mask[20],
            mask[19], mask[18], mask[17], mask[16],
            mask[15], mask[14], mask[13], mask[12],
            mask[11], mask[10], mask[9], mask[8],
            mask[7], mask[6], mask[5], mask[4],
            mask[3], mask[2], mask[1], mask[0]
        } = {
            {30{ZEROS}}, {1{ONES}}
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
                snake_x31, snake_x30, snake_x29, snake_x28,
                snake_x27, snake_x26, snake_x25, snake_x24,
                snake_x23, snake_x22, snake_x21, snake_x20,
                snake_x19, snake_x18, snake_x17, snake_x16,
                snake_x15, snake_x14, snake_x13, snake_x12,
                snake_x11, snake_x10, snake_x9, snake_x8,
                snake_x7, snake_x6, snake_x5, snake_x4,
                snake_x3, snake_x2, snake_x1, snake_x0
            } = ({
                    snake_x30, snake_x29, snake_x28, snake_x27,
                    snake_x26, snake_x25, snake_x24, snake_x23,
                    snake_x22, snake_x21, snake_x20, snake_x19,
                    snake_x18, snake_x17, snake_x16, snake_x15,
                    snake_x14, snake_x13, snake_x12, snake_x11,
                    snake_x10, snake_x9, snake_x8, snake_x7,
                    snake_x6, snake_x5, snake_x4, snake_x3,
                    snake_x2, snake_x1, snake_x0, next_x
                } & {
                    mask[31], mask[30], mask[29], mask[28],
                    mask[27], mask[26], mask[25], mask[24],
                    mask[23], mask[22], mask[21], mask[20],
                    mask[19], mask[18], mask[17], mask[16],
                    mask[15], mask[14], mask[13], mask[12],
                    mask[11], mask[10], mask[9], mask[8],
                    mask[7], mask[6], mask[5], mask[4],
                    mask[3], mask[2], mask[1], mask[0]
                });

            {
                snake_y31, snake_y30, snake_y29, snake_y28,
                snake_y27, snake_y26, snake_y25, snake_y24,
                snake_y23, snake_y22, snake_y21, snake_y20,
                snake_y19, snake_y18, snake_y17, snake_y16,
                snake_y15, snake_y14, snake_y13, snake_y12,
                snake_y11, snake_y10, snake_y9, snake_y8,
                snake_y7, snake_y6, snake_y5, snake_y4,
                snake_y3, snake_y2, snake_y1, snake_y0
            } = ({
                    snake_y30, snake_y29, snake_y28, snake_y27,
                    snake_y26, snake_y25, snake_y24, snake_y23,
                    snake_y22, snake_y21, snake_y20, snake_y19,
                    snake_y18, snake_y17, snake_y16, snake_y15,
                    snake_y14, snake_y13, snake_y12, snake_y11,
                    snake_y10, snake_y9, snake_y8, snake_y7,
                    snake_y6, snake_y5, snake_y4, snake_y3,
                    snake_y2, snake_y1, snake_y0, next_y
                } & {
                    mask[31], mask[30], mask[29], mask[28],
                    mask[27], mask[26], mask[25], mask[24],
                    mask[23], mask[22], mask[21], mask[20],
                    mask[19], mask[18], mask[17], mask[16],
                    mask[15], mask[14], mask[13], mask[12],
                    mask[11], mask[10], mask[9], mask[8],
                    mask[7], mask[6], mask[5], mask[4],
                    mask[3], mask[2], mask[1], mask[0]
                });

        end else if (grow && ~dead) begin

            size = size + 1;
            mask[size] = {9{ONES}};

        end

    end

endmodule
