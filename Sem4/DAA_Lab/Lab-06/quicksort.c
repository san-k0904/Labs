#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int partition(int* arr,int l,int h){
    int i,j,temp;
    i=l;
    j=h;
    do{
        do{i++;}while(arr[i]<=arr[l]);
        do{j--;}while(arr[j]>arr[l]);
        if(i<j){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }while(i<j);
    temp=arr[j];
    arr[j]=arr[l];
    arr[l]=temp;
    return j;
}
void quicksort(int* arr,int l,int h){
    int j;
    if(l<h){
        j=partition(arr,l,h);
        quicksort(arr,l,j);
        quicksort(arr,j+1,h);
    }

}
int main(){
    int a[]={10,27,2,4,8,34,INT32_MAX};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    printf("Sorted array: ");
    for(int i=0;i<n-1;i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
    return 0;
}