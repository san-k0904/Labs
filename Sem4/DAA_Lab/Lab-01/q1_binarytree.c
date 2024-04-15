#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* lchild;
    struct node* rchild;

};
typedef struct node* NODE;
NODE insert_bst(NODE root, int value){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=value;
    temp->rchild=temp->lchild=NULL;
    if(root==NULL)
        return temp;
    else{
        NODE prev=NULL;
        NODE cur=root;
        if(value>cur->data){
            prev=cur;
            cur=cur->rchild;
        }
        else {
            prev=cur;
            cur=cur->lchild;
        }
        if(cur=NULL){
            if(value>prev->data)
                prev->rchild=temp;
            else
                prev->lchild=temp;
        }
    }
    return root;
}
int Search(NODE root, int key){
    if(root->data==key){
        return 1;
    }
    else{
        if(root!=NULL)
        {
            if(key>root->data){
            return Search(root->rchild,key);
            }
            else{
                return Search(root->lchild,key);
            }
        }
    }
    return -1;
}
int main(){
    NODE root= (NODE)malloc(sizeof(struct node));
    root=NULL;
    int choice,value,flag,key;
    printf("What do you wish to do : 1. Insert, 2. Search , -1. Exit\n");
    do{
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                root=insert_bst(root,value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d",&key);
                flag=Search(root,key);
                if(flag==1){
                    printf("Element found.\n");
                }
                else
                    printf("Element not found.\n");
                break;
        }
    }while(choice!=-1);
    return 0;
}