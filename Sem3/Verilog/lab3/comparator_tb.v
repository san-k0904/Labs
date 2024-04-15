`timescale 1ns/1ns
`include "comparator.v"
module comparator_tb;
reg [2:0]a,b;
wire eq,gt,l;
comparator comp(a,b,gt,eq,l);
initial begin 
    $dumpfile("comparator_tb.vcd");
    $dumpvars(0,comparator_tb);
    a=3'b101;b=3'b101;#20;
    a=3'b001;b=3'b111;#20;
    a=3'b010;b=3'b110;#20;
    a=3'b101;b=3'b011;#20;
    $display("Test complete");
end
endmodule