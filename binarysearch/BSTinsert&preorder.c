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

node *root;

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

node *insert(node *r,int k){
	if (r==NULL) return makenode(k);
	if (r->key==k) return r;
	if (r->key<k) r->rightchild= insert(r->rightchild,k);
	else r->leftchild=insert(r->leftchild,k);
	return r;
}



void preorder(node *r){
	if (r==NULL) return;
	printf("%d ",r->key);
	preorder(r->leftchild);
	preorder(r->rightchild);
}

void postorder(node *r){
	postorder(r->leftchild);
	postorder(r->rightchild);
	printf("%d ",r->key);
}




int main(){
	char cmd[1000];
	while(1){
		scanf("%s",cmd);
		if (strcmp(cmd,"insert")==0){
			int k;
			scanf("%d",&k);
			root=insert(root,k);
		}
		if (strcmp(cmd,"#")==0) break;
	}
	preorder(root);
}
