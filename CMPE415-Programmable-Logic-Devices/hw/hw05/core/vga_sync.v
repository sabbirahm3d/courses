`timescale 1ns / 1ps
`default_nettype none
//
// File:   vga_sync.v
// Date:   04-Nov-05
// Author: C. Terman / I. Chuang
//
// MIT 6.111 Fall 2005
//
// Verilog code to produce VGA sync signals (and blanking) for 640x480 screen
//
// 28-Nov-05 ike: adjusted vsync to be closer to vesa standard

module vga_sync(
        clk,
        hsync, vsync,
        hcount, vcount,
        pix_clk,
        blank
    );

    input wire clk;  // 50Mhz
    output reg hsync, vsync;
    output reg [9:0] hcount, vcount;
    output wire pix_clk;
    output blank;

    // pixel clock: 25Mhz = 40ns (clk/2)
    reg pcount;      // used to generate pixel clock
    wire en = (pcount == 0);
    always @(posedge clk) pcount <= ~pcount;
    assign pix_clk = en;

    //****************************************************************
    //****************************************************************
    //***
    //***  Sync and Blanking Signals
    //***
    //****************************************************************
    //****************************************************************

    reg hblank, vblank;

    // horizontal: 794 pixels = 31.76us
    // display 640 pixels per line
    wire hsyncon, hsyncoff, hreset, hblankon;
    assign hblankon = en & (hcount == 639);    
    assign hsyncon = en & (hcount == 652 - 4);
    assign hsyncoff = en & (hcount == 746 - 4);
    assign hreset = en & (hcount == 793 - 4);

    wire blank = (vblank | (hblank & ~hreset));    // blanking => black

    // vertical: 528 lines = 16.77us
    // display 480 lines
    wire vsyncon, vsyncoff, vreset, vblankon;
    assign vblankon = hreset & (vcount == 479);    
    assign vsyncon = hreset & (vcount == 492 - 4);
    assign vsyncoff = hreset & (vcount == 494 - 4);
    assign vreset = hreset & (vcount == 527 - 4);

    // sync and blanking
    always @(posedge clk) begin
        hcount <= en ? (hreset ? 0 : hcount + 1) : hcount;
        hblank <= hreset ? 0 : hblankon ? 1 : hblank;
        hsync <= hsyncon ? 0 : hsyncoff ? 1 : hsync;  // hsync is active low

        vcount <= hreset ? (vreset ? 0 : vcount + 1) : vcount;
        vblank <= vreset ? 0 : vblankon ? 1 : vblank;
        vsync <= vsyncon ? 0 : vsyncoff ? 1 : vsync;  // vsync is active low
    end

endmodule
