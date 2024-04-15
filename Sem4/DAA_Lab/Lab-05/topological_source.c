#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int columnsum(int i,int** adj_matrix,int n,int* visited){
    int sum=0;
    for(int j=0;j<n;j++){
        if(!visited[j]){
            sum+=adj_matrix[j][i];
        }
    }
    return sum;
}
void source(int** adj_matrix,int n,int* visited){
    for(int i=0;i<n;i++){
        if(!columnsum(i,adj_matrix,n,visited)&& visited[i]==0){
            printf("%d, ",i);
            visited[i]=1;
        }
    }
}
int main(){
    int n;
    printf("Enter the no. of vertices in the graph: ");
    scanf("%d",&n);
    int visited[n];
    int check=0;
    memset(visited,0,sizeof(visited));
    int** adjaceny_matrix=(int**)malloc(n*(sizeof(int*)));
    for(int i=0;i<n;i++){
        adjaceny_matrix[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        adjaceny_matrix[i][i]=0;
    }
    int pushorder[n];
    int poporder[n];
    printf("Enter values:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adjaceny_matrix[i][j]);
        }
    }
    printf("\ntopological order: ");
    for(int i=0;i<n;i++){
        source(adjaceny_matrix,n,visited);
    }
    printf("\n");
    return 0;
}