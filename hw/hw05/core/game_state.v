`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:04:53 11/13/2017 
// Design Name: 
// Module Name:    game_state 
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
module game_state(
        input wire clk, // clk
        input wire rst, // Active high, syn rst
        input wire [4:0] head_x, input wire [4:0] snake_x1,
        input wire [4:0] snake_x2, input wire [4:0] snake_x3,
        input wire [4:0] snake_x4, input wire [4:0] head_y,
        input wire [4:0] snake_y1, input wire [4:0] snake_y2,
        input wire [4:0] snake_y3, input wire [4:0] snake_y4,
        input wire [4:0] food_x, input wire [4:0] food_y,
        output reg grow, output reg die
    );

    //-------------Internal Constants--------------------------
    parameter   state_lvl0 = 2'b00,
                state_lvl1 = 2'b01,
                state_lvl2 = 2'b10,
                state_lvl3 = 2'b11;
    //-------------Internal Variables---------------------------
    reg [1:0] curr_state;  // Seq part of the FSM
    reg [1:0] next_state;  // combo part of FSM

    reg [4:0] obj_x, obj_y;
    reg [2:0] bites = 3'b0;
    wire is_collision;
    reg collided_flag;
    integer obs_num;

    collision check_col(
        .clk(clk),
        .head_x(head_x), .head_y(head_y),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4),
        .obj_x(obj_x), .obj_y(obj_y),
        .is_collision(is_collision)
    );

    always @(posedge clk) begin

        next_state = 2'b00;

        case(curr_state)

            state_lvl0: begin

                if ((bites == 5) && ~is_collision) begin
                    next_state <= state_lvl1;
                    bites <= 3'b0;
                end else begin
                    die <= 1;
                    next_state <= state_lvl0;
                end

            end

            state_lvl1: begin

                for (obs_num = 1; obs_num < 11; obs_num = obs_num + 1) begin:

                    obs_coords1 obstacle(
                        clk,
                        obs_num,
                        obj_x, obj_y
                    );

                    if (~is_collision) begin
                        collided_flag <= 1;
                    end

                end

                if ((bites == 5) && ~collided_flag) begin
                    next_state <= state_lvl2;
                    bites <= 3'b0;
                end else begin
                    die <= 1;
                    next_state <= state_lvl0;
                end

            end

            state_lvl2: begin

                for (obs_num = 11; obs_num < 21; obs_num = obs_num + 1) begin:

                    obs_coords2 obstacle(
                        clk,
                        obs_num,
                        obj_x, obj_y
                    );

                    if (~is_collision) begin
                        collided_flag <= 1;
                    end

                end

                if ((bites == 5) && ~collided_flag) begin
                    next_state <= state_lvl3;
                    bites <= 3'b0;
                end else begin
                    die <= 1;
                    next_state <= state_lvl0;
                end

            end

            state_lvl3: begin

                for (obs_num = 21; obs_num < 31; obs_num = obs_num + 1) begin:

                    obs_coords3 obstacle(
                        clk,
                        obs_num,
                        obj_x, obj_y
                    );

                    if (~is_collision) begin
                        collided_flag <= 1;
                    end

                end

                if ((bites == 5) && ~collided_flag) begin
                    next_state <= state_lvl3;
                    bites <= 3'b0;
                end else begin
                    die <= 1;
                    next_state <= state_lvl0;
                end

            end

            default: begin
                curr_state <= state_lvl0;
            end

        endcase

    end

    //----------Seq Logic-----------------------------
    always @ (posedge clk) begin

        if ((head_x == food_x) && (head_y == food_y)) begin
            bites <= bites + 1;
            grow <= 1;
        end

    end

endmodule
