module JKflipflop(q, _q, J, K, clk, clear, set);
input J, K, clk, clear, set;
output q, _q;
reg q, _q;
//As long as clear and set are not low, then q will wait for the
//negedge of the clock and change according to the values
//at J and K.
//If J and K are both low, q holds.
//If J and K are not equal, q takes on the value at J.
//If J and K are both high, then q toggles.
always@(negedge clk or negedge clear or negedge set)

begin

    if(~clear) begin
    q <= 1'b0;
    _q <= 1'b1;
    end

    else if(~set) begin
        q <= 1'b0;
        _q <= 1'b0;
    end

    else begin
        case({J,K})

            2'b00: begin
                q <= q;
                _q <= _q;
            end

            2'b01: begin
                q <= 1'b0;
                _q <= 1'b1;
            end

            2'b10: begin
                q <= 1'b1;
                _q <= 1'b0;
            end

            2'b11: begin
                q <= ~q;
                _q <= ~_q;
            end
        endcase
    end

end

endmodule
