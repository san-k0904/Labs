#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int* arr,int n){
    int x,temp;
    int j;
    for(int i=1;i<n;i++){
        x=arr[i];
        j=i-1;
        while(j!=-1&&arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }

}
int main(){
    int arr[]={2,3,1,7,8,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}