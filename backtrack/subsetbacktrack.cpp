#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>


int n,m;
int a[10000];
void print(){
	for (int i=1;i<=m;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void backtrack(int k){
	for (int i=a[k-1]+1;i<=n-m+k;i++){
		a[k]=i;
		if (k==m) print();
        else backtrack(k+1);
	}
	
}
int main(){
	scanf("%d %d",&n,&m);
	int count=0;
	//for (int i=1;i<=n;i++) a[count++]=i;
	backtrack(1);
}
