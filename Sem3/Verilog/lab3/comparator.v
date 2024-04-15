module comparator(a,b,gt,eq,l);
input[2:0]a,b;
output reg gt,eq,l;
wire [2:0]i;
integer j;
always @(a or b)
begin
    for(j=0;j<=2;j=j+1)
    begin
        i[j]=~(a[j]^b[j]);
    end
    eq=i[2]&i[1]&i[0];
    gt=(a[2]&~b[2])|(i[2]&a[1]&~b[1])|(i[2]&i[1]&a[0]&~b[0]);
    l=~(eq|gt);
end
endmodule