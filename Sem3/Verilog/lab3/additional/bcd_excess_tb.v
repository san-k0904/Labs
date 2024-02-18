`timescale 1ns/1ns
`include "bcd_excess.v"
module bcd_excess_tb;
reg[3:0]a;
wire[3:0]e;
bcd_excess be(a,e);
initial begin
    $dumpfile("bcd_excess_tb.vcd");
    $dumpvars(0,bcd_excess_tb);
    a=0;#20;
    a=1;#20;
    a=2;#20;
    a=3;#20;
    a=4;#20;
    a=5;#20;
    a=6;#20;
    a=7;#20;
    a=8;#20;
    a=9;#20;
    $display("Test complete");
end
endmodule