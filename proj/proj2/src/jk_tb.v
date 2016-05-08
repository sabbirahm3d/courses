module jk_tb;

    reg J, K, CLK;
    wire Q, Q_NOT;
    jk_flipflop jk_ff(.J(J), .K(K), .CLK(CLK), .Q(Q), .Q_NOT(Q_NOT));

    initial begin

        J = 1'b0; K = 1'b0;

        CLK = 1;

        #100;
        J = 1'b0; K = 1'b1; #100;
        J = 1'b1; K = 0'b0; #100;
        J = 1'b1; K = 1'b1; #100;
        J = 1'b0; K = 0'b0; #100;
        J = 1'b0; K = 1'b1; #100;
        J = 1'b1; K = 0'b0; #100;
        J = 1'b1; K = 1'b1; #100;
        J = 1'b0; K = 0'b0; #100;

        #50 $finish;

    end

    always
        #50 CLK = !CLK;

    always
        #50 $monitor( "CLK = %b J = %b K = %b Q = %b, Q_NOT = %b",
            CLK, J, K, Q, Q_NOT);

endmodule