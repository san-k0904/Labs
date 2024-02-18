`timescale 1ns/1ns
`include "multiplier.v"
module multiplier_tb;
reg [2:0]X,Y;
wire[5:0]P;
multiplier multi(X,Y,P);
initial begin
    $dumpfile("multiplier_tb.vcd");
    $dumpvars(0,multiplier_tb);
    X=2;Y=5;#20;
    X=0;Y=2;#20;
    X=7;Y=7;#20;
    X=6;Y=4;#20;
    X=4;Y=1;#20;
    $display("Test completed");
end
endmodule