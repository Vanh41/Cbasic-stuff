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
  printf("\n");
}

void addpoly(int id1,int id2,int id3){
  node *temp1=head[id1];
  node *temp2=head[id2];
  //head[id3]=NULL; 
  if (temp1->exponent>temp2->exponent){
    head[id3]=makenewnode(head[id1]->coefficient,head[id1]->exponent);
    temp1=temp1->next;
  }
  else if (temp1->exponent<temp2->exponent){
    head[id3]=makenewnode(head[id2]->coefficient,head[id2]->exponent);
    temp2=temp2->next;
  }
  else {
    head[id3]=makenewnode(head[id1]->coefficient+head[id2]->coefficient,head[id1]->exponent);
    temp1=temp1->next;
    temp2=temp2->next;
  }
  //node *pol=head[id3];
  while (temp1!=NULL&&temp2!=NULL){
    if (temp1->exponent>temp2->exponent){
        addterm(id3,temp1->coefficient,temp1->exponent);
        temp1=temp1->next;
    }
    else if (temp1->exponent<temp2->exponent){
      addterm(id3,temp2->coefficient,temp2->exponent);
      temp2=temp2->next;
    }
    else if (temp1->exponent==temp2->exponent){
      addterm(id3,temp2->coefficient+temp1->coefficient,temp2->exponent);
      temp2=temp2->next;
      temp1=temp1->next;
    }
  }
  if (temp1!=NULL)
    while(temp1!=NULL) {
      addterm(id3,temp1->coefficient,temp1->exponent);
      temp1=temp1->next;
  }
  if (temp2!=NULL)
    while(temp2!=NULL) {
      addterm(id3,temp2->coefficient,temp2->exponent);
      temp2=temp2->next;
  }

}

int evaluate(int id,int x){
  node *temp=head[id];
  int ans=0;
  while(temp!=NULL){
    ans+=temp->coefficient*pow(x,temp->exponent);
    temp=temp->next;
  }
  return ans;
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
    if (strcmp(command,"AddPoly")==0) 
     {
      int x,y,z;
      scanf("%d %d %d",&x,&y,&z);
      addpoly(x,y,z);
     }
    if (strcmp(command,"EvaluatePoly")==0) 
     {
      int id,x;
      scanf("%d %d",&id,&x);
      printf("%d",evaluate(id,x));
     }
  }
}
