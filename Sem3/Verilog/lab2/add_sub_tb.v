`timescale 1ns/1ns
`include "add_sub.v"
module add_sub_tb;
reg[3:0]X,Y;
reg Cin;
wire [3:0]S;
wire Cout;
add_sub as1(X,Y,Cin,S,Cout);
initial begin
    $dumpfile("add_sub_tb.vcd");
    $dumpvars(0,add_sub_tb);
    Cin=0;X=3;Y=2;#20;
    Cin=1;X=3;Y=2;#20;
    Cin=1;X=5;Y=2;#20;
    Cin=0;X=5;Y=2;#20;
    Cin=0;X=4;Y=2;#20;
    $display("Test Completed");
end
endmodule