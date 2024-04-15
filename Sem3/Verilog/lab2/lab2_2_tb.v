`timescale 1ns/1ns
`include "lab2_2.v"
module lab2_2_tb;
reg [1:0]x;
reg Cin;
wire S,Cout;
lab2_2 l22 (Cin,x,Cout,S);
initial begin
    $dumpfile("lab2_2_tb.vcd");
    $dumpvars(0,lab2_2_tb);
    Cin=0;x[0]=0;x[1]=0;#20;
    Cin=0;x[0]=0;x[1]=1;#20;
    Cin=0;x[0]=1;x[1]=0;#20;
    Cin=0;x[0]=1;x[1]=1;#20;
    Cin=1;x[0]=0;x[1]=0;#20;
    Cin=1;x[0]=0;x[1]=1;#20;
    Cin=1;x[0]=1;x[1]=0;#20;
    Cin=1;x[0]=1;x[1]=1;#20;
    $display("Test Completed");
end
endmodule