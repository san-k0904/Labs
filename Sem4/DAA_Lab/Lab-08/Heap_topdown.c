#include<stdio.h>
#include<stdlib.h>
void InsertasHeap(int a[],int n){
    int i,temp;
    i=n;
    temp=a[n];
    while(i>1 && temp>a[i/2]){//for minheap temp<a[i/2];
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int main(){
    int a[]={-1,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++){
        InsertasHeap(a,i);
    }
    for(int j=1;j<=7;j++){
        printf("%d\t",a[j]);
    }
    printf("\n");
    return 0;

}