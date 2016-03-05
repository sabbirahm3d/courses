module ledSegs(S, R, A, B, C);

	input A, B, C;
	output S, R;
	wire w1, w2, w3;

	xor(w1, A, B);

	and(w3, A, B);

	and(w2, w1, C);

	xor(S, w1, C);

	or(R, w2, w3);

endmodule