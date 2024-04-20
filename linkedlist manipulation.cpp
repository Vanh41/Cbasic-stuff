#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list{
    int element;
    struct list *next;
};
typedef struct list node;
node *root,*cur,*prev;

node *makenewnode(int k){
    node *new = (node*)malloc(sizeof(node));
    new->element=k;
    new->next=NULL;
    return new;
}

void addfirst(int k){
    node *new=makenewnode(k);
    new->next=root;
    root=new;
    cur=root;
}

void addlast(int k){
    node *new=makenewnode(k);
    if (root==NULL){
        root=new;
        cur=new;
        prev=NULL;
        return;
    }
    node *p=root;
    while (p->next!=NULL)
    p=p->next;
    p->next=new;
    cur=new;
    prev=p;
}

node *reverse (node *root){
    node *cur,*prev;
    cur =prev=NULL;
    while (root!=NULL){
        cur = root;
        root=root->next;
        cur->next=prev;
        prev=cur;
    }
    return prev;
}

void output(node*p){
    if (p==NULL) {
        printf("NULL pointer error.\n");
        return ;
    }
    int tmp=p->element;
    printf("%d",tmp);
}

int readnode(){
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}


void main(){
    int n; int a;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        a=readnode();
        root=makenewnode(a);
    }
    char command[1000];
    getchar();
    while (strcmp(command,"#")!=0){
        scanf("%s",command);
        if (strcmp(command,"#")==0) break;
        if (strcmp(command,"addlast")==0) {
            int k;
            scanf("%d",&k);
            addlast(k);
        }
        if (strcmp(command,"addfirst")==0) {
            int k;
            scanf("%d",&k);
            addfirst(k);
        }
    }
}
