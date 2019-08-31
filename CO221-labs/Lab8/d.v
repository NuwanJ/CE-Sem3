
/**************************************************************
	Lab 8: Hardware level D-latch (Positive Edge Trigger)

	Author: Jaliyagoda A.J.N.M. (E/15/140)
	Last Update: 2018/05/26

**************************************************************/

module testbench;

	reg CLK, RST, D;
	output Q;

	positiveEdgeD myD(CLK, RST, D, Q);

    initial begin
        CLK=1;
        D=0;
        RST=1;
        
        $dumpfile("D3.vcd"); // rising edge
        $dumpvars(0, myD);

        #1 RST = 1;
		  #2 RST = 0;
        #1 D = 1;
        #3 RST = 0;
        #8 D = 0;
        #6 D = 1;
        #2 D = 0;
        #6 D = 1;
        #5 D = 0;
        #6 D = 1;
        #8 RST = 1;
        #10 $finish;
    
    end

always #5 CLK = ~CLK;

endmodule

module positiveEdgeD(CLK, RST, D, Q);
	// Positive edge triggered D-flipflop using master-slave arrangement

	input CLK, RST, D;
	output Q;
	wire clkBar;

	not u1(clkBar, CLK);	
	dFlipFlop masterD(clkBar, RST, D, Qm);
	dFlipFlop slaveD(CLK, RST, Qm, Q);

endmodule


module dFlipFlop(clk, reset, d, q);
	// Basic D Flipflop

	input clk, reset, d;
	output q;
	wire notD, r, s , rWithReset, sWithReset; 

	not(notD, d);
	not(notReset, reset);
	and(r, notD, clk);
	and(s, d, clk);
	or(rWithReset, r, reset);
	and(sWithReset, s, notReset);

	srLatch sr(sWithReset, rWithReset, q);

endmodule

module srLatch(s, r, q);
	// Basic SR Latch

	input s, r;
	output q;
	wire qBar;

	nor(q, r, qBar);
	nor(qBar, s, q);

endmodule
