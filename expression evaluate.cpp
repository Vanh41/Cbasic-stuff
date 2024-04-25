#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct stack1{
	int element;
	struct stack1 *next;
};
typedef struct stack1 nodevalue;

struct stack2{
	char element;
	struct stack2 *next;
};
typedef struct stack2 nodeoperator;

// id 1:value
// id 2:operator

char s[1000];

nodevalue *top1=NULL;
nodeoperator *top2=NULL;
 

bool isemptyval(){
	if (top1==NULL) return true;
	return false;
}

bool isemptyop(){
    if (top2==NULL) return true;
	return false;
}

// dealing w/ val

nodevalue *makenodeval(int a){
	nodevalue *new=(nodevalue*)malloc(sizeof(nodevalue));
	new->element=a;
	new->next=NULL;
	return new;
}

void pushval(int a){
	nodevalue *tmp=makenodeval(a);
	if (isemptyval()==true) {
		top1=tmp;
		return;
	}
	tmp->next=top1;
	top1=tmp;
}

int popvalue(){
	if (isemptyval()==true) return 0;
	int x=top1->element;
	top1=top1->next;
	return x;
}

// dealing w/ op

nodeoperator *makenodeop(char a){
	nodeoperator *new=(nodeoperator*)malloc(sizeof(nodeoperator));
	new->element=a;
	new->next=NULL;
	return new;
}

void pushop(char a){
	nodeoperator *tmp=makenodeop(a);
	if (isemptyop()==true) {
		top2=tmp;
		return;
	}
	tmp->next=top2;
	top2=tmp;
}

char popop(){
	if (isemptyop()==false){
	char x=top1->element;
	top1=top1->next;
	return x;
	}
	return ' ';
}


int presedence(char operator){
	if (operator=='+') return 1;
	if (operator=='*') return 2;
	return 0;
}

bool checkdigit(char a){
	if (0<=a-'0'&&a-'0'<=9) return true;
	return false;
}

int compute(int a,int b, char op){
	if (op=='+') return a+b;
	if (op=='*') return a*b;
	return 0;
}
// 82*((45+(58))+91)*((11*59*21)+91)*35*57*25




int main(){
	scanf("%s",s);
	printf("%s",s);
}
