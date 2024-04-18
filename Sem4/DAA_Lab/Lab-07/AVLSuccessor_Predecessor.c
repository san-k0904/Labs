#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* lchild;                   
    int data;
    struct node* rchild;
    int height;
};
typedef struct node* NODE;

int NodeHeight(NODE p){
    int hl,hr;
    hl=p&& p->lchild?p->lchild->height:0;
    hr=p&& p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}
int BalancedFactor(NODE p){
    int hl,hr;
    hl=p&& p->lchild?p->lchild->height:0;
    hr=p&& p->rchild?p->rchild->height:0;
    return hl-hr;
}
NODE LLRotation(NODE p){
    NODE pl=p->lchild;
    NODE plr=p->rchild;//if any node attached to the pl element
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    return pl;

}
NODE LRRotation(NODE p){
    NODE pl=p->lchild;
    NODE plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->rchild=p;
    plr->lchild=pl;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);
    return plr;
}
NODE RRRotation(NODE p){
    NODE pr=p->rchild;
    NODE prl=p->lchild;//if any node attached to the pr element
    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    return pr;
}
NODE RLRotation(NODE p){
    NODE pr=p->rchild;
    NODE prl=pr->lchild;
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->rchild=pr;
    prl->lchild=p;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);
    return prl;
}
NODE insert(NODE root,int key){
    if(root==NULL){
        NODE temp=(NODE)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        temp->data=key;
        temp->lchild=temp->rchild=NULL;
        temp->height=1;
        return temp;
    }
    if(key>root->data){
        root->rchild=insert(root->rchild,key);
    }
    else if(key<root->data){
        root->lchild=insert(root->lchild,key);
    }
    //update height for nodes
    root->height=NodeHeight(root);
    
    if(BalancedFactor(root)==2 && BalancedFactor(root->lchild)==1)
        return LLRotation(root);
    else if(BalancedFactor(root)==2 && BalancedFactor(root->lchild)==-1)
        return LRRotation(root);
    else if(BalancedFactor(root)==-2 && BalancedFactor(root->rchild)==-1)
        return RRRotation(root);
    else if(BalancedFactor(root)==-2 && BalancedFactor(root->rchild)==1)
        return RLRotation(root);

    return root;
}
void Inorder(NODE root){
    if(root==NULL){
        return;
    }
    Inorder(root->lchild);
    printf("%d\t",root->data);
    Inorder(root->rchild);

}
void Preorder(NODE root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    Preorder(root->lchild);
    Preorder(root->rchild);

}
int InorderSucc(NODE root, int key){
    if (root == NULL){
        return -1; // No nodes in the tree, so no successor
    }
    NODE current = root; // Start from the root node
    NODE successor = NULL; // Initialize successor to NULL
    while (current != NULL){
        if (current->data < key){
            current = current->rchild; // Move to the right child
        }
        else if (current->data > key){
            successor = current; // Update successor
            current = current->lchild; // Move to the left child
        }
        else{
            if (current->rchild != NULL){
                successor = current->rchild; // Find the leftmost node in the right subtree
                while (successor->lchild != NULL){
                    successor = successor->lchild;
                }
            }
            break;
        }
    }
    if (successor != NULL){
        return successor->data; // Return the successor's data if found
    }
    else{
        return -1; // No successor found
    }
}
int main(){
    int ch,key,suc,suckey;
    NODE root=(NODE)malloc(sizeof(struct node));
    root=NULL;
    printf("What do you want to do?:\n");
    printf("1.Insert,2.display,3. successor,4.Predecessor-1.Exit\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d",&key);
            fflush(stdin);
            root=insert(root,key);
            break;
        case 2:
            Preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter key for successor: ");
            scanf("%d",&suckey);
            suc=InorderSucc(root,suckey);
            printf("The successor is: %d\n",suc);
            break;
        case -1:
            exit(0);
            break;
        }
    }
    return 0;
}