module jk_flipflop(
    input J, K, CLK,
    output Q, Q_NOT);

    // If J and K are both low, Q holds.
    // If J and K are not equal, Q takes on the value at J.
    // If J and K are both high, then Q toggles.
    reg Q, Q_NOT;

    always@(posedge CLK) begin

        case({J,K})

            2'b00: Q = Q;
            2'b01: Q = 1'b0;
            2'b10: Q = 1'b1;
            2'b11: Q = !Q;

        endcase

        Q_NOT = !Q;

    end

endmodule
