module funcG(g, A, B, C, D);

input A, B, C, D;
output g;
wire w1, w2, w3, w4, w5, w6, w7;

	nor(w1, C, C);

	nor(w2, !D, !D);

	nor(w3, w1, w2); // ~(C+~D)

	and(w4, B, !C);

	nand(w5, !B, C);

	or(w6, w4, A);

	or(w7, !w5, w3);

	or(g, w6, w7);

	/*
	1 x 2 NOR, 1(2(2)) = 4 transistors
	1 x 2 AND, 1(2(2)+2) = 6 transistors
	1 x 2 NAND, 1(2(2)) = 4 transistors

	14 transistors total
	*/

	endmodule