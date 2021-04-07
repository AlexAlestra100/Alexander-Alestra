// Alexander Alestra
// Mux 8 to 1
// compile: iverilog m8x1.v
// run: ./a.out

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

module MuxMod(s, d, o);
   input [2:0] s;
   input [0:7] d;
   output o;

   wire [0:7] s_decoded, and_out;

   DecoderMod my_decoder(s, s_decoded);

   and(and_out[0], d[0], s_decoded[0]);
   and(and_out[1], d[1], s_decoded[1]);
   and(and_out[2], d[2], s_decoded[2]);
   and(and_out[3], d[3], s_decoded[3]);
   and(and_out[4], d[4], s_decoded[4]);
   and(and_out[5], d[5], s_decoded[5]);
   and(and_out[6], d[6], s_decoded[6]);
   and(and_out[7], d[7], s_decoded[7]);

  or(o, and_out[0], and_out[1], and_out[2], and_out[3], and_out[4], and_out[5], and_out[6], and_out[7]);
endmodule

module TestMod;
   reg [2:0] s;
   reg [0:7] d;
   wire o;

   MuxMod my_mux(s, d, o);

   initial begin
     $display("Time  s..  d.......  o");
     $display("----  ---  --------  -");
     $monitor("%4d  %b  %b  %b", $time, s, d, o);
   end
  
   always begin d[7] = 0; #1; d[7] = 1; #1; end
   always begin d[6] = 0; #2; d[6] = 1; #2; end
   always begin d[5] = 0; #4; d[5] = 1; #4; end
   always begin d[4] = 0; #8; d[4] = 1; #8; end
   
   always begin d[3] = 0; #16; d[3] = 1; #16; end
   always begin d[2] = 0; #32; d[2] = 1; #32; end
   always begin d[1] = 0; #64; d[1] = 1; #64; end
   always begin d[0] = 0; #128; d[0] = 1; #128; end   
   
   always begin s[0] = 0; #256; s[0] = 1; #256; end
   always begin s[1] = 0; #512; s[1] = 1; #512; end
   always begin s[2] = 0; #1024; s[2] = 1; #1024; end
   initial #2047 $finish;
     
endmodule