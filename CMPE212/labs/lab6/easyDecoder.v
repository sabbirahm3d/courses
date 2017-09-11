module easyDecoder(a, b, c, d, e, f, g, X, Y);

	input X, Y;
	output a, b, c, d, e, f, g;

	and(a, ~X, ~Y);

	or(b, 0, 0);

	or(c, X, 0);

	and(d, ~X, ~Y);

	or(e, ~X, Y);

	and(f, ~X, ~Y);

	or(g, ~X, Y);

endmodule