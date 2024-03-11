#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
//NOT FINISHED
int pos=0;
int check(char a[]){
	int i=1;
	if (a[0]=='*'||a[0]=='+') return 0;
	while(a[i]!='\0'){
		if ((a[i]=='*'||a[i]=='+')&&(a[i-1]=='*'||a[i-1]=='+'))
		return 0;
		i++;
	}
	return 1;
}
int computemul(char a[],int n){
	int ans=a[n-1]-'0';
	for (int i=n;i<strlen(a);i++){
		if (a[i]='*') continue;
	  ans=ans*(a[i]-'0');
	  i++;
	  if (a[i]=='+') {
	  	pos=i;
	  break;
}
	}
	return ans;
}
int computesum(char a[],int n){
	int ans=a[n-1]-'0';
	for (int i=n;i<strlen(a);i++){
		 if (a[i+1]=='*') {
	  	pos=i;
	  	break;
	}
		if (a[i]='+') continue;
	  ans=ans+(a[i]-'0');
	  i++;
	return ans;
}


int compute(char a[]){
	int i=0;
	int ans=0;
	char tmp;
	while(a[i]!='\0'){
		if (a[i]=='*'){
			ans=ans+computemul(a,i);
			i=pos;
		}
		if (a[i]=='+')
		 {
		 	ans=ans+computesum(a,i)
		 	i=pos;
		 }
		 i++
	}
	return ans;
}

int main(){
	char a[15000];
	int i=0;
	scanf("%s",a);
	printf("%d",check(a));
	if (check(a)==0) printf("NOT_CORRECT");
	else printf("%d",compute(a));
}
