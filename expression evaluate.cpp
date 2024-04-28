#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct stack1{
	long long element;
	struct stack1 *next;
};
typedef struct stack1 nodevalue;

struct stack2{
	char element;
	struct stack2 *next;
};
typedef struct stack2 nodeoperator;

char s[50000];

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

nodevalue *makenodeval(long long a){
	nodevalue *new=(nodevalue*)malloc(sizeof(nodevalue));
	new->element=a;
	new->next=NULL;
	return new;
}

void pushval(long long a){
	nodevalue *tmp=makenodeval(a);
	if (isemptyval()==true) {
		top1=tmp;
		return;
	}
	tmp->next=top1;
	top1=tmp;
}

long long popvalue(){
	if (isemptyval()==true) return 0;
	long long x=top1->element;
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
	return 'n';
}

// discard right parenthesis
void pop(){
	if (top2==NULL) return ;
	top2=top2->next;
}


long long presedence(char operator){
	if (operator=='+') return 1;
	if (operator=='*') return 2;
	return 0;
}

bool checkdigit(char a){
	if (0<=a-'0'&&a-'0'<=9) return true;
	return false;
}

long long compute(long long a,long long b, char op){
	if (op=='+') return (a+b)%(1000000000+7);
	if (op=='*') return (a*b)%(1000000000+7);
	return 0;
}
// 82*((45+(58))+91)*((11*59*21)+91)*35*57*25

long long evaluate(){
	for (long long i=0;i<strlen(s);i++){
		if(s[i] == ' ') continue;
		else if (s[i]=='(') pushop(s[i]);
		else if (checkdigit(s[i])==true){
			long long val=0;
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
				long long a=popvalue();
				long long b=popvalue();
				long long c=compute(a,b,op);
				pushval(c);
			 }
			 if (isemptyop()==false) pop();
		}
		else{
			while(isemptyop()==false && presedence(top2->element)>=presedence(s[i])){
				long long a=popvalue();
				long long b=popvalue();
				char op = popop();
				long long c=compute(a,b,op);
				pushval(c);
			}
			pushop(s[i]);
		}
	}
	while (isemptyop()==false){
		long long a=popvalue();
		long long b=popvalue();
		char op=popop();
		long long c=compute(a,b,op);
		pushval(c);
	}
	if (isemptyval()==false) return top1->element;
	return 0;
}



int main(){
	scanf("%[^\n]s",s);
	if (evaluate()==0) printf("NOT_CORRECT");
	else
	printf("%lld",evaluate()%(1000000000+7));
	return 0;
}


//idea:
/*
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

