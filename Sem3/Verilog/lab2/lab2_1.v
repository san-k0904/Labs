module lab2_1(A,B,C,D,g,f);
input A,B,C,D;
output f,g;
wire g;
assign g= C^D;
assign f= (A&g)|(B&~g);
endmodule