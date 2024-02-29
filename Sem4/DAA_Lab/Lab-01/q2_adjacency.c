#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node* NODE;

void AdjacencyMatrix(int** adjacency_matrix,int vertex1,int vertex2,int val){
    adjacency_matrix[vertex1][vertex2]=adjacency_matrix[vertex2][vertex1]=val;
}
void AdjacencyList(NODE* adjaceny_list,int vertex1,int vertex2){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=vertex2;
    temp->next=NULL;
    if(adjaceny_list[vertex1]->next==NULL)
        adjaceny_list[vertex1]->next=temp;
    else{
        NODE cur=adjaceny_list[vertex1];
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
    }
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = vertex1;
    temp->next = NULL;
    if(adjaceny_list[vertex2]->next==NULL)
        adjaceny_list[vertex2]->next=temp;
    else{
        NODE cur=adjaceny_list[vertex2];
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
    }
}
void Adjacency(int** adjacency_matrix,NODE* adjacency_list,int n){
    char ch;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            printf("Is vertex %d connected to vertex %d(y/n): ",i,j);
            scanf(" %c",&ch);
            if(ch=='y'){
                AdjacencyMatrix(adjacency_matrix,i,j,1);
                AdjacencyList(adjacency_list,i,j);
            }
            else{
                AdjacencyMatrix(adjacency_matrix,i,j,0);
            }
        }

    }
}

void print_adjacency(int** adjacency_matrix,NODE* adjacency_list,int n){
    printf("Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nAdjacency List:\n");
    NODE cur=(NODE)malloc(sizeof(struct node));
    for(int i=0;i<n;i++){
        cur=adjacency_list[i];
        while(cur!=NULL){
            printf("%d->",cur->data);
            cur=cur->next;
        }
        printf("\n");
    }
    free(cur);
    printf("\n");
}
int main(){
    int n;
    printf("Enter the no. of vertices in the graph: ");

    scanf("%d",&n);
    int** adjaceny_matrix=(int**)malloc(n*(sizeof(int*)));
    for(int i=0;i<n;i++){
        adjaceny_matrix[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        adjaceny_matrix[i][i]=0;
    }
    NODE* adjaceny_list=(NODE*)malloc(n*sizeof(NODE));
    for(int i=0;i<n;i++){
        adjaceny_list[i]=(NODE)malloc(sizeof(struct node));
        adjaceny_list[i]->data=i;
        adjaceny_list[i]->next=NULL;
    }
    Adjacency(adjaceny_matrix,adjaceny_list,n);
    print_adjacency(adjaceny_matrix,adjaceny_list,n);
    return 0;
}