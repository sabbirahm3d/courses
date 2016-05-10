// tb_fsm.v
// Testbench for the vending machine finite state machine

// define scale for time
`timescale 1ns / 1ns

module tb_fsm;

    // Inputs
    reg in, CLK, reset;

    // Outputs
    wire voucher, change;

    // Variable used for for-loops
    integer i;

    // Instantiate the Unit Under Test (UUT)
    vending_machine_fsm uut (
        .a(in),
        .CLK(CLK),
        .reset(reset),
        .y0(voucher),
        .y1(change)
    );

    initial begin

        $dumpfile("fsm.vcd");
        $dumpvars(0, tb_fsm);

        // Initialize Inputs
        in = 0;
        CLK = 0;
        reset = 0;

        // Wait 20 ns for global reset to finish
        #20;

        reset = 1;
        $monitor(
            "Input: %b\nVoucher = %b, Change = %b \n",
            in, voucher, change
        );


        // Test 1: 3 consecutive quarters
        $display("Test 1: 3 consecutive quarters");

        for (i = 0; i < 4; i = i + 1) begin
            in = 0;
            #20;
        end


        // Test 2: 7 consecutive dimes
        $display("\n\n\nTest 2: 7 consecutive dimes");
        reset = 1;
        for (i = 0; i < 8; i = i + 1) begin
            in = 1;
            #20;
        end

        // Test 2: 7 consecutive dimes
        $display("\n\n\nTest 3: Alternate dimes and quarters");
        reset = 1;
        for (i = 0; i < 8; i = i + 1) begin
            in = 1;
            #20;
            in = 0;
            #20;
        end

        #20;
        $finish;

    end

    always 
        CLK = #10 !CLK;

endmodule
