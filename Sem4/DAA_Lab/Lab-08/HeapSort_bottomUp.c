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
void delete(int a[],int n){
    int x;
    x=a[n];
    a[n]=a[1];
    a[1]=x;
    // int i=1;
    // int j=2*i;
    // while(j<n-1){
    //     if(a[j]<a[j+1]){
    //         j=j+1;
    //     }
    //     if(a[i]<a[j]){
    //         int temp=a[j];
    //         a[j]=a[i];
    //         a[i]=temp;
    //         i=j;
    //         j=2*i;
    //     }
    //     else
    //         break;

    // }
    heapify(a,n-1);
}
int main(){
    int a[]={-1,10,20,30,25,5,40,35};
    heapify(a,7);
    
    for(int j=7;j>1;j--){
        delete(a,j);
    }
    printf("Sorted array is: \n");
    for(int k=1;k<=7;k++){
        printf("%d\t",a[k]);
    }

    printf("\n");
    return 0;
}