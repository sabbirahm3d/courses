module funcB(b, A, B, C, D);

input A, B, C, D;
output b;
wire w1, w2;

	nand(w1, !A, B);

	xor(w2, C, !D);

	or(b, w1, w2);

	/* 
	2 x 3 AND, 2(2(3)+2) = 16 transistors
	2 x 2 AND, 2(2(2)+2) = 12 transistors
	1 x 2 NOR, 1(2(2)) = 4 transistors
	4 x 2 OR, 4(2(2)+2) = 24 transitors

	56 transistors total
	*/

	endmodule