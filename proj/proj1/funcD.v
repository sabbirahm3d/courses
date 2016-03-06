module funcD(d, A, B, C, D);

input A, B, C, D;
output d;
wire w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13;

	and(w1, A, !B, !C); // A~B~C

	and(w2, !A, B, D); // ~ABD

	and(w3, w2, !C); // ~AB~CD

	or(w4, w1, w3); // A~B~C + ~AB~CD

	nor(w5, C, C); // ~(C+C)

	nor(w6, !D, !D); // ~(~D+~D)

	nor(w7, w5, w6); // ~( ~(C+C) + ~(~D+~D) ) = C~D

	and(w8, w7, !A); // ~A(C~D)

	nor(w9, C, !D); // ~( C+~D )

	nor(w10, w9, w9); // ~( ~(C+~D) + ~(C+~D) ) = C+~D

	nor(w11, A, B); // ~(A+B) = ~A~B

	and(w12, w10, w11); // ~A~B(C+~D)

	or(w13, w12, w8); // ~A~B(C+~D) + ~A(C~D)

	or(d, w13, w4); // ~A~B(C+~D) + ~A(C~D) + A~B~C + ~AB~CD

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule