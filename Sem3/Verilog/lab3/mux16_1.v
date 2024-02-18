module mux8_1(S,w,f);
input[2:0]S;
input[0:7]w;
output reg f;
always @(w or S)
begin
case(S)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
end
endmodule
module mux2_1(S,w,f);
input S;
input [0:1]w;
output reg f;
always @(S or w)
f=S?w[1]:w[0];
endmodule
module mux16_1(S,W,f);
input[3:0]S;
input[0:15]W;
output f;
wire [1:0]c;
mux8_1 stage0(S[2:0],W[0:7],c[0]);
mux8_1 stage1(S[2:0],W[8:15],c[1]);
mux2_1 stage2(S[3],c,f);
endmodule