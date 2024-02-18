`timescale 1ns/1ns
`include "ivk_ad2.v"
module ivk_ad2_tb ;
reg x1,x2,x3,x4;
wire f;
ivk_ad2 ivk(x1,x2,x3,x4,f);
initial begin
    $dumpfile("ivk_ad2_tb.vcd");
    $dumpvars(0,ivk_ad2_tb);
    x1=0;x2=0;x3=0;x4=0;#20;
    x1=0;x2=0;x3=0;x4=1;#20;
    x1=0;x2=0;x3=1;x4=0;#20;
    x1=0;x2=0;x3=1;x4=1;#20;
    x1=0;x2=1;x3=0;x4=0;#20;
    x1=0;x2=1;x3=0;x4=1;#20;
    x1=0;x2=1;x3=1;x4=0;#20;
    x1=0;x2=1;x3=1;x4=1;#20;
    x1=1;x2=0;x3=0;x4=0;#20;
    x1=1;x2=0;x3=0;x4=1;#20;
    x1=1;x2=0;x3=1;x4=0;#20;
    x1=1;x2=0;x3=1;x4=1;#20;
    x1=1;x2=1;x3=0;x4=0;#20;
    x1=1;x2=1;x3=0;x4=1;#20;
    x1=1;x2=1;x3=1;x4=0;#20;
    x1=1;x2=1;x3=1;x4=1;#20;
    $display("Test completed");
end
endmodule