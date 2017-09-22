<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="CLK_50MHZ" />
        <signal name="XLXN_2(9:0)" />
        <signal name="XLXN_3(9:0)" />
        <signal name="XLXN_4" />
        <signal name="VGA_HSYNC" />
        <signal name="VGA_VSYNC" />
        <signal name="VGA_RED" />
        <signal name="VGA_GREEN" />
        <signal name="VGA_BLUE" />
        <signal name="SW2" />
        <signal name="SW1" />
        <signal name="SW0" />
        <port polarity="Input" name="CLK_50MHZ" />
        <port polarity="Output" name="VGA_HSYNC" />
        <port polarity="Output" name="VGA_VSYNC" />
        <port polarity="Output" name="VGA_RED" />
        <port polarity="Output" name="VGA_GREEN" />
        <port polarity="Output" name="VGA_BLUE" />
        <port polarity="Input" name="SW2" />
        <port polarity="Input" name="SW1" />
        <port polarity="Input" name="SW0" />
        <blockdef name="vga_sync">
            <timestamp>2017-9-22T0:42:53</timestamp>
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
            <timestamp>2017-9-22T1:6:18</timestamp>
            <rect width="256" x="64" y="-448" height="448" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-416" y2="-416" x1="320" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="vga_sync" name="XLXI_1">
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="VGA_HSYNC" name="hsync" />
            <blockpin signalname="VGA_VSYNC" name="vsync" />
            <blockpin name="pix_clk" />
            <blockpin signalname="XLXN_4" name="blank" />
            <blockpin signalname="XLXN_3(9:0)" name="hcount(9:0)" />
            <blockpin signalname="XLXN_2(9:0)" name="vcount(9:0)" />
        </block>
        <block symbolname="vga_rectangle" name="XLXI_2">
            <blockpin signalname="XLXN_4" name="blank" />
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="SW0" name="SW0" />
            <blockpin signalname="SW1" name="SW1" />
            <blockpin signalname="SW2" name="SW2" />
            <blockpin signalname="XLXN_3(9:0)" name="pos_h(9:0)" />
            <blockpin signalname="XLXN_2(9:0)" name="pos_v(9:0)" />
            <blockpin signalname="VGA_RED" name="red" />
            <blockpin signalname="VGA_GREEN" name="green" />
            <blockpin signalname="VGA_BLUE" name="blue" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="928" y="992" name="XLXI_1" orien="R0">
        </instance>
        <branch name="CLK_50MHZ">
            <wire x2="848" y1="640" y2="640" x1="768" />
            <wire x2="928" y1="640" y2="640" x1="848" />
            <wire x2="848" y1="640" y2="1072" x1="848" />
            <wire x2="1488" y1="1072" y2="1072" x1="848" />
            <wire x2="1856" y1="640" y2="640" x1="1488" />
            <wire x2="1488" y1="640" y2="1072" x1="1488" />
        </branch>
        <branch name="XLXN_2(9:0)">
            <wire x2="1856" y1="960" y2="960" x1="1312" />
        </branch>
        <branch name="XLXN_3(9:0)">
            <wire x2="1856" y1="896" y2="896" x1="1312" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1568" y1="832" y2="832" x1="1312" />
            <wire x2="1568" y1="576" y2="832" x1="1568" />
            <wire x2="1856" y1="576" y2="576" x1="1568" />
        </branch>
        <branch name="VGA_HSYNC">
            <wire x2="1328" y1="640" y2="640" x1="1312" />
            <wire x2="1328" y1="400" y2="640" x1="1328" />
        </branch>
        <branch name="VGA_VSYNC">
            <wire x2="1408" y1="704" y2="704" x1="1312" />
            <wire x2="1408" y1="400" y2="704" x1="1408" />
        </branch>
        <branch name="VGA_RED">
            <wire x2="2256" y1="576" y2="576" x1="2240" />
            <wire x2="2288" y1="576" y2="576" x1="2256" />
        </branch>
        <branch name="VGA_GREEN">
            <wire x2="2256" y1="768" y2="768" x1="2240" />
            <wire x2="2288" y1="768" y2="768" x1="2256" />
        </branch>
        <branch name="VGA_BLUE">
            <wire x2="2256" y1="960" y2="960" x1="2240" />
            <wire x2="2288" y1="960" y2="960" x1="2256" />
        </branch>
        <branch name="SW2">
            <wire x2="1648" y1="400" y2="832" x1="1648" />
            <wire x2="1856" y1="832" y2="832" x1="1648" />
            <wire x2="1888" y1="400" y2="400" x1="1648" />
        </branch>
        <branch name="SW1">
            <wire x2="1728" y1="320" y2="768" x1="1728" />
            <wire x2="1856" y1="768" y2="768" x1="1728" />
            <wire x2="1888" y1="320" y2="320" x1="1728" />
        </branch>
        <branch name="SW0">
            <wire x2="1808" y1="240" y2="704" x1="1808" />
            <wire x2="1856" y1="704" y2="704" x1="1808" />
            <wire x2="1888" y1="240" y2="240" x1="1808" />
        </branch>
        <instance x="1856" y="992" name="XLXI_2" orien="R0">
        </instance>
        <iomarker fontsize="28" x="768" y="640" name="CLK_50MHZ" orien="R180" />
        <iomarker fontsize="28" x="1328" y="400" name="VGA_HSYNC" orien="R270" />
        <iomarker fontsize="28" x="1408" y="400" name="VGA_VSYNC" orien="R270" />
        <iomarker fontsize="28" x="1888" y="240" name="SW0" orien="R0" />
        <iomarker fontsize="28" x="1888" y="320" name="SW1" orien="R0" />
        <iomarker fontsize="28" x="1888" y="400" name="SW2" orien="R0" />
        <iomarker fontsize="28" x="2288" y="576" name="VGA_RED" orien="R0" />
        <iomarker fontsize="28" x="2288" y="768" name="VGA_GREEN" orien="R0" />
        <iomarker fontsize="28" x="2288" y="960" name="VGA_BLUE" orien="R0" />
    </sheet>
</drawing>