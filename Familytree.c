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
node *nodes[100000];

node *makenode(char name[100]){
    node *p=(node*)malloc(sizeof(node));
    strcpy(p->name,name);
    p->leftmostchild=NULL;
    p->rightsibling=NULL;
    p->parent=NULL;
    return p;
}

node *findnode(char name[100]){
    for (int i=0;i<100000;i++)
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
    int ans[10000];
    int tmp=0;
   	while (1){
        char name1[100];
        scanf("%s",name1);
        if (strcmp(name1,"***")!=0){
            char name2[100];
            scanf("%s",name2);
            nodes[count++]=makenode(name1);
            nodes[count++]=makenode(name2);
            addchild(findnode(name1),findnode(name2));
        }
        else {
            char command[100];
            while(1){
                scanf("%s",command);
                if (strcmp(command,"descendants")==0){
                    char name3[100];
                    scanf("%s",name3);
                    ans[tmp++]=countnodes(findnode(name3));
                }
                if (strcmp(command,"generation")==0){
                    char name3[100];
                    scanf("%s",name3);
                    ans[tmp++]=height(findnode(name3));
                }
                if (strcmp(command,"***")==0){
                    break;
                }
            }
            if (strcmp(command,"***")==0) break;
        }
    }
    for (int i=0;i<tmp;i++) printf("%d\n",ans[i]);
}
