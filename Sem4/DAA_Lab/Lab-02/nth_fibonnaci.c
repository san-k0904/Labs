#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int fibonnaci(int n,int a,int b){
    int r;
    if(n>2){
        r=a+b;
        a=b;
        b=r;
        opcount++;
        return fibonnaci(n-1,a,b);
        
    }
    return b;
}
int main(){
    int n;
    printf("Enter which fibonnaci number you want: ");
    scanf("%d",&n);
    int result;
    if(n<3){
        if(n==1){
            result=0;
        }
        else if(n==2){
            result=1;
        }
        else{
            printf("Wrong.\n");
            exit(0);
        }
    }
    else{
        result=fibonnaci(n,0,1);
    }
    printf("THE fibonnaci number is: %d\n",result);
    printf("OpCount: %d\n",opcount);
    return 0;
}