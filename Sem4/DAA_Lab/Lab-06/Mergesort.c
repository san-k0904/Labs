#include<stdio.h>
#include<stdlib.h>
void merge(int* arr,int l,int h,int mid){
    int i,j,k;
    i=l;j=mid+1;k=l;
    int B[h+1];
    while(i<=mid&& j<=h){
        if(arr[i]<arr[j])
            B[k++]=arr[i++];
        else
            B[k++]=arr[j++];
    }
    for(;i<=mid;i++){
        B[k++]=arr[i];
    }
    for(;j<=h;j++){
        B[k++]=arr[j];
    }
    for(i=l;i<=h;i++){
        arr[i]=B[i];
    }
}
void Mergesort(int* arr, int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        Mergesort(arr,l,mid);
        Mergesort(arr,mid+1,h);
        merge(arr,l,h,mid);
    }
}
void IMergeSort(int* arr, int n){
    int p,i,l,h,mid;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(arr,l,h,mid);
        }
        if(p/2<n)
        merge(arr,0,p/2-1,n-1);
        
    }
}
int main(){
    int a[]={10,27,2,4,8,34};
    int n=sizeof(a)/sizeof(a[0]);
    
    Mergesort(a,0,n);
    printf("Sorted array using recursion: ");
    for(int i=0;i<n;i++){
        printf("%d, ",a[i]);
    }
    int b[]={10,27,2,4,8,34};
    IMergeSort(b,n);
    printf("\nSorted array without using recursion: ");
    for(int i=0;i<n;i++){
        printf("%d, ",b[i]);
    }
    printf("\n");
    return 0;
}