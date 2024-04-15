#include<stdio.h>
#include<stdlib.h>

int gcd(int m,int n){
    int opcount=0;
    int r;
    while(n!=0){
        opcount++;
        r=m%n;
        m=n;
        n=r;
    }
    opcount++;
    printf("The Opcount for this is: %d\n",opcount);
    return m;
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