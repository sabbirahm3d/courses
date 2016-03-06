module funcF(f, A, B, C, D);

input A, B, C, D;
output f;
wire w1, w2, w3, w4, w5, w6, w7;

	nand(w1, C, D); // 2 NOR

	and(w2, w1, B); // 2 AND

	or(w3, w2, A); // 2 NAND

	nor(w4, C, D);

	or(f, w3, w4);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule