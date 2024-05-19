#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct queue{
	int element;
	struct queue *next;
};
typedef struct queue node;



node *makenode(int x){
	node *newn=(node*)malloc(sizeof(node));
	newn->element=x;
	newn->next=NULL;
	return newn;
}

node *head,*tail;

bool isempty(){
	if (head==NULL&&tail==NULL) return true;
	return false;
}

void initqueue(){
	head=tail=NULL;
}

void push(int k){
	 node *newn=makenode(k);
	if (isempty()==true) {
		head=tail=newn;
		return;
}
   tail->next=newn;
   tail=newn;
}

int pop(){
	if (isempty()==true) return NULL;
	node *tmp=head;
	int v=head->element;
	head=head->next;
	if (head==NULL) tail=NULL;
	free(tmp);
	return v;
}


void display(){
	node *temp=head;
	if (temp==NULL) return;
	while (temp->next!=NULL){
		printf("%d\n",temp->element);
		temp=temp->next;
	}
}

int a[1000];
int count=0;

int main(){
	initqueue();
	char command[1000];
    head=NULL;
	while(1){
		scanf("%s",command);
		if (strcmp(command,"#")==0) break;
		if (strcmp(command,"PUSH")==0){
			int k;
			scanf("%d",&k);
			push(k);
		}
		if (strcmp(command,"POP")==0){
		  if (strcmp(command,"POP")==0){
			if (isempty()==true) a[count++]=-100;
			else
		 	a[count++]=pop();
		}
		}
	}
	for (int i=0;i<count;i++) {
	if  (a[i]==-100) printf("NULL\n");
	else
	printf("%d\n",a[i]);
}
}
