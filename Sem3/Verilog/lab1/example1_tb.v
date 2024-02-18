`timescale 1ns/1ns
`include "example1.v"
module example1_tb;
reg A,B,C,D;
wire f;
example1 ex1(A,B,C,D,f);
initial begin
    $dumpfile("example1_tb.vcd");
    $dumpvars(0,example1_tb);
    A=0;B=0;C=0;D=0;#20;
    A=0;B=0;C=0;D=1;#20;
    A=0;B=0;C=1;D=0;#20;
    A=0;B=0;C=1;D=1;#20;
    A=0;B=1;C=0;D=0;#20;
    A=0;B=1;C=0;D=1;#20;
    A=0;B=1;C=1;D=0;#20;
    A=0;B=1;C=1;D=1;#20;
    A=1;B=0;C=0;D=0;#20;
    A=1;B=0;C=0;D=1;#20;
    A=1;B=0;C=1;D=0;#20;
    A=1;B=0;C=1;D=1;#20;
    A=1;B=1;C=0;D=0;#20;
    A=1;B=1;C=0;D=1;#20;
    A=1;B=1;C=1;D=0;#20;
    A=1;B=1;C=1;D=1;#20;
    $display("Test completed");
end
endmodule