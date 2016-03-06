module testbench();

   // 4 inputs for A, B, C, and D                                             
   reg [3:0] switches;

   wire a, b, c, d, e, f, g;

   funcA funcA(a, switches[3], switches[2],switches[1],switches[0]);
   funcB funcB(b, switches[3], switches[2],switches[1],switches[0]);
   funcC funcC(c, switches[3], switches[2],switches[1],switches[0]);
   funcD funcD(d, switches[3], switches[2],switches[1],switches[0]);
   funcE funcE(e, switches[3], switches[2],switches[1],switches[0]);
   funcF funcF(f, switches[3], switches[2],switches[1],switches[0]);
   funcG funcG(g, switches[3], switches[2],switches[1],switches[0]);


   initial

     begin
        switches = 4'b1111;

        $display("switches = ABCD, a, b, c, d, e, f, g\n");

        #80 $finish;

     end

   always

     begin
        #5 switches = switches + 4'b0001;

        $monitor("switches=%b, a=%b, b=%b, c=%b, d=%b, e=%b, f=%b, g=%b", switches, a, b, c, d, e, f, g);

        // $monitor displays the time and the string everytime             
        // 'switches' or 'out' changes value.                              
     end

endmodule