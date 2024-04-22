#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct stack{
	int element;
	struct stack *next;
};
typedef struct stack node;



node *makenode(int x){
	node *newn=(node*)malloc(sizeof(node));
	newn->element=x;
	newn->next=NULL;
	return newn;
}

node *top;

bool isempty(){
	if (top==NULL) return true;
	return false;
}

void initstack(){
	top=NULL;
}

void push(int k){
	node *tmp=makenode(k);
	tmp->next=top;
	top=tmp;
}

int pop(){
	if (top==NULL) return NULL;
	int x=top->element;
	node *p=top;
	top=top->next;
	free(p);
	return x; 
}


void display(){
	node *temp=top;
	if (temp==NULL) return;
	while (temp->next!=NULL){
		printf("%d\n",temp->element);
		temp=temp->next;
	}
}
int a[1000];
int count=0;

int main(){
	initstack();
	char command[1000];node *top;
top=NULL;
	while(1){
		scanf("%s",command);
		if (strcmp(command,"#")==0) break;
		if (strcmp(command,"PUSH")==0){
			int k;
			scanf("%d",&k);
			push(k);
		}
		if (strcmp(command,"POP")==0){
			if (isempty()==true) a[count++]=-100;
			else
		 	a[count++]=pop();
		}
	//	display();
	}
	for (int i=0;i<count;i++) {
	if  (a[i]==-100) printf("NULL\n");
	else
	printf("%d\n",a[i]);
}
}
