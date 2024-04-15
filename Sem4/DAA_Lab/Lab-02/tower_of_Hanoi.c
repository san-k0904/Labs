#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void TOH(int n, int src,int aux,int dest){
    if(n>0){
        TOH(n-1,src,dest,aux);
        opcount++;
        printf("Move disk from %d tower to %d tower\n",src,dest);
        TOH(n-1,aux,src,dest);
        opcount++;
    }
}
int main(){
    int n;
    printf("Enter no. of disks: ");
    scanf("%d",&n);
    TOH(n,1,2,3);
    printf("OpCount: %d\n",opcount);
}