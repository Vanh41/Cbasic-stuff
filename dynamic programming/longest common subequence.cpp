#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>

char a[1000];
char b[1000]; 
int mem[1000][1000];
//memset(mem,-1,sizeof(mem));
int max(int x,int y ){
	if (x>y) return x;
	return y;
}

int lcs(int i,int j){
	if (i==-1||j==-1) return 0;
	if (mem[i][j]!=0) return mem[i][j];
	int res;
	if (a[i]==b[j]) {
		res=1+lcs(i-1,j-1);
	}
	else 
	res=max(lcs(i,j-1),lcs(i-1,j));
 mem[i][j]=res;
 return res;
}


int main(){
	scanf("%s",a);
	scanf("%s",b);
	printf("%d",lcs(strlen(a)-1,strlen(b)-1));
}
