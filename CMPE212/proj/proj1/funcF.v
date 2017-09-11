module funcF(f, A, B, C, D);

input A, B, C, D;
output f;
wire w1, w2, w3, w4;

	and(w1, B, !C);

	or(w2, w1, A);

	nand(w3, !B, C);

	and(w4, w3, !D);

	or(f, w2, w4);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule