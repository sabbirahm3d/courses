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
        input wire clk,
        input wire rst, input wire enable,
        input wire [4:0] head_x, input wire [4:0] head_y,
        input wire [4:0] snake_x3, input wire [4:0] snake_y3,
        input wire [4:0] snake_x4, input wire [4:0] snake_y4,
        input wire [4:0] food_x, input wire [4:0] food_y,
        output reg grow, output reg die,
        output reg [1:0] level, output reg rst_size
    );

    // ---------------------- internal constants ----------------------
    parameter   state_lvl0 = 2'b00,
                state_lvl1 = 2'b01,
                state_lvl2 = 2'b10,
                state_lvl3 = 2'b11;

    // ---------------------- internal variables ----------------------
    reg [1:0] state;
    reg [2:0] bites = 3'b0;
    reg [4:0] obs_num;

    // ---------------------- collision variables ----------------------
    reg [4:0] obj_x, obj_y;
    wire is_collision;

    // instantiate the collision module
    collision check_col(
        .clk(clk),
        .head_x(head_x), .head_y(head_y),
        .snake_x3(snake_x3), .snake_y3(snake_y3),
        .snake_x4(snake_x4), .snake_y4(snake_y4),
        .obj_x(obj_x), .obj_y(obj_y),
        .is_collision(is_collision)
    );

    // ---------------------- LCD variables ----------------------

    // ASCII values
    parameter   CHAR_L = 76,
                CHAR_E = 69,
                CHAR_0 = 48,
                CHAR_1 = 49;

    reg [7:0] dis_char = CHAR_L;
    reg [1:0] dis_pos = 2'b0;

    // instantiate the LCD driver module - its outputs are set as no-connects
    LCDDriver lcd(
        .clk(clk),
        .rst(rst),
        .start_write(enable),
        .dis_pos(dis_pos),
        .dis_char(dis_char)
    );

    // ---------------------- sequential state machine ----------------------
    always @(posedge clk) begin

        if (rst) begin  // reset current state to state 0
            state <= state_lvl0;
            level <= 2'b0;
            obs_num <= 5'b0;
            dis_pos <= 2'b0;
            die <= 0;

        end else begin

            case(state)

                state_lvl0: begin  // level 0 with no obstacles

                    dis_pos <= dis_pos + 1;  // increment position to 2 and 3
                    dis_char <= CHAR_0;  // append '0', '0'

                    // no collisions with fence and 5 bites
                    if ((bites == 5) && ~is_collision) begin
                        state <= state_lvl1;
                        bites <= 3'b0;

                    // collision with fence
                    end else begin

                        // increment again to the last index of the LCD and
                        // append 'E'
                        dis_pos <= dis_pos + 1;
                        dis_char <= CHAR_E;

                        // back to state 0
                        state <= state_lvl0;

                        die <= 1;

                    end

                end

                state_lvl1: begin  // level 1 with 10 obstacles

                    dis_pos <= dis_pos + 1;  // increment position to 2 and 3

                    // append '0' then '1'
                    if (dis_pos == 2)
                        dis_char <= CHAR_0;
                    else
                        dis_char <= CHAR_1;

                    level <= 1;

                    // increment the number of obstacles and initialize
                    // coordinate points to each of them
                    obs_num <= obs_num + 1;
                    obj_x <= obs_num * 10 + 10;
                    obj_y <= obs_num * 5 + 10;

                    // no collisions with fence, 5 bites and number of
                    // obstacles is at its maximum
                    if ((bites == 5) && ~is_collision && obs_num == 10) begin

                        // move on to level 2
                        state <= state_lvl2;

                        // reset number of bites and size of snake
                        bites <= 3'b0;
                        rst_size <= 1;

                    // number of obstacles not at max yet
                    end else if (
                        (bites < 5) && ~is_collision && obs_num < 10) begin
                        state <= state_lvl1;

                    end else if (is_collision) begin

                        // increment again to the last index of the LCD and
                        // append 'E'
                        dis_pos <= dis_pos + 1;
                        dis_char <= CHAR_E;

                        // back to state 0
                        state <= state_lvl0;

                        die <= 1;

                    end

                end

                state_lvl2: begin  // level 2 with 20 obstacles

                    dis_pos <= dis_pos + 1;  // increment position to 2 and 3

                    // append '1' then '0'
                    if (dis_pos == 2)
                        dis_char <= CHAR_1;
                    else
                        dis_char <= CHAR_0;

                    level <= 2;

                    obs_num <= obs_num + 1;

                    obj_x <= obs_num * 10 + 10;
                    obj_y <= obs_num * 5 + 10;

                    // no collisions with fence, 5 bites and number of
                    // obstacles is at its maximum
                    if ((bites == 5) && ~is_collision && obs_num == 20) begin

                        // move on to level 3
                        state <= state_lvl3;

                        // reset number of bites and size of snake
                        bites <= 3'b0;
                        rst_size <= 1;

                    // number of obstacles not at max yet
                    end else if (
                        (bites < 5) && ~is_collision && obs_num < 20) begin
                        state <= state_lvl2;

                    end else begin

                        // increment again to the last index of the LCD and
                        // append 'E'
                        dis_pos <= dis_pos + 1;
                        dis_char <= CHAR_E;

                        // back to state 0
                        state <= state_lvl0;

                        die <= 1;

                    end

                end

                state_lvl3: begin  // level 3 with 30 obstacles

                    dis_pos <= dis_pos + 1;  // increment position to 2 and 3
                    dis_char <= CHAR_1;

                    level <= 3;

                    obs_num <= obs_num + 1;
                    obj_x <= obs_num * 10 + 10;
                    obj_y <= obs_num * 5 + 10;

                    // no collisions with fence, 5 bites and number of
                    // obstacles is at its maximum
                    if ((bites == 5) && ~is_collision && obs_num == 30) begin

                        // stay on level 3
                        state <= state_lvl3;

                        // reset number of bites and size of snake
                        bites <= 3'b0;
                        rst_size <= 1;

                    // number of obstacles not at max yet
                    end else if (
                        (bites < 5) && ~is_collision && obs_num < 30) begin
                        state <= state_lvl3;

                    end else begin

                        // increment again to the last index of the LCD and
                        // append 'E'
                        dis_pos <= dis_pos + 1;
                        dis_char <= CHAR_E;

                        // back to state 0
                        state <= state_lvl0;

                        die <= 1;

                    end

                end

            endcase

        end

    end

    // ---------------------- sequential bite counter ----------------------
    always @ (posedge clk) begin

        // if collision between head and food coordinates
        if ((head_x == food_x) && (head_y == food_y)) begin

            bites <= bites + 1;
            grow <= 1;

        end

    end

endmodule
