`timescale 1ns/1ns
`include "mux4_1.v"
module mux4_1_tb;
reg[3:0]w;
reg[1:0]s;
wire f;
mux4_1 mux(s,w,f);
initial begin
    $dumpfile("mux4_1_tb.vcd");
    $dumpvars(0,mux4_1_tb);
    w=4'b1010;s=0;#20;
    w=4'b1010;s=1;#20;
    w=4'b1010;s=2;#20;
    w=4'b1010;s=3;#20;
end
endmodule