#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct node{
	int id;
	struct node* leftmostchild;
	struct node* rightsibling;
	struct node* parent;
}node;
node *root1;

node *makenode(int u){
	node *p=(node*)malloc(sizeof(node));
	p->id=u;
	p->	leftmostchild=NULL;
	p->rightsibling=NULL;
	p->parent=NULL;
	return p;
}

node *find(node *root,int u){
	if (root==NULL) return NULL;
	if (root->id==u) return root;
	node *p=root->leftmostchild;
	while (p!=NULL){
		node *q=find(p,u);
		if (q!=NULL) return q;
		p=p->rightsibling;
	}
	return NULL;
}
//Insert a new node with the identifier (id) u as the leftmost child of the node with the identifier (id) v in the tree
void insert(node *root,int u,int v){
	node *p=find(root,v);
	if (p==NULL) return;
	node *q=makenode(u);
	if (p->leftmostchild==NULL){
		p->leftmostchild=q;
		q->parent=p;
		return;
	}
	node *h=p->leftmostchild;
	while (h->rightsibling!=NULL){
		h=h->rightsibling;
	}
	h->rightsibling=q;
	q->parent=p;	
}

// print tu root->leaves
void preorder(node *root){
	if (root==NULL) return;
	printf("%d ",root->id);
	node *p=root->leftmostchild;
	while (p!=NULL){
		preorder(p);
		p=p->rightsibling;	
	}
}

// print tu leaves-> root
void postorder(node *root){
	if (root==NULL) return;
	node *p=root->leftmostchild;
	while (p!=NULL) {
		postorder(p);
		p=p->rightsibling;
	}
	printf("%d ",root->id);
}




void freeTree(node *r){
	if (r==NULL) return;
	node *p=r->leftmostchild;
	while (p!=NULL){
		node *np=p->rightsibling;
		freeTree(p);
		p=np;
	}
	free(r);
}


int main(){
	char command[100];
	int ans[10000];
	int count=0;
	while (1){
		scanf("%s",command);
		if (strcmp(command,"*")==0) break;
		else
		if (strcmp(command,"MakeRoot")==0) {
			int u;
			scanf("%d",&u);
			root1=makenode(u);
		}
		else
		if (strcmp(command,"Insert")==0) {
			int u;
			int v;
			scanf("%d %d",&u,&v);
			insert(root1,u,v);
		}
		else
		if (strcmp(command,"PreOrder")==0) {
			preorder(root1);
		}
		else
		if (strcmp(command,"PostOrder")==0) {
			postorder(root1);
		}
 }
 //for (int i=0;i<count;i++) printf("%d\n",ans[i]);
}
		

