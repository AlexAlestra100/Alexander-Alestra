module DecoderMod(s, o);
  input [2:0] s;
  output [0:7] o;
	
  wire [2:0] not_i;
  
  not(not_i[2], s[2]);
  not(not_i[1], s[1]);
  not(not_i[0], s[0]);
  
  and(o[0], not_i[2], not_i[1], not_i[0]);
  and(o[1], not_i[2], not_i[1], s[0]);
  and(o[2], not_i[2], s[1], not_i[0]);
  and(o[3], not_i[2], s[1], s[0]);
  and(o[4], s[2], not_i[1], not_i[0]);
  and(o[5], s[2], not_i[1], s[0]);
  and(o[6], s[2], s[1], not_i[0]);
  and(o[7], s[2], s[1], s[0]);
endmodule

module TestMod;
  reg [2:0] s;
  wire [0:7] o;

  DecoderMod my_decoder(s, o);

   initial begin
     $monitor("%4d   %b   %b", $time, s, o);
     $display("Time   s..   o.......");
     $display("----   ---   --------");
   end

   initial begin
        s = 3'b000; #1;
        s = 3'b001; #1;
        s = 3'b010; #1;
        s = 3'b011; #1;
        s = 3'b100; #1;
        s = 3'b101; #1;
     	s = 3'b110; #1;
        s = 3'b111;
   end
endmodule