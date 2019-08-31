/**************************************************************
	Lab 7: 4bit Ripple Full Adder

	Group A3
	(E/15/138, E/15/140, E/15/142)
 
	Last Update: 2018/05/26

**************************************************************/

module testbench;

	reg [3:0] A,B;
	wire [3:0] S;
	wire cOut;
	reg [3:0] i,j;
	
	bitFullAdder myFullAdder(A,B,S, 1'b0, cOut);
	
	initial begin
		A <= 4'b0000;
		B <= 4'b0000;

		$dumpfile("adder.vcd"); 
		$dumpvars(0, myFullAdder);
     
 
		for(i=0; i<15; i=i+1) begin
			#1 $display(" A(0000),  B(0000),  S(0000), cOut\n");

			for(j=0; j<15; j=j+1) begin
				A <= i;
 				B <= j;
				#2 $display("%2d(%b), %2d(%b), %2d(%b), %b", i, i, j, j, S, S, cOut);
	  		end
			#1 $display("\n");
  		end
		
		#10 $finish;
	end

endmodule

module bitFullAdder(A,B,S,cIn,cOut);

	//get A,B (4bit registers), cIn and results R(4bit), cOut

	input [3:0] A,B;
	input cIn;

	output [3:0] S;
	output cOut;

	wire w1, w2, w3;
 
	fullAdder add1(A[0], B[0], cIn, w1, S[0]);
	fullAdder add2(A[1], B[1], w1, w2, S[1]);
	fullAdder add3(A[2], B[2], w2, w3, S[2]);
	fullAdder add4(A[3], B[3], w3, cOut, S[3]);

endmodule

module fullAdder(A, B, cIn, cOut, S);

	input A,B, cIn;
	output cOut, S;
	wire x,y,z, p;

	halfAdder add1(A,B, x, y);
	halfAdder add2(y, cIn, z, S);
	or u1(cOut, x, z);
	
	/*input A,B,cIn; output S,cOut;
	assign {cOut,S} = A + B + cIn;
	*/
endmodule

module halfAdder(A, B, cOut, S);
	// Get A,B bits and results A+B

	input A,B;
	output cOut, S;

	and u1(cOut, A,B);
	xor u2(S, A,B);

endmodule
