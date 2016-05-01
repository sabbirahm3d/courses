module Tb_dflipflop_synrst();

reg data_in;
reg clock,reset;
wire data_out;

d_flipflop_synrst UUT(.data_in(data_in),
.data_out(data_out),
.clock(clock),
.reset(reset));
initial begin
// Initiliase Input Stimulus
data_in = 0;
clock = 0;
reset=0;
end

always #100 clock=~clock;

//Stimulus
initial 
begin 
#200 data_in = 1'b1; 
reset = 1'b1;
#200 data_in = 1'b1;
reset = 1'b1;

#300 data_in = 1'b1;
reset=1'b0;
#600 data_in = 1'b0;
#500 data_in = 1'b1;
#200 data_in = 1'b0;
#400 $stop;
end

endmodule