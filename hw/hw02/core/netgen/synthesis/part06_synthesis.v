////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: part06_synthesis.v
// /___/   /\     Timestamp: Thu Oct  5 14:19:34 2017
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim part06.ngc part06_synthesis.v 
// Device	: xc3s500e-4-fg320
// Input file	: part06.ngc
// Output file	: /home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/netgen/synthesis/part06_synthesis.v
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
  wire N1;
  wire a_IBUF_2;
  wire a_inv;
  wire b_IBUF_5;
  wire clk_BUFGP_7;
  wire y_0_OBUF_10;
  wire y_1_11;
  wire z_0_14;
  wire z_1_15;
  GND   XST_GND (
    .G(y_0_OBUF_10)
  );
  VCC   XST_VCC (
    .P(N1)
  );
  FDSE   z_0 (
    .C(clk_BUFGP_7),
    .CE(b_IBUF_5),
    .D(y_0_OBUF_10),
    .S(a_IBUF_2),
    .Q(z_0_14)
  );
  FDRE   z_1 (
    .C(clk_BUFGP_7),
    .CE(b_IBUF_5),
    .D(N1),
    .R(a_IBUF_2),
    .Q(z_1_15)
  );
  FDR   y_1 (
    .C(clk_BUFGP_7),
    .D(N1),
    .R(a_inv),
    .Q(y_1_11)
  );
  IBUF   a_IBUF (
    .I(a),
    .O(a_IBUF_2)
  );
  IBUF   b_IBUF (
    .I(b),
    .O(b_IBUF_5)
  );
  OBUF   y_1_OBUF (
    .I(y_1_11),
    .O(y[1])
  );
  OBUF   y_0_OBUF (
    .I(y_0_OBUF_10),
    .O(y[0])
  );
  OBUF   z_1_OBUF (
    .I(z_1_15),
    .O(z[1])
  );
  OBUF   z_0_OBUF (
    .I(z_0_14),
    .O(z[0])
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_7)
  );
  INV   a_inv1_INV_0 (
    .I(a_IBUF_2),
    .O(a_inv)
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

