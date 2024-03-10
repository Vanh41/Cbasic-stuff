#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
//NOT FINISHED

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
int compute(char a[]){
	int i=0;
	int pos=0;
	int ans=0;
	char tmp;
	while(a[i]!='\0'){
		if (a[i]=='*')
		strncpy(tmp,)
	}
}

int main(){
	char a[15000];
	int i=0;
	scanf("%s",a);
	printf("%d",check(a));
}
