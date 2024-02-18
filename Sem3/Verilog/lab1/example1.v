module example1 (A,B,C,D,f);
    input A,B,C,D;
    output f;
    assign f=C|(A&~D);
endmodule