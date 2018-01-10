`timescale 1ns / 1ps
`default_nettype none
//////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:52:02 11/12/2017 
// Design Name: 
// Module Name:    lcd_driver 
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

module LCDDriver(
        input wire start_write,  // pulse 1 clk period to begin LCD write
        input wire [6:0] dis_pos,  // used during write strobe
        input wire [7:0] dis_char,  // used during write strobe
        input wire rst,  // must set rst for one clk cycle to init module
        input wire clk,
        output wire [3:0] sf_d_11_8,
        output wire lcd_e,
        output wire lcd_rs,
        output wire lcd_rw,
        output reg ready  // high when module is ready for write signal
    );

    wire nibble_ready;
    reg start_write_nibbles,single_nibble_mode;
    reg [7:0] sf_d;
    reg rs,rw;

    reg [31:0] counter;

    reg [7:0] dis_char_saved;
    reg [6:0] dis_pos_saved;

    reg [4:0] CS;

    parameter S_reset = 5'hff;
    parameter S_init = 5'h00;
    parameter S_1 = 5'h01;
    parameter S_2 = 5'h02;
    parameter S_3 = 5'h03;
    parameter S_4 = 5'h04;
    parameter S_5 = 5'h05;
    parameter S_6 = 5'h06;
    parameter S_7 = 5'h07;
    parameter S_8 = 5'h08;
    parameter S_9 = 5'h09;
    parameter S_10 = 5'h0a;
    parameter S_11 = 5'h0b;
    parameter S_12 = 5'h0c;
    parameter S_13 = 5'h0d;
    parameter S_14 = 5'h0e;
    parameter S_15 = 5'h0f;
    parameter S_16 = 5'h10;

    LCDNibbleDriver I1(
        .sf_d_11_8_out(sf_d_11_8),  // for LCD
        .lcd_e_out(lcd_e),  // for LCD
        .lcd_rs_out(lcd_rs),  // for LCD
        .lcd_rw_out(lcd_rw),  // for LCD
        .ready(nibble_ready),  // high when module is ready for write signal
        // pulse 1 clk period after ready is high to begin LCD write
        .start_write(start_write_nibbles),
        .single_nibble_mode(single_nibble_mode),  
        .sf_d_in(sf_d),  // used during write strobe
        .lcd_rs_in(rs),  // for LCD
        .lcd_rw_in(rw),  // for LCD
        .rst(rst),  // must set rst for one clk cycle to init module    
        .clk(clk)
     );                  
                       
    reg start_write_prev;

    always  @(posedge clk) begin
        start_write_prev<=start_write;
    end

    always @(posedge clk) begin
        if (rst)
            CS<=S_reset;
        else
            case (CS)
                S_reset: begin
                    counter <=0;
                    CS <= S_init;
                end
                // Wait 15 ms or longer, although the display is generally ready
                // when the FPGA finishes configuration. The 15 ms interval is
                // 750,000 clock cycles at 50 MHz
                S_init:  begin
                    sf_d <= 0;
                    ready <=0;
                    if (counter == 750000) begin
                        CS <= S_1;
                        counter <= 0;
                    end else begin
                        counter <= counter +1;
                    end
                end

                // These two states Write SF_D<11:8> = 0x3, pulse LCD_E High for
                // 12 clock cycles
                S_1: begin
                    sf_d <= 8'h03;
                    single_nibble_mode <= 1;
                    rs <= 0;
                    rw <= 0;

                    // set writing of nibbles for one cycle
                    start_write_nibbles <= (counter == 0) ? 1 : 0;
                    // wait long enough for nibble_ready to fall
                    if (counter < 3)
                        counter <= counter + 1;
                    else begin
                        if (nibble_ready) begin
                            CS <= S_2;
                            counter <= 0;
                        end
                    end 
                end // case: S_10

                S_2: begin // Wait 4.1 ms or longer, which is 205,000 clock cycles at 50 MHz.
                    if (counter < 205000)
                        counter <= counter +1;
                    else begin
                        CS <= S_3;
                        counter <= 0;
                    end 
                 end 

                S_3: begin // //These two states Write SF_D<11:8> = 0x3, pulse LCD_E High for 12 clock cycles. 
                    sf_d <= 8'h03;
                    single_nibble_mode <= 1;
                    rs <= 0;
                    rw <= 0;
                    // set writing of nibbles for one cycle
                    start_write_nibbles <= (counter == 0) ? 1 : 0;     
                    if (counter < 3)
                        // wait long enough for nibble_ready to fall
                        counter <= counter +1;
                    else begin
                        if (nibble_ready) begin
                            CS <= S_4;
                            counter <= 0;
                        end
                    end 
                end // case: S_10     

                // Wait 100 µs or longer, which is 5,000 clock cycles at 50 MHz
                S_4: begin
                    if (counter < 5000)
                        counter <= counter +1;
                    else begin
                        CS <= S_5;
                        counter <= 0;
                    end 
                end 

                // These two states Write SF_D<11:8> = 0x3, pulse LCD_E High for
                // 12 clock cycles
                S_5: begin 
                    sf_d <= 8'h03;
                    single_nibble_mode <= 1;
                    rs <= 0;
                    rw <= 0;

                    // set writing of nibbles for one cycle
                    start_write_nibbles <= (counter == 0) ? 1 : 0;     
                    if (counter < 3)
                        // wait long enough for nibble_ready to fall
                        counter <= counter +1;
                    else begin
                        if (nibble_ready) begin
                            CS <= S_6;
                            counter <= 0;
                        end
                    end 
                end // case: S_10     

                // Wait 40 µs or longer, which is 2,000 clock cycles at 50 MHz
                S_6: begin
                    if (counter < 2000)
                        counter <= counter +1;
                    else begin
                        CS <= S_7;
                        counter <= 0;
                    end 
                end 

         S_7: begin // //These two states Write SF_D<11:8> = 0x2, pulse LCD_E High for 12 clock cycles. 
            sf_d <= 8'h02;
            single_nibble_mode <= 1;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_8;
                  counter <= 0;
                 end
              end 
         end // case: S_10     
         S_8: begin // // Wait 40 µs or longer, which is 2,000 clock cycles at 50 MHz.
            if (counter < 2000) counter <= counter +1;
            else begin
               CS <= S_9;
                 counter <= 0;
            end 
         end 
         
       
         /////////////
         //  Issue a Function Set command, 0x28, to configure the display for operation on the Spartan-3E Starter Kit board.
         S_9: begin
            sf_d <= 8'h28;
            single_nibble_mode <= 0;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_10;
                  counter <= 0;
                 end
              end 
         end // case: S_10   
         
         
        


         // Issue an Entry Mode Set  command, 0x06, to set the display to automatically increment the address pointer. 
         S_10: begin 
         sf_d <= 8'h06;
            single_nibble_mode <= 0;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_11;
                  counter <= 0;
                 end
              end 
         end // case: S_10  
         
         
         // Issue a Display On/Off command, 0x0C, to turn the display on and disables the cursor and blinking.
         S_11: begin 
            sf_d <= 8'h0C;
            single_nibble_mode <= 0;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_12;
                  counter <= 0;
                 end
              end 
         end // case: S_10  
         
         
          // Finally, issue a Clear Display command 0x01. Allow at least 1.64 ms (82,000 clock cycles) after issuing this command.
          S_12: begin        sf_d <= 8'h01;
            single_nibble_mode <= 0;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_13;
                  counter <= 0;
                 end
              end 
         end // case: S_10  
        
         
         S_13: begin // // waiting at least 1.64 ms (82,000 clock cycles) after previous command 
            if (counter < 82000) counter <= counter +1; //wait long enough for nibble_ready to fall and for 1.64+ ms
            else begin
               CS <= S_14;
                 counter <= 0;
            end 
         end 
         

          S_14: begin
             if(start_write && ~start_write_prev)begin
                CS <= S_15;
                dis_char_saved <= dis_char;
                dis_pos_saved <= dis_pos;
                ready<=0;
             end else ready<=1;
          end

          S_15: begin
            sf_d <= {1'b1,dis_pos_saved}; //append 1 as MSB according to UG
            single_nibble_mode <= 0;
            rs <= 0;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1; //wait long enough for nibble_ready to fall
            else begin
               if (nibble_ready) begin
                  CS <= S_16;
                  counter <= 0;
                 end
              end 
         end // case: S_14  
         
         S_16: begin        
            sf_d <= dis_char_saved;
            single_nibble_mode <= 0;
            rs <= 1;
            rw <= 0;

              start_write_nibbles <= (counter == 0)?1:0;  //set writing of nibbles for one cycle     
            if (counter < 3) counter <= counter +1;  // wait before checking nibble_ready
            else begin
               if (nibble_ready) begin
                  CS <= S_14;
                  counter <= 0;
                 end
              end 
         end // case: S_14 

        endcase
    end //end always

endmodule
       



module LCDNibbleDriver(
        output reg [3:0] sf_d_11_8_out, //for LCD
        output reg lcd_e_out,           //for LCD
        output reg lcd_rs_out,          //for LCD
        output reg lcd_rw_out,          //for LCD
        output reg ready,           //high when module is ready for write signal
        input wire start_write,      //pulse 1 clk period after ready is high to begin LCD write
        input wire single_nibble_mode,  
        input wire [7:0] sf_d_in,    //used during write strobe, fig 5-3 pg 43 in UG
        input wire lcd_rs_in,          //for LCD, see table 5-1 page 42 in user guide
        input  wire lcd_rw_in,          //for LCD, see table 5-1 page 42 in user guide
        input wire rst,              //must set rst for one clk cycle to init. module    
        input wire clk
    );
                       
                       
                       
    reg [31:0] counter;
    reg [15:0] CS;

    parameter S_init = 16'b0000000000000001;
    parameter S_1    = 16'b0000000000000010;
    parameter S_2    = 16'b0000000000000100;
    parameter S_3    = 16'b0000000000001000;
    parameter S_4    = 16'b0000000000010000;
    parameter S_5    = 16'b0000000000100000;
    parameter S_6    = 16'b0000000001000000;
    parameter S_7    = 16'b0000000010000000;
    parameter S_8    = 16'b0000000100000000;
    parameter S_9    = 16'b0000001000000000;
    parameter S_10   = 16'b0000010000000000;
    parameter S_11   = 16'b0000100000000000;
    parameter S_12   = 16'b0001000000000000;
    parameter S_13   = 16'b0010000000000000;
    parameter S_14   = 16'b0100000000000000;
    parameter S_15   = 16'b1000000000000000;

    reg lcd_rw_saved,lcd_rs_saved;
                       
    always @(posedge clk) begin

       if (rst) CS<=S_init;
       else
          case(CS) 
             S_init: begin
                sf_d_11_8_out <= 0;
                lcd_e_out <= 0;
                lcd_rs_out <= 0;
                lcd_rw_out <= 0;
                counter<=0;
                if (start_write) begin
                   ready<=0;
                   if (single_nibble_mode) begin
                     CS <= S_4;
                   end else begin
                      CS <= S_1;
                   end
                end else ready<=1;
                lcd_rs_saved<=lcd_rs_in;
                lcd_rw_saved<=lcd_rw_in;  
             end

             S_1: begin 
                sf_d_11_8_out <= sf_d_in[7:4];
                lcd_e_out  <= 0;
                lcd_rs_out <= lcd_rs_saved;
                lcd_rw_out <= lcd_rw_saved;
    //            if (counter < 2) counter <= counter +1;//just some delay that I hope helps
    //            else begin
                   CS <= S_2;
                   counter <= 0;
    //            end
             end

             S_2: begin //  12+ cylces 230 ns
                lcd_e_out <= 1;
                if (counter < 24) counter <= counter +1;
                else begin
                   CS <= S_3;
                     counter <= 0;
                end
             end


             S_3: begin //  50 cylces 1 us
                lcd_e_out <= 0;
                if (counter < 100) counter <= counter +1;
                else begin
                   CS <= S_4;
                     counter <= 0;
                end
             end



             S_4: begin //  set next nibble
                sf_d_11_8_out <= sf_d_in[3:0];
                lcd_e_out  <= 0;
                lcd_rs_out <= lcd_rs_saved;
                lcd_rw_out <= lcd_rw_saved;
    //            if (counter < 2) counter <= counter +1;//just some delay that I hope helps
    //            else begin
                   CS <= S_5;
                   counter <= 0;
    //            end
             end

             S_5: begin //  12 cylces 230 ns
                lcd_e_out <= 1;
                if (counter < 24) counter <= counter +1;
                else begin
                   CS <= S_6;
                     counter <= 0;
                end
             end

             S_6: begin //  40 us 2000 cylces
                lcd_e_out <= 0;
                if (counter < 4000)
                    counter <= counter +1;
                else  begin
                    CS <= S_init;
                    counter <= 0;
                end
             end
          endcase
    end //end always
       
endmodule
