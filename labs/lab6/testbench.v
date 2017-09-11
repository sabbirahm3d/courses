module testbench4easyDecoder();

   reg [1:0] switches;

   wire [6:0] LED;


   easyDecoder d1(LED[6], LED[5], LED[4], LED[3], LED[2], LED[1], LED[0], switches[1], switches[0]);


   initial
     begin
        switches = 00;
        $display("switches=XY, LEDs=abcdefg\n");
        #50 $finish;
     end

   always
     begin
        #10 $display("switches=%b, LEDs=%b", switches, LED);
        switches = switches + 01;
     end

endmodule