module circuit(a, b, c, d, e, f, g, A, B, C, D);

input A, B, C, D;
output a, b, c, d, e, f, g;
wire w1, w2, w3, w4, w5, w6, w7;

	and(w1, A, !B, !C); // A~B~C

	and(w2, !A, C); // ~AC

	nor(w3, A, B); // ~(A+B) = ~A~B

	and(w4, !A, B, D); // ~ABD

	nor(w5, C, !D); // ~(C+~D)

	nor(w6, w5, w5); // C+~D  

	nor(w7, C, C); // ~(C+C)

	nor(w8, !D, !D); // ~(~D+~D)

	nor(w9, w7, w8); // C~D

	nand(w10, !A, B); // ~(~AB)

	and(w11, B, !C); // B~C

	nand(w12, !B, C); // ~(~BC)

	nor(w14, B, D); // ~(B+D)

	nand(w15, !B, !C); // ~(~B~C)

	and(w16, w15, A); // A~(~B~C)

	or(w17, w14, w9); // ~B~D + C~D

	nand(w18, w17, w17); // 0

	nand(w19, w16, w16); // 0

	nand(e, w18, w19); // A~(~B~C) + ~B~D + C~D

	and(w20, w12, !D); // ~D(~(~BC))

	or(w21, !w12, w9); // ~BC + C~D

	or(w22, A, w11); // A + (B~C)

	or(f, w20, w22); // A + (B~C) + ~D(~(~BC))

	or(g, w21, w22); // ~BC + C~D + A + (B~C)

	nor(w23, w5, w9); // C ^ ~D

	or(b, w10, w23); // ~(~AB) + C ^ ~D

	nand(c, w3, w9); // ~( ~(A+B)(C~D) )

	and(w24, w3, w6); // ~(A+B)(C+~D)

	and(w25, !A, w9); // ~A(C~D)

	or(w26, w24, w25); // ~(A+B)(C+~D) + ~A(C~D)

	and(w27, !C, w4); // ~C(~ABD)

	or(w28, w1, w27); // A~B~C + ~C(~ABD)

	or(d, w26, w28); // ~(A+B)(C+~D) + ~A(C~D) + A~B~C + ~C(~ABD)

	and(w29, !D, w3); // ~D(~(A+B)) = ~D(~A~B)

	or(w30, w1, w2); // A~B~C + ~AC

	or(w31, w4, w29); // ~ABD + ~A~B~D

	or(a, w30, w31);

	endmodule