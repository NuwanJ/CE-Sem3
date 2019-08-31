
/*************************************************************************

	4-bit Combinational ALU design
	
	Group members
		E/15/140 Jaliyagoda A.J.N.M.
		E/15/173 Karunarathna S.D.D.D. 
		E/15/179 Karunaratne S.M.A.K.

	Last update : 01/06/2018
	source code : https://github.com/DDilshani/CO221-ALU

*************************************************************************/


module testbench;

	reg [3:0] A,B;		// Input Registers
	reg [2:0] C;		// Control Signal
	reg [4:0] i; 		// Debugging only
	output [3:0] out;	// Output Register

	ALU myALU(out, A,B, C[2], C[1], C[0]);
	
	initial begin
		A <= 4'b0000; 	// Register A
		B <= 4'b0000; 	// Register B
		C <= 3'b000; 	// Control input signal
		
		$dumpfile("alu.vcd"); 
		$dumpvars(0, myALU);
		
		for(i=0; i<15; i=i+1) begin
			B <= i;
 			A <= i/2;
			#10 $display("Signal=%d (%b)   |   A=%d, B=%d, Out=%d  |   A=%b, B=%b, Out=%b", C,C, A,B,out, A,B,out);
	  	end
	end

endmodule

module ALU(S, A, B, L,M,N);
   input [3:0] A,B;     // Input Registers
   input L, M, N;     // Control Input
   output [3:0] S;      // Output Register
    
	// 4bit wires
	wire [3:0] inA, inB, afterEnA, afterEnB;
	wire [3:0] AandB, AorB, AplusB, AxB, AxorB;
	
	// 1bit wires
	wire EnA, EnB, ABar, BBar, P, Q, R, cIn,  cOut;
	
	moduleEnA myEnA(EnA, L, M, N);
	moduleEnB myEnB(EnB, L, M, N);
	moduleABar myABar(ABar, L, M, N);
	moduleBBar myBBar(BBar, L, M, N);
	moduleCin myCin(cIn, L, M, N);
	
	// AND Module - take bus input if En=1
	busAND myAND1(afterEnA, A, EnA);
	busAND myAND2(afterEnB, B, EnB);
	
	// XOR Module - invert bus input if En=1
	busXOR myXOR1(inA, afterEnA, ABar);
	busXOR myXOR2(inB, afterEnB, BBar);
	
	// -A, -B, A+B, A-B handle from this 4bit Full Adder
	fourBitFullAdder myFullAdder(AplusB,cOut, inA,inB,cIn);
	
	// Bitwise AND operation
	bitwiseAndAB  myAndAB(AandB, A,B);
	
	// Bitwise OR Operation
	bitwiseOrAB myOrAB(AorB, A,B);
	
	// A*B Operation
	AmultiplyB myAxB(AxB, A,B);
	
	// Bonus Operation - A xor B
	bitwiseXOR myAxorB(AxorB, A, B);
	
	// Final output switching modules
	modulePQRfromLMN myController(P,Q,R, L,M,N);
	outputSelector myOutput(S, P,Q,R, AplusB, AandB, AorB, AxB, AxorB);

endmodule

module bitwiseAndAB(R, A, B);
    input [3:0] A, B;
    output [3:0] R;
    
	// S = A & B
    and myAND0(R[0], A[0], B[0]);
    and myAND1(R[1], A[1], B[1]);
    and myAND2(R[2], A[2], B[2]);
    and myAND3(R[3], A[3], B[3]);
    
endmodule

module bitwiseOrAB(R, A, B);
    input [3:0] A, B;
    output [3:0] R;
    
    or (R[0], A[0], B[0]);
    or (R[1], A[1], B[1]);
    or (R[2], A[2], B[2]);
    or (R[3], A[3], B[3]);
    
endmodule

