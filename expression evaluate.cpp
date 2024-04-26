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
	char x=top2->element;
	top2=top2->next;
	return x;
	}
	return ' ';
}

// discard right parenthesis
void pop(){
	if (top2==NULL) return ;
	top2=top2->next;
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

int evaluate(){
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='(') pushop(s[i]);
		else if (checkdigit(s[i])==true){
			int val=0;
			while(i<strlen(s) && checkdigit(s[i])==true) {
				val=val*10+s[i]-'0';
				i++;
			}
			pushval(val);
			i--;
		}
		else if (s[i]==')'){
			 while (top2->element!='('&&isemptyop()==false){
				char op=popop();
				int a=popvalue();
				int b=popvalue();
				int c=compute(a,b,op);
				pushval(c);
			 }
			 if (isemptyop()==false) pop();
		}
		else{
			while(isemptyop()==false && presedence(top2->element)>=presedence(s[i])){
				int a=popvalue();
				int b=popvalue();
				char op = popop();
				int c=compute(a,b,op);
				pushval(c);
			}
			pushop(s[i]);
		}
	}
	while (isemptyop()==false){
		int a=popvalue();
		int b=popvalue();
		char op=popop();
		int c=compute(a,b,op);
		pushval(c);
	}
	if (isemptyval()==false) return top1->element;
	return 0;
}



int main(){
	scanf("%s",s);
	printf("%d",evaluate());
	return 0;
}


/*
idea:
1. While there are still tokens to be read in,
   1.1 Get the next token.
   1.2 If the token is:
       1.2.1 A number: push it onto the value stack.
       1.2.2 A variable: get its value, and push onto the value stack.
       1.2.3 A left parenthesis: push it onto the operator stack.
       1.2.4 A right parenthesis:
         1 While the thing on top of the operator stack is not a 
           left parenthesis,
             1 Pop the operator from the operator stack.
             2 Pop the value stack twice, getting two operands.
             3 Apply the operator to the operands, in the correct order.
             4 Push the result onto the value stack.
         2 Pop the left parenthesis from the operator stack, and discard it.
       1.2.5 An operator (call it thisOp):
         1 While the operator stack is not empty, and the top thing on the
           operator stack has the same or greater precedence as thisOp,
           1 Pop the operator from the operator stack.
           2 Pop the value stack twice, getting two operands.
           3 Apply the operator to the operands, in the correct order.
           4 Push the result onto the value stack.
         2 Push thisOp onto the operator stack.
2. While the operator stack is not empty,
    1 Pop the operator from the operator stack.
    2 Pop the value stack twice, getting two operands.
    3 Apply the operator to the operands, in the correct order.
    4 Push the result onto the value stack.
3. At this point the operator stack should be empty, and the value
   stack should have only one value in it, which is the final result.
*/
