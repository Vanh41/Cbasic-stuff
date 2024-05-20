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
node *nodes[100000];

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

int addleft(int u,int v){
	if (nodes[u]!=NULL||nodes[v]==NULL) return 0;
	if (nodes[v]->leftchild!=NULL) return 0;
	node *p=makenode(u);
	nodes[v]->leftchild=p;
	nodes[u]=p;
	return 1;
}

int addright(int u,int v){
	if (nodes[u]!=NULL||nodes[v]==NULL) return 0;
	if (nodes[v]->rightchild!=NULL) return 0;
	node *p=makenode(u);
	nodes[v]->rightchild=p;
	nodes[u]=p;
	return 1;
}

int max(int x,int y){
	if (x>y) return x;
	return y;
}

typedef struct TINFO{
	int balanced;
	int hl; //depth of left child
	int hr; //depth of right child
	int h; //depth of the tree
}INFO;

INFO visit(node *r){
	if (r==NULL){
		INFO i;
		i.balanced=1;
		i.h=0;
		return i;
	}
	INFO i1=visit(r->leftchild);
	INFO i2=visit(r->rightchild);
	INFO i;
	i.h=max(i1.h,i2.h)+1;
	if (i1.balanced==0){
		i.balanced=0;
		return i;
	}
	if (i2.balanced==0){
		i.balanced=0;
		return i;
	}
	if (abs(i1.h-i2.h)>=2){
		i.balanced=0;
	}
	else i.balanced=1;
	return i;
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
			nodes[u]=root;
		}
		else
		if (strcmp(command,"AddLeft")==0){
			int u,v;
			scanf("%d %d",&u,&v);
			addleft(u,v);
		}
		else
		if (strcmp(command,"AddRight")==0){
			int u,v;
			scanf("%d %d",&u,&v);
			addright(u,v);
		}
	}
	INFO i=visit(root);
	printf("%d %d",i.balanced,i.h);	
}
