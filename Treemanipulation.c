#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct tree{
    int id;
    struct tree *leftmostchild;
    struct tree *rightsibling;
    struct tree *parent;
};
typedef struct tree node;

node *makenode(int id){
    node *new=(node*)malloc(sizeof(node));
    new->id=id;
    new->leftmostchild=NULL;
    new->rightsibling=NULL;
    new->parent=NULL;
    return new;
}

node *find(node *r,int u){
    if (r==NULL) return NULL;
    if (r->id==u) return r;
    node *p=r->leftmostchild;
    while (p!=NULL){
        node *q=find(p,u);
        if (q!=NULL) return q;
        p=p->rightsibling; 
    }
    return NULL;
}

void insert(node *r,int u,int v){
    node *p=find(r,v);
    if (p==NULL) return;
    node *q=makenode(u);
    if (p->leftmostchild==NULL){
        p->leftmostchild=q;
        q->parent=p;
        return;
    }
    node *h=p->leftmostchild;
    while (h->rightsibling!=NULL) h=h->rightsibling;
    h->rightsibling=q;
    q->parent=p;
}



int main(){
    printf("hello world");
}