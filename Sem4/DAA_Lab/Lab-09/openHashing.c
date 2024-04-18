#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* link;
};
typedef struct node* NODE;
NODE orderedLinkedList(NODE first,int key){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=key;
    temp->link=NULL;
    NODE cur;
    NODE prev;
    if(first==NULL){
        return temp;
    }
    cur=first;
    prev=NULL;
    if(key<first->data){
        temp->link=first;
        return first;
    }
    while(cur!=NULL && key>cur->data){
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    temp->link=cur;
    return first;
}
int  hashFunction(int key){
    return key%10;
}
void Insert_Hash(NODE* HashTable,int key){
    int index;
    index=hashFunction(key);
    HashTable[index]=orderedLinkedList(HashTable[index],key);
}
void Search(NODE* HashTable,int key){
    int index=hashFunction(key);
    NODE first=HashTable[index];
    if(first==NULL){
        printf("NO such key\n");
        return;
    }
    NODE cur=first;
    while(cur!=NULL){
        if(cur->data==key){
            printf("Found\n");
            return;
        }
        cur=cur->link;
    }
    if(cur==NULL){
        printf("NOT found");
        return;
    }
}
int main(){
    NODE* HashTable=(NODE*)malloc(10*sizeof(NODE));
    for(int i=0;i<10;i++){
        HashTable[i]=(NODE)malloc(sizeof(struct node));
        HashTable[i]=NULL;
    }
    Insert_Hash(HashTable,12);
    Insert_Hash(HashTable,22);
    Insert_Hash(HashTable,42);
    Search(HashTable,21);
    return 0;

}