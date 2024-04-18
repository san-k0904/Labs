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
NODE Insucc(NODE p){
    while (p && p->lchild){
        p=p->lchild;
    }
    return p;
}
NODE Inpre(NODE p){
    while(p && p->rchild){
        p=p->rchild;
    }
    return p;
}
NODE delete(NODE root,int key){
    if (root==NULL){
        return NULL;
    }
    if(root->lchild==NULL && root->rchild==NULL){
        root=NULL;
        free(root);
        return NULL;
    }
    if(key<root->data){
        root->lchild=delete(root->lchild,key);
    }
    else if(key>root->data){
        root->rchild=delete(root->rchild,key);
    }
    else{
        NODE q;
        if(NodeHeight(root->lchild)>NodeHeight(root->rchild)){
            q=Inpre(root->lchild);
            root->data=q->data;
            root->lchild=delete(root->lchild,q->data);
        }
        else{
            q=Insucc(root->rchild);
            root->data=q->data;
            root->rchild=delete(root->rchild,q->data);
        }
    }
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
int main(){
    int ch,key,deletekey;
    NODE root=(NODE)malloc(sizeof(struct node));
    root=NULL;
    printf("What do you want to do?:\n");
    printf("1.Insert,2.display,3.Delete,-1.Exit\n");
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
            printf("Enter item to delete: ");
            scanf("%d",&deletekey);
            delete(root,deletekey);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}