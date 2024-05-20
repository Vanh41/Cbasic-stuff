#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct bitree{
	int id;
	struct bitree *leftchild;
	struct bitree *rightchild;
};
typedef struct bitree node;

node *root;

node *makenode(int u){
	node *p=(node*)malloc(sizeof(node));
	p->id=u;
	p->leftchild=NULL;
	p->rightchild=NULL;
	return p;
}


node *find(node *r,int u){
	if (r==NULL) return NULL;
	if (r->id==u) return r;
	node *p=find(r->leftchild,u);
	if (p!=NULL) return p;
	return find(r->rightchild,u);
}

void addleft(int u,int v,node *r){
	node *p=find(r,v);
	if (p==NULL) return ;
	if (p->leftchild!=NULL) return;
	node *q=find(r,u);
	if (q!=NULL) return;
	p->leftchild=makenode(u);
}

void addright(int u,int v,node *r){
	node *p=find(r,v);
	if (p==NULL) return;
	if (p->rightchild!=NULL) return;
	node *q=find(r,u);
	if (q!=NULL) return;
	p->rightchild=makenode(u);
}

void preorder(node *r){
	if (r==NULL) return;
	printf("%d ",r->id);
	preorder(r->leftchild);
	preorder(r->rightchild);
}

void inorder(node *r){
	if (r==NULL) return;
	inorder(r->leftchild);
	printf("%d ",r->id);
	inorder(r->rightchild);
}

void postorder(node *r){
	if (r==NULL) return;
	postorder(r->leftchild);
	postorder(r->rightchild);
	printf("%d ",r->id);
}



int main(){
	char command[100];
	while (1){
		scanf("%s",command);
		if (strcmp(command,"*")==0) break;
		if (strcmp(command,"MakeRoot")==0){
			int u;
			scanf("%d",&u);
			root=makenode(u);
		}
		else
		if (strcmp(command,"AddLeft")==0){
			int u,v;
			scanf("%d %d",&u,&v);
			addleft(u,v,root);
		}
		else
		if (strcmp(command,"AddRight")==0){
			int u,v;
			scanf("%d %d",&u,&v);
			addright(u,v,root);
		}
		else
		if (strcmp(command,"PreOrder")==0){
			preorder(root);
			printf("\n");
		}
		else 
		if (strcmp(command,"InOrder")==0){
			inorder(root);
			printf("\n");
		}
		else
		if (strcmp(command,"PostOrder")==0){
			postorder(root);
			printf("\n");
		}
		
		
	}	
}
