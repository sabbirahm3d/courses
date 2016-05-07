// `define TICK #2 //Flip-flop time delay 2 units 

module jk_flipflop(
    input J, K, CLK,
    output Q, Q_NOT);

reg Q, Q_NOT;

// As long as clear and set are not low, then Q will wait for the
// negedge of the clock and change according to the values
// at J and K.
// If J and K are both low, Q holds.
// If J and K are not equal, Q takes on the value at J.
// If J and K are both high, then Q toggles.

    always@(posedge CLK) begin
        // if(~clear) begin
        // Q <= 1'b0;
        // _q <= 1'b1;
        // end
        // else if(~set) begin
        // Q <= 1'b0;
        // _q <= 1'b0;
        // end
        // else begin
        case({J,K})

            2'b00: Q = Q;
            2'b01: Q = 1'b0;
            2'b10: Q = 1'b1;
            2'b11: Q = ~Q;

        endcase

        Q_NOT = ~Q;

    end

endmodule
