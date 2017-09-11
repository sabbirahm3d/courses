// decoder.v
// Module for 3-8 decoder

module decoder (
    input enable, // Enable for the decoder
    input [2:0] binary_in, // 4 bit binary input
    output [7:0] decoder_out // 16-bit out 
);

    wire [7:0] decoder_out ; 

    assign decoder_out = (enable) ? (1 << binary_in) : 8'b0 ;

endmodule