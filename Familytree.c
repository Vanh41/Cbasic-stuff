#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct tree{
    char name[100];
    struct tree *leftmostchild;
    struct tree *rightsibling;
    struct tree *parent;
};
typedef struct tree node;

node *makenode(char name[100]){
    node *new=(node*)malloc(sizeof(node));
    strcpy(new->name,name);
    new->leftmostchild=NULL;
    new->rightsibling=NULL;
    new->parent=NULL;
    return new;
}

node *findnode(char name[100]){
    
}

int main(){
    
}