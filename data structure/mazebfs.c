#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include<stdbool.h>

int n,m,r,c;
int a[1000][1000];
int visited[1000][1000];
int sizelist=0;

struct queue {
    int row,col;
    int step;
    struct queue *next;
    struct queue *parent;
};
typedef struct queue node;

node *head,*tail;
node *listnode[1000];
node *finalnode;

node *makenode(int row,int col,int step,node *parent){
    node *p=(node*)malloc(sizeof(node));
    p->col=col;
    p->row=row;
    p->step=step;
    p->next=NULL;
    p->parent=parent;
    return p;
}

void initQueue(){
    head = NULL; 
    tail = NULL;
}

bool isempty(){
	if (head==NULL&&tail==NULL) return true;
	return false;
}

void push(node *p){
    if (isempty()==true) {
        head=p;
        tail=p;
    }
    else {
        tail->next=p;
        tail=p;
    }
}

node *pop(){
    if (isempty()==true) return NULL;
    node* temp=head;
    head=head->next;
    if (head==NULL) tail=NULL;
    return temp;
}

bool legal(int i,int j){
    if (a[i][j]==0&&visited[i][j]==0) return true;
    return false;
}

bool target(int i,int j){
    if (i>n||j>m||i<1||j<1) return true;
    return false;
}

void addlist(node *p){
    listnode[sizelist++] = p;
}

const int dr[4] = {1,-1,0,0};
const int dc[4] = {0,0,1,-1};



int main(){

    scanf("%d %d %d %d",&n,&m,&r,&c);
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);

    initQueue();
    node* startnode = makenode(r,c,0,NULL);
    addlist(startnode);
    push(startnode);
    visited[r][c]=1;
    while (isempty()!=true){
        node *p=pop();
        for (int k=0;k<4;k++){
            int nr=p->row+dr[k];
            int nc=p->col+dc[k]; 
            if (legal(nr,nc)==true){
                visited[nr][nc]=1;
                node *new=makenode(nr,nc,p->step+1,p);
                if (target(nr,nc)==true) {
                    finalnode=new;
                    break;
                }
                else
                push(new);
            }
        }
        if(finalnode!= NULL) break;
    }
    if(finalnode!= NULL) printf("%d",finalnode->step);
    else printf("-1");
}
