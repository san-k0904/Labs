`timescale 1ns/1ns
`include "lab2_1.v"
module lab2_1_tb;
reg A,B,C,D;
wire f,g;
lab2_1 l21 (A,B,C,D,g,f);
initial begin
    $dumpfile("lab2_1_tb.vcd");
    $dumpvars(0,lab2_1_tb);
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