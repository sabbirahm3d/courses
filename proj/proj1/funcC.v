module funcC(c, A, B, C, D);

input A, B, C, D;
output c;
wire w1, w2, w3, w4, w5, w6, w7;

	nor(w1, A, B); // 2 NOR

	and(w2, C, !D); // 2 AND

	nand(c, w1, w2); // 2 NAND

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule