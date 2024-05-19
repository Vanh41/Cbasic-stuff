#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
int ans[1000];
int count=0;
void binary(int n){
	if (n==0) ans[count++]=0;
	else{
	ans[count++]=n%2;
	binary(n/2);
}
}

int main(){
 int n;
 scanf("%d",&n);
 binary(n);
 for (int i=count-2;i>=0;i--) printf("%d",ans[i]);
}
