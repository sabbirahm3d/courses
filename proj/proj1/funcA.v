module funcA(a, A, B, C, D);

input A, B, C, D;
output a;
wire w1, w2, w3, w4, w5, w6, w7;

	and(w1, A, !B, !C); // 3 AND

	and(w2, !A, C); // 2 AND

	nor(w3, A, B); // 2 NOR

	and(w4, !A, B, D); // 3 AND

	or(R, w2, w3); // 2 OR

	and(w5, w3, !D); // 2 AND

	or(w6, w1, w2); // 2 OR

	or(w7, w5, w4); // 2 OR

	or(a, w6, w7); // 2 OR


	/* 
	2 x 3 AND, 2(2(3)+2) = 16 transistors
	2 x 2 AND, 2(2(2)+2) = 12 transistors
	1 x 2 NOR, 1(2(2)) = 4 transistors
	4 x 2 OR, 4(2(2)+2) = 24 transitors

	56 transistors total
	*/

	endmodule