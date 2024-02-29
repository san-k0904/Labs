#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int push=0;
int pop=0;
void dfs_stack(int** adj_matrix,int u,int* visited,int n,int* pushorder, int* poporder){
    int stack[n+1];
    int top=-1;
    printf("%d, ",u);
    visited[u]=1;
    stack[++top]=u;
    pushorder[push++]=u;
    int found;
    int current;
    int i;
    while(top!=-1){
        found=0;
        current=stack[top];
        for(i=0;i<n;i++){
            if(adj_matrix[current][i]==1 && visited[i]==0){
                found=1;
                break;
            }
        }
        if(found){
            stack[++top]=i;
            visited[i]=1;
            pushorder[push++]=i;
            printf("%d, ", i); // Print the pushed vertex
        }
        else{
            poporder[pop++]=stack[top--];
        }
    }
}
int main(){
    int n;
    printf("Enter the no. of vertices in the graph: ");
    scanf("%d",&n);
    int visited_dfs[n];
    int check=0;
    memset(visited_dfs,0,sizeof(visited_dfs));
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
    printf("The DFS of the graph is: ");
    for (int i = 0; i < n; i++) {
        if (!visited_dfs[i]) {
            dfs_stack(adjaceny_matrix,i,visited_dfs,n,pushorder,poporder);
        }
    }
    printf("\npush order: ");
    for(int i=0;i<n;i++){
        printf("%d, ",pushorder[i]);
    }
    printf("\ntopological order: ");
    for(int i=n-1;i>=0;i--){
        printf("%d, ",poporder[i]);
    }
    printf("\n");
    return 0;
}