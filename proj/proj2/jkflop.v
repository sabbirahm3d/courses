`define TICK #2 //Flip-flop time delay 2 units
module jkflop(j,k,clk,rst,q);
input j,k,clk,rst;
output q;
reg q;
always @(posedge clk)begin
    if(j==1 & k==1 & rst==0)begin
        q <=`TICK ~q; //Toggles
    end
    else if(j==1 & k==0 & rst==0)begin
        q <= `TICK 1; //Set
    end
    else if(j==0 & k==1)begin
        q <= `TICK 0; //Cleared
    end
 end
 
 always @(posedge rst)begin
 q <= 0; //The reset normally has negligible delay and hence ignored.
 end
 
 endmodule