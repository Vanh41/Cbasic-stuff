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

node *mroot;

node *makenode(int u){
	node *newn=(node*)malloc(sizeof(node));
	newn->id=u;
	newn->leftchild=NULL;
	newn->rightchild=NULL;
	return newn;
}

node *find(node *r,int v){
	if (r==NULL) return NULL;
	if (r->id==v) return r;
	node *p=r->leftchild;
	node *q=r->rightchild;
	while(p!=NULL) p=find(p,v);
	if (p!=NULL) return p;
	while(q!=NULL) q=find(q,v);
	if (q!=NULL) return q;
	return NULL;
}

void addleft(int u,int v){
	node *temp=makenode(u);
	node *p=find(mroot,v);
	if (p==NULL) return;
	if (p->leftchild==NULL) {
		p->leftchild=temp;
		return;
	}
}

void addright(int u,int v){
	node *temp=makenode(u);
	node *p=find(mroot,v);
	if (p==NULL) return;
	if (p->rightchild==NULL) {
		p->rightchild=temp;
		return;
	}
}

void preorder(node *r){
	if (r==NULL) return;
	printf("%d ",r->id);
	preorder(r->leftchild);
	preorder(r->rightchild);
}







int main(){
  char command[1000];
  while (1){
	scanf("%s",command);
	if (strcmp(command,"MakeRoot")==0) {
		int u;
		scanf("%d",&u);
		mroot=makenode(u);
	}
	if (strcmp(command,"AddLeft")==0) {
		int u,v;
		scanf("%d %d",&u,&v);
		addleft(u,v);
	}
	if (strcmp(command,"AddRight")==0) {
		int u,v;
		scanf("%d %d",&u,&v);
		addright(u,v);
	}
	if (strcmp(command,"PreOrder")==0) {
		preorder(mroot);
	}
	if (strcmp(command,"*")==0) break;
  }
}
