#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int k;
int n;
unsigned long long a[100000],b[100000];

int cmp(const void *ptr1, const void *ptr2){
    unsigned long long *x=(unsigned long long*)ptr1;
    unsigned long long *y=(unsigned long long*)ptr2;
    return *x-*y;
}

unsigned long long binsearch(int l,int r,int k){
    if (l>r) return -1;
    if (l==r){
        if (a[l]==k) return l;
        else return -1;
    }
    int m=(l+r)/2;
    if (a[m]==k) return m;
    if (a[m]<k) return binsearch(m+1,r,k);
    else return binsearch(l,m-1,k);
}

typedef struct query{
    int ans;
    struct query *next;
}node;
node *head,*tail;

node *makenode(int k){
    node *p=(node*)malloc(sizeof(node));
    p->ans=k;
    p->next=NULL;
    return p;
}

void push(int k){
    node *p=makenode(k);
    if (head==NULL&&tail==NULL) {
        head=tail=p;
        return;
    }
    tail->next=p;
    tail=tail->next;
}

void print(){
    node *temp=head;
    while (temp!=NULL) {
        printf("%d\n",temp->ans);
        temp=temp->next;
    }
}



int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    qsort(a,n,sizeof(unsigned long long),cmp);
    char cmd[1000];
    head=tail=NULL;
    while (1){
        scanf("%s",cmd);
        if (strcmp(cmd,"check")==0) {
            int k;
            scanf("%d",&k);
            int x=binsearch(0,n-1,k);
            if (x==-1) push(0);
            else push(1);
        }
        if (strcmp(cmd,"#")==0) break;
    }
    print();
}
