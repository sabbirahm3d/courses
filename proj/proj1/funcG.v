module funcG(g, A, B, C, D);

input A, B, C, D;
output g;
wire w1, w2, w3, w4, w5, w6, w7;

	and(w1, C, !D); // 2 NOR

	or(w2, w1, A); // 2 AND

	xor(w3, B, C); // 2 NAND

	or(g, w2, w3);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule