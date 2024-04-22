#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct stack{
	char element;
	struct stack *next;
};
typedef struct stack node;

char s[1000];

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


void display(){
	node *temp=top;
	if (temp==NULL) return;
	while (temp->next!=NULL){
		printf("%c\n",temp->element);
		temp=temp->next;
	}
}

void push(char k){
	node *tmp=makenode(k);
	if (top==NULL) {
		top=tmp;
		return;
	}
	tmp->next=top;
	top=tmp;
}

void pop(){
	if (top==NULL) return;
	char x=top->element;
	node *p=top;
	top=top->next;
	free(p);
	return; 
}
bool match(char a,char b){
	if ((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}')) return true;
	return false;
}

bool check(){
	for (int i=0;i<strlen(s);i++)  {
		if (s[i]=='('||s[i]=='{'||s[i]=='[') {
		push(s[i]);
	}
		else if (match(top->element,s[i])==true) pop();
		else return false; 
	}
   if (isempty()==true) return true;
   return false;
}



int main(){
	initstack();
	scanf("%s",s);
    if (check()==true) printf("1");
    else printf("0");
}
