module main;

    reg a, CLK;
    wire y0, y1;
    vending_machine_fsm circuit(.a(a), .CLK(CLK), .y0(y0), .y1(y1));

	initial begin

        a = 1'b0;
        CLK = 1;

        #1000 $finish;

    end

    always
        #50 CLK = !CLK;

	always
	    begin
	        #5 $monitor("CLK=%b, x=%b, y0=%b, y1=%b", CLK, a, y0, y1);
	    end

endmodule