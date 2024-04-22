#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int count=0;

struct list{
  int coefficient;
  int exponent;
  struct list *next;
};
typedef struct list node;

node *poly[10000];
node *head[10000];
node *cur;

node *makenewnode(int coef,int ex){
  node *new =(node*)malloc(sizeof(node));
  new->coefficient=coef;
  new->exponent=ex;
  new->next=NULL;
  return new;
}

void addterm(int id,int coef,int ex){
   node *news=makenewnode(coef,ex);
   node *find=head[id];
   node *prev=NULL;
   if (head[id]==NULL){
    head[id]=news;
   }
   else if (head[id]->exponent<ex){
    news->next=head[id];
    head[id]=news;
   }
   else{
    while (find->next!=NULL&&find->exponent>ex){
      prev=find;
      find=find->next;
    }
    if (find->next!=NULL&&find->exponent==ex)
    find->coefficient+=coef;
    else{
      news->next=find->next;
      find->next=news;
    }
   }
}

void print(int id){
  node *tmp=head[id];
  while (tmp!=NULL) {
    printf("%d%d ",tmp->coefficient,tmp->exponent);
    tmp=tmp->next;
  }
}



int main(){
  char command[1000];
  while(1){
    scanf("%s",command);
    if (strcmp(command,"*")==0) break;
    if (strcmp(command,"hello")==0) printf("hi");
    if (strcmp(command,"AddTerm")==0) 
     {
      int x,y,z;
      scanf("%d %d %d",&x,&y,&z);
      addterm(x,y,z);
     }
    if (strcmp(command,"PrintPoly")==0){
      int x;
      scanf("%d",&x);
      print(x);
    }
  }
}
