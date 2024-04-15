#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int n,k,m;
int ans[1000]={0};
int value[1000]={0};
int dp[1000][1000]; // number of ways to select k elements from the given sequence a such that their sum equals m

int main(){
  scanf("%d %d %d",&n,&k,&m);
  for (int i=0;i<n;i++) {
    scanf("%d",&value[i]);
  }
   for (int i=0;i<=k;i++)
    for (int j=0;j<=m;j++)
	 dp[i][j]=0;
	dp[0][0]=1; //base case
	for (int i=1;i<=n;i++)
	 for (int j=m;j>=value[i-1];j--)
	  for (int count=1;count<=k;count++)
	   dp[count][j]+=dp[count-1][j-value[i-1]]; 
	printf("%d",dp[k][m]);
}
