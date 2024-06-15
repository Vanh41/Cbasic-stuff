#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct node{
    char key[1000];
    struct node *left;
    struct node *right;
}node;

node *T[1000];

node *makenode(char k[]){
    node *p=(node*)malloc(sizeof(node));
    strcpy(p->key,k);
    p->left=NULL;
    p->right=NULL;
    return p;
}

int hash(char k[]){
    int code=0;
    for (int i=1;i<=strlen(k);i++) code=(code*256+k[i-1])%1000;
    return code;
}

node *findbst(node *r,char k[]){
    if (r==NULL) return NULL;
    if (strcmp(r->key,k)==0) return r;
    if (strcmp(r->key,k)<0) return findbst(r->right,k);
    else return findbst(r->left,k);
}

int find(char k[]){
    int i=hash(k);
    node *p=findbst(T[i],k);
    if (p==NULL) return 0;
    return 1;
}

node *insertbst(node *r,char k[]){
    if (r==NULL) return makenode(k);
    if (strcmp(r->key,k)<0) return r->right=insertbst(r->right,k);
    else r->left=insertbst(r->left,k);
    return r;
}

int insert(char k[]){
    int i=hash(k);
    if (findbst(T[i],k)!=NULL) return 0;
    T[i]=insertbst(T[i],k);
    return 1;
}


int main(){
    char key[1000];
    while (1){
        scanf("%s",key);
        if (strcmp(key,"*")==0) break;
        insert(key);
    }
    char cmd[1000];
    while (1){
        scanf("%s",cmd);
        if (strcmp(cmd,"***")==0) break;
        else if (strcmp(cmd,"insert")==0){
            char k[1000];
            scanf("%s",k);
            printf("%d\n",insert(k));
        }
        else if (strcmp(cmd,"find")==0){
            char k[1000];
            scanf("%s",k);
            printf("%d\n",find(k));
        }
    }
    
}
