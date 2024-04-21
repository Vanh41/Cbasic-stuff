#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct list{
  int element;
  struct list *next;
};
typedef struct list node;

node *head,*cur,*temp,*prev;

node *makenewnode(int k){
  node *new =(node*)malloc(sizeof(node));
  new->element=k;
  new->next=NULL;
  return new;
}

void printsolution(){
    node *tmp;
    tmp=head;
    while(tmp != NULL){
        printf("%d ", tmp->element);
        tmp=tmp->next;
    }
}

void addfirst(int k){
    node *new=makenewnode(k);
    new->next=head;
    head=new;
    cur=head;
}

void addlast(int k){
    node *new=makenewnode(k);
    if (head==NULL){
        head=new;
        cur=new;
        prev=NULL;
        return;
    }
    node *p=head;
    while (p->next!=NULL)
    p=p->next;
    p->next=new;
    cur=new;
    prev=p;
}

void remove(int k){
  node *find;
  find=temp=head;
  if (find->next==NULL) free(find);
  else
  while (find->next!=NULL){
    if (find->element==k){
      temp=find;
      find=find->next;
      free(temp);
    }
    else find=find->next;
  }
}





int main(){ 
 int n;
//  khoi tao
 scanf("%d",&n);
 for (int i=0;i<n;i++){
  int k;
  scanf("%d",&k);
  if (head==NULL) temp=head=makenewnode(k);
  else {
    addfirst(k);
  }
 }  
//  command
char command[1000];
 
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

        if (strcmp(command,"remove")==0) {
            int k;
            scanf("%d",&k);
            remove(k);
        }

        
    }
 printsolution();
}
