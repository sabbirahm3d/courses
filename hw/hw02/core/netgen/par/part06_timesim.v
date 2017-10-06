////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: part06_timesim.v
// /___/   /\     Timestamp: Fri Oct  6 15:32:19 2017
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -s 4 -pcf part06.pcf -sdf_anno true -sdf_path netgen/par -insert_glbl true -insert_pp_buffers true -w -dir netgen/par -ofmt verilog -sim part06.ncd part06_timesim.v 
// Device	: 3s500efg320-4 (PRODUCTION 1.27 2013-10-13)
// Input file	: part06.ncd
// Output file	: /home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/netgen/par/part06_timesim.v
// # of Modules	: 1
// Design Name	: part06
// Xilinx        : /opt/Xilinx/14.7/ISE_DS/ISE/
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module part06 (
  clk, a, b, y, z
);
  input clk;
  input a;
  input b;
  output [1 : 0] y;
  output [1 : 0] z;
  wire a_IBUF_38;
  wire clk_BUFGP;
  wire b_IBUF_41;
  wire \clk/INBUF ;
  wire \y<0>/O ;
  wire \y<1>/O ;
  wire \y<1>/OUTPUT/OFF/ODDRIN1_MUX ;
  wire \y<1>/OUTPUT/OFF/OSR_USED_74 ;
  wire y_1_76;
  wire \y<1>/OUTPUT/OFF/O1INV_78 ;
  wire \y<1>/OUTPUT/OTCLK1INV_67 ;
  wire \z<0>/O ;
  wire \z<0>/OUTPUT/OFF/ODDRIN1_MUX ;
  wire \z<0>/OUTPUT/OFF/PCICE_MUX_99 ;
  wire \z<0>/OUTPUT/OFF/OSR_USED_102 ;
  wire z_0_104;
  wire \z<0>/OUTPUT/OFF/O1INV_106 ;
  wire \z<0>/OUTPUT/OTCLK1INV_93 ;
  wire \z<1>/O ;
  wire \z<1>/OUTPUT/OFF/ODDRIN1_MUX ;
  wire \z<1>/OUTPUT/OFF/PCICE_MUX_128 ;
  wire \z<1>/OUTPUT/OFF/OSR_USED_131 ;
  wire z_1_133;
  wire \z<1>/OUTPUT/OFF/O1INV_135 ;
  wire \z<1>/OUTPUT/OTCLK1INV_122 ;
  wire \a/INBUF ;
  wire \b/INBUF ;
  wire \clk_BUFGP/BUFG/S_INVNOT ;
  wire \clk_BUFGP/BUFG/I0_INV ;
  wire \y<0>/OUTPUT/OFF/O1INV_55 ;
  wire GND;
  wire VCC;
  initial $sdf_annotate("netgen/par/part06_timesim.sdf");
  X_IPAD #(
    .LOC ( "IPAD28" ))
  \clk/PAD  (
    .PAD(clk)
  );
  X_BUF #(
    .LOC ( "IPAD28" ))
  \clk_BUFGP/IBUFG  (
    .I(clk),
    .O(\clk/INBUF )
  );
  X_OPAD #(
    .LOC ( "PAD57" ))
  \y<0>/PAD  (
    .PAD(y[0])
  );
  X_OBUF #(
    .LOC ( "PAD57" ))
  y_0_OBUF (
    .I(\y<0>/O ),
    .O(y[0])
  );
  X_OPAD #(
    .LOC ( "PAD56" ))
  \y<1>/PAD  (
    .PAD(y[1])
  );
  X_OBUF #(
    .LOC ( "PAD56" ))
  y_1_OBUF (
    .I(\y<1>/O ),
    .O(y[1])
  );
  X_BUF #(
    .LOC ( "PAD56" ))
  \y<1>/OUTPUT/OFF/O1INV  (
    .I(1'b1),
    .O(\y<1>/OUTPUT/OFF/O1INV_78 )
  );
  X_BUF #(
    .LOC ( "PAD56" ))
  \y<1>/OUTPUT/OFF/O1_DDRMUX  (
    .I(\y<1>/OUTPUT/OFF/O1INV_78 ),
    .O(\y<1>/OUTPUT/OFF/ODDRIN1_MUX )
  );
  X_INV #(
    .LOC ( "PAD56" ))
  \y<1>/OUTPUT/OFF/OSR_USED  (
    .I(a_IBUF_38),
    .O(\y<1>/OUTPUT/OFF/OSR_USED_74 )
  );
  X_BUF #(
    .LOC ( "PAD56" ))
  \y<1>/OUTPUT/OFF/OMUX  (
    .I(y_1_76),
    .O(\y<1>/O )
  );
  X_BUF #(
    .LOC ( "PAD56" ))
  \y<1>/OUTPUT/OTCLK1INV  (
    .I(clk_BUFGP),
    .O(\y<1>/OUTPUT/OTCLK1INV_67 )
  );
  X_OPAD #(
    .LOC ( "PAD53" ))
  \z<0>/PAD  (
    .PAD(z[0])
  );
  X_OBUF #(
    .LOC ( "PAD53" ))
  z_0_OBUF (
    .I(\z<0>/O ),
    .O(z[0])
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OFF/O1INV  (
    .I(1'b0),
    .O(\z<0>/OUTPUT/OFF/O1INV_106 )
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OFF/O1_DDRMUX  (
    .I(\z<0>/OUTPUT/OFF/O1INV_106 ),
    .O(\z<0>/OUTPUT/OFF/ODDRIN1_MUX )
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OFF/PCICE_MUX  (
    .I(b_IBUF_41),
    .O(\z<0>/OUTPUT/OFF/PCICE_MUX_99 )
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OFF/OSR_USED  (
    .I(a_IBUF_38),
    .O(\z<0>/OUTPUT/OFF/OSR_USED_102 )
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OFF/OMUX  (
    .I(z_0_104),
    .O(\z<0>/O )
  );
  X_BUF #(
    .LOC ( "PAD53" ))
  \z<0>/OUTPUT/OTCLK1INV  (
    .I(clk_BUFGP),
    .O(\z<0>/OUTPUT/OTCLK1INV_93 )
  );
  X_OPAD #(
    .LOC ( "PAD52" ))
  \z<1>/PAD  (
    .PAD(z[1])
  );
  X_OBUF #(
    .LOC ( "PAD52" ))
  z_1_OBUF (
    .I(\z<1>/O ),
    .O(z[1])
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OFF/O1INV  (
    .I(1'b1),
    .O(\z<1>/OUTPUT/OFF/O1INV_135 )
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OFF/O1_DDRMUX  (
    .I(\z<1>/OUTPUT/OFF/O1INV_135 ),
    .O(\z<1>/OUTPUT/OFF/ODDRIN1_MUX )
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OFF/PCICE_MUX  (
    .I(b_IBUF_41),
    .O(\z<1>/OUTPUT/OFF/PCICE_MUX_128 )
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OFF/OSR_USED  (
    .I(a_IBUF_38),
    .O(\z<1>/OUTPUT/OFF/OSR_USED_131 )
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OFF/OMUX  (
    .I(z_1_133),
    .O(\z<1>/O )
  );
  X_BUF #(
    .LOC ( "PAD52" ))
  \z<1>/OUTPUT/OTCLK1INV  (
    .I(clk_BUFGP),
    .O(\z<1>/OUTPUT/OTCLK1INV_122 )
  );
  X_IPAD #(
    .LOC ( "IPAD58" ))
  \a/PAD  (
    .PAD(a)
  );
  X_BUF #(
    .LOC ( "IPAD58" ))
  a_IBUF (
    .I(a),
    .O(\a/INBUF )
  );
  X_BUF #(
    .LOC ( "IPAD58" ))
  \a/IFF/IMUX  (
    .I(\a/INBUF ),
    .O(a_IBUF_38)
  );
  X_IPAD #(
    .LOC ( "IPAD55" ))
  \b/PAD  (
    .PAD(b)
  );
  X_BUF #(
    .LOC ( "IPAD55" ))
  b_IBUF (
    .I(b),
    .O(\b/INBUF )
  );
  X_BUF #(
    .LOC ( "IPAD55" ))
  \b/IFF/IMUX  (
    .I(\b/INBUF ),
    .O(b_IBUF_41)
  );
  X_BUFGMUX #(
    .LOC ( "BUFGMUX_X2Y10" ))
  \clk_BUFGP/BUFG  (
    .I0(\clk_BUFGP/BUFG/I0_INV ),
    .I1(GND),
    .S(\clk_BUFGP/BUFG/S_INVNOT ),
    .O(clk_BUFGP)
  );
  X_INV #(
    .LOC ( "BUFGMUX_X2Y10" ))
  \clk_BUFGP/BUFG/SINV  (
    .I(1'b1),
    .O(\clk_BUFGP/BUFG/S_INVNOT )
  );
  X_BUF #(
    .LOC ( "BUFGMUX_X2Y10" ))
  \clk_BUFGP/BUFG/I0_USED  (
    .I(\clk/INBUF ),
    .O(\clk_BUFGP/BUFG/I0_INV )
  );
  X_SFF #(
    .LOC ( "PAD56" ),
    .INIT ( 1'b0 ))
  y_1 (
    .I(\y<1>/OUTPUT/OFF/ODDRIN1_MUX ),
    .CE(VCC),
    .CLK(\y<1>/OUTPUT/OTCLK1INV_67 ),
    .SET(GND),
    .RST(GND),
    .SSET(GND),
    .SRST(\y<1>/OUTPUT/OFF/OSR_USED_74 ),
    .O(y_1_76)
  );
  X_SFF #(
    .LOC ( "PAD53" ),
    .INIT ( 1'b1 ))
  z_0 (
    .I(\z<0>/OUTPUT/OFF/ODDRIN1_MUX ),
    .CE(\z<0>/OUTPUT/OFF/PCICE_MUX_99 ),
    .CLK(\z<0>/OUTPUT/OTCLK1INV_93 ),
    .SET(GND),
    .RST(GND),
    .SSET(\z<0>/OUTPUT/OFF/OSR_USED_102 ),
    .SRST(GND),
    .O(z_0_104)
  );
  X_SFF #(
    .LOC ( "PAD52" ),
    .INIT ( 1'b0 ))
  z_1 (
    .I(\z<1>/OUTPUT/OFF/ODDRIN1_MUX ),
    .CE(\z<1>/OUTPUT/OFF/PCICE_MUX_128 ),
    .CLK(\z<1>/OUTPUT/OTCLK1INV_122 ),
    .SET(GND),
    .RST(GND),
    .SSET(GND),
    .SRST(\z<1>/OUTPUT/OFF/OSR_USED_131 ),
    .O(z_1_133)
  );
  X_BUF #(
    .LOC ( "PAD57" ))
  \y<0>/OUTPUT/OFF/OMUX  (
    .I(\y<0>/OUTPUT/OFF/O1INV_55 ),
    .O(\y<0>/O )
  );
  X_BUF #(
    .LOC ( "PAD57" ))
  \y<0>/OUTPUT/OFF/O1INV  (
    .I(1'b0),
    .O(\y<0>/OUTPUT/OFF/O1INV_55 )
  );
  X_ZERO   NlwBlock_part06_GND (
    .O(GND)
  );
  X_ONE   NlwBlock_part06_VCC (
    .O(VCC)
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

