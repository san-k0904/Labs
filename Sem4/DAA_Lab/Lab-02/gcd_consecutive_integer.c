#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
    return a>b?a:b;
}
int gcd(int m,int n){
    int opcount=0;
    int t;
    t=min(m,n);
    while(m%t!=0||n%t!=0){
        t=t-1;
        opcount++;
    }
    opcount++;
    printf("Opcount: %d\n",opcount);
    return t;
}
int main(){
    int m,n,g;
    printf("Enter value of m: ");
    scanf("%d",&m);
    printf("Enter value of n: ");
    scanf("%d",&n);
    g=gcd(m,n);
    printf("GCD of %d and %d=%d\n",m,n,g);
    return 0;
}