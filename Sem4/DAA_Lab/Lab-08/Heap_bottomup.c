#include<stdio.h>
#include<stdlib.h>
void heapify(int a[],int n){
    int j;
    for(int i=n/2;i>=1;i--){
        j=2*i;
        while(j<=n-1){
            if(a[j]<a[j+1]){
                j=j+1;
            }
            if(a[i]<a[j]){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
                i=j;
                j=2*i;
            }
            else
                break;
        }
    }
}
int main(){
    int a[]={-1,10,20,30,25,5,40,35};
    heapify(a,7);
    for(int j=1;j<=7;j++){
        printf("%d\t",a[j]);
    }
    printf("\n");
    return 0;
}