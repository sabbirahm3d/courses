module circuitTestbench();

   // 4 inputs for A, B, C, and D                                             
   reg [3:0] switches;

   wire a, b, c, d, e, f, g;

   circuit funcA(a, b, c, d, e, f, g, switches[3], switches[2],switches[1],switches[0]);


   initial

     begin
        switches = 4'b1111;

        $display("switches = ABCD, a, b, c, d, e, f, g\n");

        #80 $finish;

     end

   always

     begin
        #5 switches = switches + 4'b0001;

        $monitor("%b: %d: a=%b, b=%b, c=%b, d=%b, e=%b, f=%b, g=%b", switches, switches, a, b, c, d, e, f, g);

        // $monitor displays the time and the string everytime             
        // 'switches' or 'out' changes value.                              
     end

endmodule