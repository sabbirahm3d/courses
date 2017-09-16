<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="CLK_50MHZ" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3(9:0)" />
        <signal name="XLXN_4(9:0)" />
        <signal name="XLXN_7" />
        <signal name="VGA_HSYNC" />
        <signal name="VGA_VSYNC" />
        <signal name="VGA_RED" />
        <signal name="VGA_GREEN" />
        <signal name="VGA_BLUE" />
        <port polarity="Input" name="CLK_50MHZ" />
        <port polarity="Output" name="VGA_HSYNC" />
        <port polarity="Output" name="VGA_VSYNC" />
        <port polarity="Output" name="VGA_RED" />
        <port polarity="Output" name="VGA_GREEN" />
        <port polarity="Output" name="VGA_BLUE" />
        <blockdef name="vga_sync">
            <timestamp>2017-9-16T22:26:26</timestamp>
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
            <timestamp>2017-9-16T22:36:11</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-128" y2="-128" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="vga_sync" name="XLXI_1">
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="VGA_HSYNC" name="hsync" />
            <blockpin signalname="VGA_VSYNC" name="vsync" />
            <blockpin name="pix_clk" />
            <blockpin signalname="XLXN_7" name="blank" />
            <blockpin signalname="XLXN_4(9:0)" name="hcount(9:0)" />
            <blockpin signalname="XLXN_3(9:0)" name="vcount(9:0)" />
        </block>
        <block symbolname="vga_rectangle" name="XLXI_2">
            <blockpin signalname="XLXN_7" name="blank" />
            <blockpin signalname="CLK_50MHZ" name="clk" />
            <blockpin signalname="XLXN_4(9:0)" name="pos_h(9:0)" />
            <blockpin signalname="XLXN_3(9:0)" name="pos_v(9:0)" />
            <blockpin signalname="VGA_RED" name="red" />
            <blockpin signalname="VGA_GREEN" name="green" />
            <blockpin signalname="VGA_BLUE" name="blue" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="CLK_50MHZ">
            <wire x2="1040" y1="608" y2="608" x1="896" />
            <wire x2="1072" y1="608" y2="608" x1="1040" />
            <wire x2="1088" y1="608" y2="608" x1="1072" />
            <wire x2="1040" y1="480" y2="608" x1="1040" />
            <wire x2="1760" y1="480" y2="480" x1="1040" />
            <wire x2="1760" y1="480" y2="800" x1="1760" />
            <wire x2="1840" y1="800" y2="800" x1="1760" />
        </branch>
        <instance x="1088" y="960" name="XLXI_1" orien="R0">
        </instance>
        <iomarker fontsize="28" x="896" y="608" name="CLK_50MHZ" orien="R180" />
        <instance x="1840" y="960" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_3(9:0)">
            <wire x2="1840" y1="928" y2="928" x1="1472" />
        </branch>
        <branch name="XLXN_4(9:0)">
            <wire x2="1840" y1="864" y2="864" x1="1472" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1680" y1="800" y2="800" x1="1472" />
            <wire x2="1680" y1="736" y2="800" x1="1680" />
            <wire x2="1840" y1="736" y2="736" x1="1680" />
        </branch>
        <branch name="VGA_HSYNC">
            <wire x2="1680" y1="608" y2="608" x1="1472" />
            <wire x2="1680" y1="320" y2="608" x1="1680" />
            <wire x2="1920" y1="320" y2="320" x1="1680" />
        </branch>
        <branch name="VGA_VSYNC">
            <wire x2="1600" y1="672" y2="672" x1="1472" />
            <wire x2="1600" y1="400" y2="672" x1="1600" />
            <wire x2="1920" y1="400" y2="400" x1="1600" />
        </branch>
        <branch name="VGA_RED">
            <wire x2="2320" y1="736" y2="736" x1="2224" />
        </branch>
        <branch name="VGA_GREEN">
            <wire x2="2320" y1="832" y2="832" x1="2224" />
        </branch>
        <branch name="VGA_BLUE">
            <wire x2="2320" y1="928" y2="928" x1="2224" />
        </branch>
        <iomarker fontsize="28" x="1920" y="320" name="VGA_HSYNC" orien="R0" />
        <iomarker fontsize="28" x="1920" y="400" name="VGA_VSYNC" orien="R0" />
        <iomarker fontsize="28" x="2320" y="736" name="VGA_RED" orien="R0" />
        <iomarker fontsize="28" x="2320" y="832" name="VGA_GREEN" orien="R0" />
        <iomarker fontsize="28" x="2320" y="928" name="VGA_BLUE" orien="R0" />
    </sheet>
</drawing>