`timescale 1ns/1ns
`include "fourbit_comparator.v"
module fourbit_comparator_tb;
reg [2:0]a,b;
wire eq,gt,l;
fourbit_comparator comp(a,b,gt,eq,l);
initial begin 
    $dumpfile("fourbit_comparator_tb.vcd");
    $dumpvars(0,fourbit_comparator_tb);
    a=4'b1101;b=4'b1101;#20;
    a=4'b0001;b=4'b1111;#20;
    a=4'b0010;b=4'b1110;#20;
    a=4'b1101;b=4'b0011;#20;
    $display("Test complete");
end
endmodule