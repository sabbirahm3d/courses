// vending_machine_fsm.v
// Schematics for the vending machine finite state machine

module vending_machine_fsm (
    input a, CLK, reset,
    output y0, y1);

    wire J0, K0, J1, K1, J2, K2, J3, K3, b, b_, c, c_, d, d_, e, e_;

    jk_flipflop JK0(.J(J0), .K(K0), .CLK(CLK), .reset(reset), .Q(b), .Q_NOT(b_));
    jk_flipflop JK1(.J(J1), .K(K1), .CLK(CLK), .reset(reset), .Q(c), .Q_NOT(c_));
    jk_flipflop JK2(.J(J2), .K(K2), .CLK(CLK), .reset(reset), .Q(d), .Q_NOT(d_));
    jk_flipflop JK3(.J(J3), .K(K3), .CLK(CLK), .reset(reset), .Q(e), .Q_NOT(e_));

    // custom 2-4 decoder
    and(d0, !a, c_); // !a!c
    and(d1, !a, c); // !ac
    and(d3, a, c); // ac

    // 3-8 decoder
    and(m0, !a, d_, e_); // !a!d!e
    and(m2, !a, d, e_); // !ad!e
    and(m3, !a, d, e); // !ade
    and(m6, a, d, e_); // ad!e

    // J0
    or(w1, d_, e); // !d + e
    and(w2, d1, w1); // !ac(!d + e)
    and(w3, d3, d); // ac(d)
    and(w4, c_, m2); // !c(!ad!e)
    or(J0, w2, w3, w4); // !ac(!d + e) + ac(d) + !c(!ad!e)

    // K0
    or(K0, !a, d); // !a + d

    // J1
    and(w5, !a, e); // !ae
    or(J1, d, w5); // d + !ae

    // K1
    and(w6, !a, b); // !ab
    and(w7, b, d); // bd
    or(w8, w6, w7); // !ab + bd
    or(K1, w8, m2); // !ab + bd + !ad!e

    // J2
    and(w9, a, e); // ae
    and(w10, d0, e_); // !a!c!e
    and(w11, b_, c); // !bc
    and(w12, w11, e); // !bce
    or(w13, w9, w10); // ae + !a!c!e
    or(J2, w13, w12, d3); // ae + !a!c!e + ac + !bce

    // K2
    xor(w14, b, e_); // b ^ e
    or(K2, a, w14, w22); // a + b ^ e

    // J3
    or(w15, b_, d_); // !b + !d
    and(w16, w15, a); // a(!b + !d)
    and(w17, d, w11); // !bc(e)
    and(w18, !a, w7); // !a(bd)
    or(J3, w16, w17, w18); // a(!b + !d) + !bc(e) + !a(bd)

    // K3
    and(w19, b_, d); // !bd
    or(K3, w19, d3); // !bd + ac

    // y0
    and(w20, c, m2); // c(!ad!e)
    or(y0, w6, w7, w20); // !ab + bd + c(!ad!e)

    // y1
    or(w21, m0, m3, m6); // !a!d!e + !ad!e + ad!e
    and(y1, b, w21); // b(!a!d!e + !ad!e + ad!e)

endmodule