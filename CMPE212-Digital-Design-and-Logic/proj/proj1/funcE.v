module funcE(e, A, B, C, D);

input A, B, C, D;
output e;
wire w1, w2, w3, w4;

	nor(w1, B, D); // ~(B+D) = ~B~D

	and(w0, C, !D);

	or(w2, w1, w0);

	nand(w3, !B, !C);

	and(w4, w3, A);

	nand(w5, w2, w2);

	nand(w6, w4, w4);

	nand(e, w5, w6);

	// or(w1, B, C); // 2 NOR

	// or(w2, !B, C); // 2 AND

	// and(w3, w1, A); // 2 NAND

	// and(w4, w2, !D);

	// or(e, w3, w4);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule