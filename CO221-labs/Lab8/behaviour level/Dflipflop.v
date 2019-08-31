module test;

    reg CLK,D,RST;
    wire Q;
    
    dff flipflop(D, CLK, RST, Q);

    // Testing field
    initial begin
        CLK=1;
        D=0;
        RST=1;
        
        $dumpfile("D.vcd");
        $dumpvars(0, flipflop);
        
        #1 D = 1;
        #3 RST = 0;
        #8 D = 0;
        #6 D = 1;
        #2 D = 0;
        #6 D = 1;
        #5 D = 0;
        #6 D = 1;
        #10 RST = 1;
        #10 $finish;
    
    end

always #5 CLK = ~CLK;
   
endmodule


module dff (d ,clk, reset, q);

input clk, reset, d;
output q;
reg q;
  	  	 
always @ (posedge clk or posedge reset)
begin
  if (reset == 1)
     q <= 0;
 else 
     q <= d;
 end
  	  	 
endmodule
    