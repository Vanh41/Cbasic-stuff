#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>


int n;
int a[100000];
bool ok=true;
// 11
// 10 5 2 3 8 7 9 20 15 18 40
// build from preorder
// out put postorder

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node;

node *root;

node *makenode(int k){
    node *p=(node*)malloc(sizeof(node));
    p->key=k;
    p->left=NULL;
    p->right=NULL;
    return p;
}

node *buildbst(int L,int R){
    if (L>R) return NULL;
    node *r=makenode(a[L]);
    int i=L+1;
    while (i<=R&&a[i]<a[L]) i++;
    i--;
    for (int j=i+1;j<=R;j++)
    if (a[j]<a[L]){
        ok=false;
        return NULL;
    }
    r->left=buildbst(L+1,i);
    r->right=buildbst(i+1,R);
    return r;
}

void postorder(node *r){
    if (r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->key);
}


int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    root=buildbst(0,n-1);
    if (ok==false) printf("NULL");
    else postorder(root);
}
