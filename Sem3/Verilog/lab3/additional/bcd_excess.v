module bcd_excess(a,e);
input [3:0]a;
output reg [3:0]e;
always @(a)
begin
    e[0]=(~a[0]&~a[3])+(~a[1]&~a[0]&~a[2]);
    e[1]=(~a[1]&a[0]&~a[2])|(~a[3]&~(a[1]^a[0]));
    e[2]=(~a[1]&a[0]&~a[2])|(a[1]&~a[3]&~a[2])|(~a[1]&~a[0]&~a[3]&a[2]);
    e[3]=(a[0]&~a[3]&a[2])|(a[1]&~a[3]&a[2])|(~a[1]&a[3]&~a[2]);
end
endmodule