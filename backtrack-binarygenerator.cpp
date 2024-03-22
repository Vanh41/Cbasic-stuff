#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>


int n;
int ans[1000];
void backtrack(int a){
  for (int i=0;i<=1;i++){
  	ans[a]=i;
  	if (a==n) {
	  for (int j=1;j<=n;j++) printf("%d",ans[j]);
	  printf("\n");             
  }
  else backtrack(a+1);
}
}
int main(){
  scanf("%d",&n);
  backtrack(1);
}
