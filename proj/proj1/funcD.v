module funcD(d, A, B, C, D);

input A, B, C, D;
output d;
wire w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;

	and(w1, A, !B, !C);

	and(w2, !A, B, D);

	and(w3, w2, !C);

	or(w4, w1, w3);

	and(w5, C, !D);

	and(w6, w5, !A);

	or(w7, C, !D);

	nor(w8, A, B);

	and(w9, w7, w8);

	or(w10, w6, w9);

	or(d, w4, w10);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule