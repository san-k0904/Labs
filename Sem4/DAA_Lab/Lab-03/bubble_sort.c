#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void bubble_sort(int arr[],int n){
    int temp;
    int flag=0;
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            opcount++;
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nOPCOUNT: %d\n",opcount);
    return 0;
}