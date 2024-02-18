// module lab2_2(Cin,x,y,Cout,S);
// input Cin,x,y;
// output Cout,S;
// wire g;
// assign g= x^y;
// assign S= Cin^g;
// assign Cout= (Cin &y)|(x&y)|(Cin&x);
// endmodule
module lab2_2(Cin,x,Cout,S);
input Cin;
input [1:0]x;
output reg Cout,S;
always @(x,Cin)
begin
    S=x[0]^x[1]^Cin;
    Cout= (Cin &x[1])|(x[0]&x[1])|(Cin&x[0]);
end
endmodule