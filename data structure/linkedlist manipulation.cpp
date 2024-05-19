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

bool check(int k){
  node *find=head;
  while (find!=NULL){
    if (find->element==k) return true;
    find=find->next;
  }
  return false;
}

void addfirst(int k){
    if (check(k)==true) return;
    node *new=makenewnode(k);
    new->next=head;
    head=new;
    cur=head;
}

void addlast(int k){
  if (check(k)==true) return;
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

void removed(int k){
  node *find;
  find=temp=prev=head;
  while(find->element==k&&find==head) {
    head=head->next;
    prev=prev->next;
    find=head;
  }
  if (find->next==NULL&&find->element==k) {
    free(find);
    head=NULL;
  }
  while (find->next!=NULL){
    if (find->element==k){
      prev->next=find->next;
      free(find);
      find=prev;
    }
    else {
      if (prev==find) find=find->next;
      else {
        find=find->next;
        prev=prev->next;
      }
      if (find->next==NULL&&find->element==k) prev->next=NULL;
  }
}

}

bool checkavai(int u,int v){
  node *find=head;
  int checku=0;
  int checkv=0;
  if (find->element==v&&find->next==NULL) return true;
  if (find->next==NULL) return false;
  // check if v appear
  while (find->next!=NULL){
    if (find->element==v) {
      checkv=1;
      break;
    }
    else find=find->next;
  }
 find=head;
  // check if u not appear
  while (find->next!=NULL){
    if (find->element==u) {
      checku=1;
      break;
    }
    else find=find->next;
  }
  if (checku==1&&checkv==1) return false;
  if (checku==0&&checkv==1) return true;
  return false;
}

void addafter(int u,int v){
  node *find;
  if (check(u)==true&&check(v)==true) return;
  find=temp=prev=head;
  if (checkavai(u,v)==false) return;
  if (find->next==NULL) addlast(u);
  else
  while (find->next!=NULL){
    if (find->element==v){
      temp=makenewnode(u);
      temp->next=find->next;
      find->next=temp;
      find=find->next;
    }
    else find=find->next;
  }
}


void addbefore(int u,int v){
  node *find;
  if (check(u)==true&&check(v)==true) return;
  find=temp=prev=head;
  if (checkavai(u,v)==false) return;
  if (find==head&&find->element==v) addfirst(u);
  else
  while (find->next!=NULL){
    if (find->element==v){
      temp=makenewnode(u);
      temp->next=prev->next;
      prev->next=temp;
      find=find->next;
    }
    else {
      if (prev==find) find=find->next;
      else {
        prev=prev->next;
        find=find->next;
    }
  }
  }
}

void reverse(){
  temp=prev=NULL;
  while (head!=NULL){
    temp=head;
    head=head->next;
    temp->next=prev;
    prev=temp;
  }
  head=temp;
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
 reverse();
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
            removed(k);
        }

        if (strcmp(command,"addafter")==0) {
            int u,v;
            scanf("%d %d",&u,&v);
            addafter(u,v);
        }
        if (strcmp(command,"addbefore")==0) {
            int u,v;
            scanf("%d %d",&u,&v);
            addbefore(u,v);
        }
        
        if (strcmp(command,"reverse")==0) {
            reverse();
        }
        //printsolution();
    }
 printsolution();
}
