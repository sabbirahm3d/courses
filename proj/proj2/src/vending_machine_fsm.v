module vending_machine_fsm(
    input a, CLK, 
    output y0, y1);

    wire J0, K0, J1, K1, J2, K2, J3, K3;
    output b, b_, c, c_, d, d_, e, e_;

    jk_flipflop JK0(.J(J0), .K(K0), .CLK(CLK), .Q(b), .Q_NOT(b_));
    jk_flipflop JK1(.J(J1), .K(K1), .CLK(CLK), .Q(c), .Q_NOT(c_));
    jk_flipflop JK2(.J(J2), .K(K2), .CLK(CLK), .Q(d), .Q_NOT(d_));
    jk_flipflop JK3(.J(J3), .K(K3), .CLK(CLK), .Q(e), .Q_NOT(e_));

    // custom 2-4 decoder
    and(w1, !a, c_); // !a!c

    and(w2, !a, c); // !ac

    and(w3, a, c); // ac

    // 3-8 decoder
    and(m0, !a, d_, e_); // m0

    and(m2, !a, d, e_); // m2

    and(m3, !a, d, e); // m3

    and(m6, a, d, e_); // m6

    // J0
    and(w8, w2, d_); // !ac!d

    and(w9, w2, e); // !ace

    and(w10, w3, d); // acd

    and(w11, m2, c_); // !c2

    or(w12, w8, w9); // !ac!d + !ace

    or(w13, w10, w11); // acd + !c2

    or(J0, w12, w13); // !ac!d + !ace + acd + !c2

    // K0
    or(K0, !a, d); // !a + d

    // J1
    and(w14, !a, e); // !ae

    or(J1, w14, w14); // d + !ae

    // K1
    and(w15, !a, b); // !ab

    and(w16, b, d); // bd

    or(w29, w15, w16); // !ab + bd

    or(K1, w29, m2); // !ab + bd + 2

    // J2
    and(w17, a, e); // ae

    and(w18, w1, e_); // !a!c!e

    and(w19, b_, c); // !bc

    and(w20, w19, e); // !bce

    or(w21, w17, w3); // ae + ac

    or(w22, w18, w19); // !a!c!e + !bce

    or(J2, w21, w22); // !a!c!e + !bce + ae + ac

    // K2
    xor(w23, b, e_); // b^!e

    or(K2, a, w23); // a+b^!e

    // J3
    or(w24, b_, d_); // !b+!d

    and(w25, a, w24); // a(!b+!d)

    and(w26, d, w19); // !bcd

    and(w27, !a, w16); // !abd

    or(J3, w25, w26, w27); // a(!b+!d) + !bcd + !abd

    // K3
    and(w28, b_, d); // !bd

    or(K3, w3, w28); // ac + !bd

    // y0
    and(w30, c, m2); // c2

    or(y0, w30, w29); // !ab + bd + c2

    // y1
    or(w31, m0, m3, m6); // m0 + m3 + m6

    and(y1, b, w31); // b(m0 + m3 + m6)

endmodule