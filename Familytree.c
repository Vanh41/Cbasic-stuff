#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct tree{
    char name[101];
    struct tree *leftmostchild;
    struct tree *rightsibling;
    struct tree *parent;
};
typedef struct tree node;

node *root;
node *nodes[1000];

node *makenode(char name[100]){
    node *p=(node*)malloc(sizeof(node));
    strcpy(p->name,name);
    p->leftmostchild=NULL;
    p->rightsibling=NULL;
    p->parent=NULL;
    return p;
}

node *findnode(char name[100]){
    for (int i=0;i<=100;i++)
     if (strcmp(nodes[i]->name,name)==0) return nodes[i];
    return NULL;
}

void addchild(node *child,node *parent){
	child->parent=parent;
	if (parent->leftmostchild==NULL) parent->leftmostchild=child;
	else{
		node *p=parent->leftmostchild;
		while(p->rightsibling!=NULL) p=p->rightsibling;
		p->rightsibling=child;
	}
}

int max(int x,int y){
	if (x>y) return x;
	return y;
}

int countnodes(node *nod){
	if (nod==NULL) return 0;
	node *p=nod->leftmostchild;
	int count=1;
	while (p!=NULL){
		count+=countnodes(p);
		p=p->rightsibling;
	}
	return count;
}

int height(node *nod){
	if (nod==NULL) return 0;
	int maxh=0;
	node *p=nod->leftmostchild;
	while (p!=NULL){
		int h=height(p);
		if (h>maxh) maxh=h;
		p=p->rightsibling;
	}
	return maxh;
}

//descendants <name>: return number of descendants of the given <name>
//generation <name>: return the number of generations of the descendants of the given <name>



int main(){
	int count=0;
	node *child[100];
	node *parent[100];
   while (1){
   	scanf("%s",child[count]->name);
   	if (strcmp(child[count]->name,"***")!=0){
   	 	scanf("%s",parent[count]->name);
   	 	addchild(child[count],parent[count]);
   	 	count++;
		}
	else {
		char command[100];
		while(1){
		scanf("%s",command);
		
		if (strcmp(command,"descendants")==0) {
			char name[100];
			scanf("%s",name);
			int p=countnodes(findnode(name));
			printf("%d\n",p);
		}
		else
		if (strcmp(command,"generation")==0) {
			char name[100];
			scanf("%s",name);
			int p=height(findnode(name));
			printf("%d\n",p);
		}
		else
		if (strcmp(command,"***")==0) break;	
		}
	}
	if (strcmp(child[count]->name,"***")==0) break;
	}  
}
