#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int UCLN(int a,int b){
	while (a!=b){
		if (a>b) a=a-b;
		if (a<b) b=b-a;
	}
	return a;
}
int BCNN(int a,int b){
	return a*b/UCLN(a,b);
}

int main(){
 int a,b;
 scanf("%d %d",&a,&b);
 printf("%d",UCLN(a,b));
}
