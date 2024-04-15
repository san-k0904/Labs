module mux4_1(S,w,f);
input [1:0]S;
input[3:0]w;
output reg f;
always @(w,S)
if(S==0)
f=w[0];
else if(S==1)
f=w[1];
else if(S==2)
f=w[2];
else
f=w[3];
endmodule
    