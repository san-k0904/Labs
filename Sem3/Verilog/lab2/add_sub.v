module fulladd(Cout,S,x,y,Cin);
input x,y,Cin;
output Cout,S;
assign S=x^y^Cin;
assign Cout=(Cin&y)|(Cin&x)|(x&y);
endmodule
module add_sub(X,Y,Cin,S,Cout);
input[3:0]X,Y;
input Cin;
output[3:0]S;
output Cout;
wire [3:0]B;
wire [3:1]C;
assign B[0]=Y[0]^Cin;
assign B[1]=Y[1]^Cin;
assign B[2]=Y[2]^Cin;
assign B[3]=Y[3]^Cin;
fulladd add1(C[1],S[0],X[0],B[0],Cin);
fulladd add2(C[2],S[1],X[1],B[1],C[1]);
fulladd add3(C[3],S[2],X[2],B[2],C[2]);
fulladd add4(Cout,S[3],X[3],B[3],C[3]);
endmodule