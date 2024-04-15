#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void AdjacencyMatrix(int** adjacency_matrix,int vertex1,int vertex2,int val){
    adjacency_matrix[vertex1][vertex2]=adjacency_matrix[vertex2][vertex1]=val;
}
void Adjacency(int** adjacency_matrix,int n){
    char ch;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            printf("Is vertex %d connected to vertex %d(y/n): ",i,j);
            scanf(" %c",&ch);
            if(ch=='y'){
                AdjacencyMatrix(adjacency_matrix,i,j,1);
            }
            else{
                AdjacencyMatrix(adjacency_matrix,i,j,0);
            }
        }

    }
}
void dfs(int** adj_matrix,int u,int* visited,int n ){
    if(visited[u]==0){
        printf("%d, ",u);
        visited[u]=1;
    }
    for(int i=0;i<n;i++){
        if(adj_matrix[u][i]==1&& visited[i]==0){
            dfs(adj_matrix,i,visited,n);
        }
    }
}
void dfs_stack(int** adj_matrix,int u,int* visited,int n,int* pushorder, int* poporder){
    int stack[n+1];
    int top=-1;
    printf("%d, ",u);
    visited[u]=1;
    int push=0;
    int pop=0;
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
        }
        else{
            poporder[pop++]=stack[top--];
        }
    }
}
void bfs(int** adj_matrix,int u, int* visited, int n){
    int queue[n];
    int front=0;
    int rear=-1;
    int next;
    printf("%d, ",u);
    visited[u]=1;
    queue[++rear]=u;
    while(front<=rear){
        next=queue[front++];
        for(int i=0;i<n;i++){
            if(adj_matrix[next][i]==1 && visited[i]==0){
                printf("%d, ",i);
                visited[i]=1;
                queue[++rear]=i;
            }
        }
    }


}
int main(){
    int n;
    printf("Enter the no. of vertices in the graph: ");
    scanf("%d",&n);
    int visited_dfs[n];
    memset(visited_dfs,0,sizeof(visited_dfs));
    int visited_bfs[n];
    memset(visited_bfs,0,sizeof(visited_bfs));
    int** adjaceny_matrix=(int**)malloc(n*(sizeof(int*)));
    for(int i=0;i<n;i++){
        adjaceny_matrix[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        adjaceny_matrix[i][i]=0;
    }
    int pushorder[n];
    int poporder[n];
    Adjacency(adjaceny_matrix,n);
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
    printf("\npop order: ");
    for(int i=0;i<n;i++){
        printf("%d, ",poporder[i]);
    }
    printf("\n");
    printf("The BFS of the graph is: ");
    for (int i = 0; i < n; i++) {
        if (!visited_bfs[i]) {
            bfs(adjaceny_matrix,i,visited_bfs,n);
        }
    }
    printf("\n");
    return 0;
}