module AmultiplyB(R, A,B);
	input [3:0] A,B;
	output [3:0] R; // R2

	wire [3:0] X0, X1, X2, X3, Y1, Y2, Y3, S1, S2, S3;
	wire p0, p1, p2, p3, p4, p5, p6, p7, cOut1, cOut2, cOut3;
	
	// Level 1
	busAND myA0(X0, A , B[0]);
	busAND myA1(Y1, A, B[1]);
	fourBitFullAdder fA0(S1,cOut1, X1,Y1,1'b0);

	assign p0 = X0[0];
	assign X1[0] = X0[1];
	assign X1[1] = X0[2];
	assign X1[2] = X0[3];
	assign X1[3] = 1'b0;

	// Level 2
	busAND myA2(Y2, A, B[2]);
	fourBitFullAdder fA1(S2,cOut2, X2,Y2,1'b0);

	assign p1 = S1[0];
	assign X2[0] = S1[1];
	assign X2[1] = S1[2];
	assign X2[2] = S1[3];
	assign X2[3] = cOut1;

	// Level 3
	busAND myA3(Y3, A, B[3]);
	fourBitFullAdder fA2(S3,cOut3, X3,Y3,1'b0);
	
	assign p2 = S2[0];
	assign X3[0] = S2[1];
	assign X3[1] = S2[2];
	assign X3[2] = S2[3];
	assign X3[3] = cOut2;

	// Level 4
	assign p3 = S3[0];
	assign p4 = S3[1];
	assign p5 = S3[2];
	assign p6 = S3[3];
	assign p7 = cOut3;

	// Final output
	assign R[0] = p0;
	assign R[1] = p1;
	assign R[2] = p2;
	assign R[3] = p3;

	// Overflowed output
	/*assign R2[0] = p4;
	assign R2[1] = p5;
	assign R2[2] = p6;
	assign R2[3] = p7;*/

endmodule

module bitwiseXOR(AxorB, A, B);
	input [3:0] A, B;
	output [3:0] AxorB;
    
	//AxorB  = A XOR B
	xor (AxorB[0], A[0], B[0]);
	xor (AxorB[1], A[1], B[1]);
	xor (AxorB[2], A[2], B[2]);
	xor (AxorB[3], A[3], B[3]);

endmodule


//---- Control Unit ------------------------------------------------------------------

module moduleEnA(enA, L,M,N);
	input L, M, N;
	output enA;
	wire notL, notM, notN, out1;
	
	// enA = (L'.M'.N)'
	not b1 (notL, L);
	not b2 (notM, M);
	
	and b4 (out1, notL, notM, N);
	not b5 (enA, out1);
	
endmodule 

module moduleEnB(enB, L,M,N);
	input L, M, N;
	output enB;
	wire notL, notM, notN, out2;
	
	// enB = (L'.M'.N')'
	not c1 (notL, L);
	not c2 (notM, M);
	not c3 (notN, N);
	
	and c4 (out2, notL, notM, notN);
	not c5 (enB, out2);

endmodule 

module moduleABar(ABar, L,M,N);
	input L, M, N;
	output ABar;
	wire notL, notM, notN;
	
	// ABar = (L'.M'.N')
	not d1 (notL, L);
	not d2 (notM, M);
	not d3 (notN, N);
	
	and d4 (ABar, notL, notM, notN);
	
endmodule 

module moduleBBar(BBar, L,M,N);
	input L, M, N;
	output BBar;
	wire notL, notN, out2;
	
	// BBar = (L'.N')
	not e1 (notL, L);
	not e3 (notN, N);
	and e4 (out2, notL, notN);
	not e5 (BBar, out2);

endmodule 

module moduleCin(cIn, L,M,N);
	input L,M,N;
	output cIn;
	wire notL, notN, out2;
	
	// cIn = (L'.M.N')'
	not f01(notL, L);
	not f02(notN, N);
	and f03(out2, notL, M, notN);
	not f04(cIn, out2);
	
endmodule 

module modulePQRfromLMN(P,Q,R, L,M,N);
	input L,M, N;
	output P, Q, R;
	wire xorMN, notN; 
	
	// P = L.(M (+) N)
	// Q = L.N'
	// R = L.M.N
	
	xor d1 (xorMN, M,N);
	not d2 (notN, N);
	
	and d3 (P, L,xorMN);
	and d4 (Q, L, notN);
	and d5 (R, L,M,N);

endmodule

module outputSelector(S, P,Q,R, AplusB, AandB, AorB, AxB, AxorB);
	// 4bit output selector
	input [3:0] AplusB, AandB, AorB, AxB, AxorB;
	input P,Q,R;
	output [3:0] S;

	oneBitOutputSelector f11(S[0], P,Q,R, AplusB[0], AandB[0], AorB[0], AxB[0], AxorB[0]);
	oneBitOutputSelector f12(S[1], P,Q,R, AplusB[1], AandB[1], AorB[1], AxB[1], AxorB[1]);
	oneBitOutputSelector f13(S[2], P,Q,R, AplusB[2], AandB[2], AorB[2], AxB[2], AxorB[2]);
	oneBitOutputSelector f14(S[3], P,Q,R, AplusB[3], AandB[3], AorB[3], AxB[3], AxorB[3]);
	
endmodule

module oneBitOutputSelector(S, P,Q,R, AplusB, AandB, AorB, AxB, AxorB);
	// 1bit output selector
	input AplusB, AandB, AorB, AxB, AxorB;
	input P,Q,R;
	output S;
	
	wire pBar, qBar, rBar;
	wire AplusB_out, AandB_out, AorB_out, AxB_out, AxorB_out;
	
	not f21(pBar, P);
	not f22(qBar, Q);
	not f23(rBar, R);
	
	and f24(AplusB_out, AplusB, pBar, qBar, rBar);
	and f25(AandB_out, AandB, pBar, Q, rBar);
	and f26(AorB_out, AorB, P, qBar, rBar);
	and f27(AxB_out, AxB, P, Q, rBar);
	and f28(AxorB_out, AxorB, R);
	
	or f29(S, AplusB_out, AandB_out, AorB_out, AxB_out, AxorB_out);
	
endmodule

//---- 4bit Full Adder ------------------------------------------------------------------

module fourBitFullAdder(AplusB,cOut, inA,inB,cIn);
	input [3:0] inA, inB;
	input cIn;	
	output [3:0] AplusB;	
	output cOut;
	wire w1, w2, w3;
 
	fullAdder add1(inA[0], inB[0], cIn, w1, AplusB[0]);
	fullAdder add2(inA[1], inB[1], w1, w2, AplusB[1]);
	fullAdder add3(inA[2], inB[2], w2, w3, AplusB[2]);
	fullAdder add4(inA[3], inB[3], w3, cOut, AplusB[3]);
endmodule


module fullAdder(A, B, cIn, cOut, S);
	input A,B, cIn;
	output cOut, S;
	wire x,y,z, p;

	halfAdder add1(A,B, x, y);
	halfAdder add2(y, cIn, z, S);
	or u1(cOut, x, z);
	
endmodule

module halfAdder(A, B, cOut, S);
	input A,B;
	output cOut, S;

	// Get A,B bits and results A+B
	and u1(cOut, A,B);
	xor u2(S, A,B);

endmodule

//---- support Modules for 4bit fullAdder ----------------------------------------------

module busAND(Y, X, En);
   input [3:0] X;
   input En;
   output [3:0] Y;
    
   // if (EnA==1) ? Y=X : Y= 4'b0000
	and f31(Y[0], X[0], En);
	and f32(Y[1], X[1], En);
	and f33(Y[2], X[2], En);
	and f34(Y[3], X[3], En);
	
endmodule

module busXOR(Y, X, En);
	input [3:0] X;
   input En;
   output [3:0] Y;

	// if (EnA==1) ? Y=xor(Y, 1) : Y= Y    
	xor f41(Y[0], X[0], En);
	xor f42(Y[1], X[1], En);
	xor f43(Y[2], X[2], En);
	xor f44(Y[3], X[3], En);
	
endmodule


