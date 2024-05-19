#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int n;
int m;
int a[100]={0};
int mark[100]={0};
int T=0;
void print(){
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
}

bool check(int v,int k){
	if (k<n) return true;
    else return (T+v==m);
}
void tra(int k){
	for (int i=1;i<=m-T-n+k;i++){
		if (check(i,k)){
		a[k]=i;
		T+=i;
		if (n==k) print();
		else tra(k+1);
		T-=i;
		}
	}
}


int main(){
  scanf("%d %d",&n,&m);
  tra(1);
}
