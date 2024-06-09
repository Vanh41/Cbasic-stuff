#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct bintree{
    int key;
    struct bintree *leftchild;
    struct bintree *rightchild;
};
typedef struct bintree node;

node *makenode(int k){
    node *p=(node*)malloc(sizeof(node));
    p->key=k;
    p->leftchild=NULL;
    p->rightchild=NULL;
    return p;
}

node *find(node *r,int k){
    if (r==NULL) return NULL;
    if (r->key==k) return r;
    if (k>r->key) return find(r->rightchild,k);
    else return find(r->leftchild,k);
}




int main(){

}
