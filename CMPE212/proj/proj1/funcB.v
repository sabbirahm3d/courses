module funcB(b, A, B, C, D);

input A, B, C, D;
output b;
wire w1, w2, w3, w4, w5, w6;

	nand(w1, !A, B);

	nor(w2, C, C);

	nor(w3, !D, !D);

	nor(w4, C, !D);

	nor(w5, w2, w3);

	nor(w6, w4, w5);

	or(b, w1, w6);

	/* 
	2 x 3 AND, 2(2(3)+2) = 16 transistors
	2 x 2 AND, 2(2(2)+2) = 12 transistors
	1 x 2 NOR, 1(2(2)) = 4 transistors
	4 x 2 OR, 4(2(2)+2) = 24 transitors

	56 transistors total
	*/

	endmodule