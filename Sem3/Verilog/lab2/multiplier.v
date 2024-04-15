module fulladd(Cin,x,y,Cout,S);
input Cin,x,y;
output Cout,S;
wire g;
assign g= x^y;
assign S= Cin^g;
assign Cout= (Cin &y)|(x&y)|(Cin&x);
endmodule
module multiplier(X,Y,P);
input[2:0]X,Y;
output[5:0]P;
wire [3:1]c0,c1;
wire [1:0]s;
assign P[0]=X[0]&Y[0];
wire zero_bit=1'b0;
fulladd stage0(zero_bit,(X[1]&Y[0]),(X[0]&Y[1]),c0[1],P[1]);
fulladd stage1(c0[1],(X[2]&Y[0]),(X[1]&Y[1]),c0[2],s[0]);
fulladd stage3(c0[2],(X[2]&Y[1]),zero_bit,c0[3],s[1]);
fulladd stage4(zero_bit,(X[0]&Y[2]),s[0],c1[1],P[2]);
fulladd stage5(c1[1],(X[1]&Y[2]),s[1],c1[2],P[3]);
fulladd stage6(c1[2],(X[2]&Y[2]),c0[3],P[5],P[4]);
endmodule