module logic();

integer i;
reg [7:0] ram [0:255];

initial begin
  for (i = 0; i < 256; i = i + 1) begin
    #1 $display(" Address = %g  Data = %h",i,ram[i]);
    ram[i] <= 0; // Initialize the RAM with 0
    #1 $display(" Address = %g  Data = %h",i,ram[i]);
  end
  #1 $finish;
end

endmodule