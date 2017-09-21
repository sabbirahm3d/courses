<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="CLK_50MHZ" />
        <signal name="VGA_HSYNC" />
        <signal name="VGA_VSYNC" />
        <signal name="XLXN_6(9:0)" />
        <signal name="XLXN_7(9:0)" />
        <signal name="VGA_RED" />
        <signal name="VGA_GREEN" />
        <signal name="VGA_BLUE" />
        <signal name="BLANK" />
        <signal name="SW0" />
        <signal name="SW1" />
        <signal name="SW2" />
        <port polarity="Input" name="CLK_50MHZ" />
        <port polarity="Output" name="VGA_HSYNC" />
        <port polarity="Output" name="VGA_VSYNC" />
        <port polarity="Output" name="VGA_RED" />
        <port polarity="Output" name="VGA_GREEN" />
        <port polarity="Output" name="VGA_BLUE" />
        <port polarity="Input" name="SW0" />
        <port polarity="Input" name="SW1" />
        <port polarity="Input" name="SW2" />
        <blockdef name="vga_sync">
            <timestamp>2017-9-21T1:22:42</timestamp>
            <rect width="256" x="64" y="-384" height="384" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="384" y1="-352" y2="-352" x1="320" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="vga_rectangle">
            <timestamp>2017-9-21T21:4:16</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="96" y2="96" x1="64" />
            <line x2="0" y1="160" y2="160" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-128" y2="-128" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
            <rect width="256" x="64" y="-256" height="448" />
        </blockdef>
        <block symbolname="vga_sync" name="XLXI_1">
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="VGA_HSYNC" name="hsync" />
            <blockpin signalname="VGA_VSYNC" name="vsync" />
            <blockpin name="pix_clk" />
            <blockpin signalname="BLANK" name="blank" />
            <blockpin signalname="XLXN_6(9:0)" name="hcount(9:0)" />
            <blockpin signalname="XLXN_7(9:0)" name="vcount(9:0)" />
        </block>
        <block symbolname="vga_rectangle" name="XLXI_4">
            <blockpin signalname="BLANK" name="blank" />
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="SW0" name="SW0" />
            <blockpin signalname="SW1" name="SW1" />
            <blockpin signalname="SW2" name="SW2" />
            <blockpin signalname="XLXN_6(9:0)" name="pos_h(9:0)" />
            <blockpin signalname="XLXN_7(9:0)" name="pos_v(9:0)" />
            <blockpin signalname="VGA_RED" name="red" />
            <blockpin signalname="VGA_GREEN" name="green" />
            <blockpin signalname="VGA_BLUE" name="blue" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="912" y="1120" name="XLXI_1" orien="R0">
        </instance>
        <branch name="CLK_50MHZ">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="720" y="768" type="branch" />
            <wire x2="720" y1="768" y2="768" x1="640" />
            <wire x2="880" y1="768" y2="768" x1="720" />
            <wire x2="912" y1="768" y2="768" x1="880" />
            <wire x2="880" y1="672" y2="768" x1="880" />
            <wire x2="1504" y1="672" y2="672" x1="880" />
            <wire x2="1504" y1="672" y2="960" x1="1504" />
            <wire x2="1568" y1="960" y2="960" x1="1504" />
        </branch>
        <branch name="VGA_HSYNC">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1552" y="592" type="branch" />
            <wire x2="1312" y1="768" y2="768" x1="1296" />
            <wire x2="1552" y1="592" y2="592" x1="1312" />
            <wire x2="1792" y1="592" y2="592" x1="1552" />
            <wire x2="1312" y1="592" y2="624" x1="1312" />
            <wire x2="1312" y1="624" y2="768" x1="1312" />
        </branch>
        <branch name="XLXN_6(9:0)">
            <wire x2="1568" y1="1024" y2="1024" x1="1296" />
        </branch>
        <branch name="XLXN_7(9:0)">
            <wire x2="1568" y1="1088" y2="1088" x1="1296" />
        </branch>
        <branch name="VGA_RED">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2016" y="896" type="branch" />
            <wire x2="2016" y1="896" y2="896" x1="1952" />
            <wire x2="2208" y1="896" y2="896" x1="2016" />
        </branch>
        <branch name="VGA_GREEN">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2000" y="992" type="branch" />
            <wire x2="2000" y1="992" y2="992" x1="1952" />
            <wire x2="2208" y1="992" y2="992" x1="2000" />
        </branch>
        <branch name="VGA_BLUE">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2016" y="1088" type="branch" />
            <wire x2="2016" y1="1088" y2="1088" x1="1952" />
            <wire x2="2208" y1="1088" y2="1088" x1="2016" />
        </branch>
        <branch name="BLANK">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1440" y="896" type="branch" />
            <wire x2="1424" y1="960" y2="960" x1="1296" />
            <wire x2="1424" y1="896" y2="960" x1="1424" />
            <wire x2="1440" y1="896" y2="896" x1="1424" />
            <wire x2="1568" y1="896" y2="896" x1="1440" />
        </branch>
        <iomarker fontsize="28" x="640" y="768" name="CLK_50MHZ" orien="R180" />
        <iomarker fontsize="28" x="1792" y="592" name="VGA_HSYNC" orien="R0" />
        <iomarker fontsize="28" x="1792" y="624" name="VGA_VSYNC" orien="R0" />
        <iomarker fontsize="28" x="2208" y="896" name="VGA_RED" orien="R0" />
        <iomarker fontsize="28" x="2208" y="992" name="VGA_GREEN" orien="R0" />
        <iomarker fontsize="28" x="2208" y="1088" name="VGA_BLUE" orien="R0" />
        <branch name="VGA_VSYNC">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1520" y="624" type="branch" />
            <wire x2="1296" y1="624" y2="832" x1="1296" />
            <wire x2="1520" y1="624" y2="624" x1="1296" />
            <wire x2="1792" y1="624" y2="624" x1="1520" />
        </branch>
        <instance x="1568" y="1120" name="XLXI_4" orien="R0">
        </instance>
        <branch name="SW0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1456" y="1152" type="branch" />
            <wire x2="1456" y1="1152" y2="1152" x1="1296" />
            <wire x2="1568" y1="1152" y2="1152" x1="1456" />
        </branch>
        <branch name="SW1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1440" y="1216" type="branch" />
            <wire x2="1440" y1="1216" y2="1216" x1="1296" />
            <wire x2="1568" y1="1216" y2="1216" x1="1440" />
        </branch>
        <branch name="SW2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="1280" type="branch" />
            <wire x2="1424" y1="1280" y2="1280" x1="1312" />
            <wire x2="1568" y1="1280" y2="1280" x1="1424" />
        </branch>
        <iomarker fontsize="28" x="1296" y="1152" name="SW0" orien="R180" />
        <iomarker fontsize="28" x="1296" y="1216" name="SW1" orien="R180" />
        <iomarker fontsize="28" x="1312" y="1280" name="SW2" orien="R180" />
    </sheet>
</drawing>