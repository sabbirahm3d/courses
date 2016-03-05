module sampletestbench();


   reg [2:0] switches;

   // 3 inputs for A, B, and C                                             
   wire [1:0] out;

   lab6 labby(out[1],out[0],switches[2],switches[1],switches[0]);


   initial

     begin
        switches = 3'b111;

        $display("\t\t switches=ABC, out\n");

        #45 $finish;

     end

   always

     begin
        #5 switches = switches + 3'b001;

        $monitor($time, " switches=%b, out=%b", switches, out);

        // $monitor displays the time and the string everytime             
        // 'switches' or 'out' changes value.                              
     end

endmodule