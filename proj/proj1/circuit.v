module circuit(a, b, c, d, e, f, g, A, B, C, D);

input A, B, C, D;
output a, b, c, d, e, f, g;
wire w1, w2, w3, w4, w5, w6, w7;

	and(w1, A, !B, ~C); // A~B~C

	and(w2, !A, C); // ~AC

	nor(w3, A, B); // ~(A+B)

	and(w4, !A, B, D); // ~ABD

	nor(w5, C, !D); // ~(C+~D)

	nor(w6, C, C); // ~(C+C)

	nor(w7, !D, !D); // (~D+~D)

	nor(w8, w6, w7); // C~D

	nor(w9, w5, w5); // C+~D

	nor(w10, w5, w8); // C^~D

	nand(w11, !A, B); // ~(~AB)

	and(w12, B, !C); // B~C

	nand(w13, !B, C); // ~(~BC)

	and(w14, w13, !D); // ~D(~(~BC))

	or(w15, !w13, w8); // ~BC + C~D

	or(w16, w12, A); // A + B~C

	or(f, w16, w14); // A + B~C + ~D(~(~BC))

	or(g, w15, w16); // A + B~C + ~B + C~D

	or(b, w10, w11); // A + ~B + C^~B

	and(w17, w3, !D); // ~A~B~D

	and(w18, w4, !C); // ~AB~CD

	and(w19, w9, w3); // ~A~B(C+~D)

	nand(c, w8, w3); // ~(~A~B)(C~D)

	or(w20, w1, w2); // A~B~C + ~AC

	or(w21, w4, w17); // ~A~B~D + ~ABD

	or(a, w20, w21); // A~B~C + ~AC + ~(A+B)(~D) + ~ABD

	or(w22, w18, w1); // A~B~C + ~AB~CD

	or(w23, w8, !A); // ~A(C~D)

	or(w24, w23, w18); // ~A(C~D) + ~A~CBD

	or(d, w24, w22); // A~B~C + ~A~C(BD) + ~(A+B)(C+~D) + ~A(C~D)


	endmodule