module FullAdderMod(X, Y, Ci, S, Co);
	input X, Y, Ci;
	output S, Co;
	wire [0:2] t;
	
	xor(t[0], X, Y);
	and(t[1], X, Y);
	xor(S, t[0], Ci);
	and(t[2], Ci, t[0]);
	or(Co, t[2], t[1]);
endmodule

module BigAdder(X, Y, S, C5);
	input [4:0] X, Y;
	output [4:0] S;
	output C5;
	wire [0:3] Tc;
	wire Fc;
  	assign Fc = 0;
	
	FullAdderMod F0(X[0], Y[0], Fc, S[0], Tc[0]);
	FullAdderMod F1(X[1], Y[1], Tc[0], S[1], Tc[1]);
	FullAdderMod F2(X[2], Y[2], Tc[1], S[2], Tc[2]);
	FullAdderMod F3(X[3], Y[3], Tc[2], S[3], Tc[3]);
	FullAdderMod F4(X[4], Y[4], Tc[3], S[4], C5);
endmodule

module TestMod;
	reg [4:0] X, Y;
	wire [4:0] S;
	wire C5;

	BigAdder B0(X, Y, S, C5);

	initial begin
		$monitor("%4d   %d(%b)   %d(%b)   %d(%b)   %b", $time, X, X, Y, Y, S, S, C5);
		$display("Time   X........   Y........   S........   C");
		$display("----   ---------   ---------   ---------   -");
	end

	initial begin
		X = 5'b00001; Y = 5'b00001; #1;
        X = 5'b00010; Y = 5'b00101; #1;
		X = 5'b01010; Y = 5'b01111; #1;
		X = 5'b10001; Y = 5'b10011; #1;
		X = 5'b00001; Y = 5'b11111; #1;
		X = 5'b11111; Y = 5'b11111;
	end
endmodule
