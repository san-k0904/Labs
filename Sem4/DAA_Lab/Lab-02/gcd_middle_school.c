#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int min(int a,int b){
    return a>b?a:b;
}
void gcd(int m,int n){
    int k;
    int g=1;
    printf("Common prime nos.: ");
    while(m!=1 && n!=1){
        k=2;
        while(m%k!=0 ||n%k!=0){
            k++;
            if(k>min(m,n))
                break;
        }
        if(isPrime(k)){
            printf("%d ",k);
            m=m/k;
            n=n/k;
            g*=k;
        }
        if(k>min(m,n))
            break;
        
    }
    printf(";gcd= %d\n",g);
}
// Sieve_of_Erathonesis(int n,int arr[]){
//     int prime[n+1];
//     memset(prime,1,sizeof(prime));
//     for(int i=2;i*i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             if(j%i==0){
//                 prime[j]=0;
//             }
//         }
//     }


// }
int main(){
    int m,n;
    printf("Enter value of m: ");
    scanf("%d",&m);
    printf("Enter value of n: ");
    scanf("%d",&n);
    gcd(m,n);
    return 0;
}