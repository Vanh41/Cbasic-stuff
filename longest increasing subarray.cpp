#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int a[100000]={0};
bool comp[100000]={0};
int Length[100000]={0};

int max(int x,int y){
	if (x>y) return x;
	return y;
}


int main(){
  int n;
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&a[i]);
  int i,j;
  for (i=1;i<=n;i++)
   Length[i]=1;
   for (j=1;j<=i-1;j++){
	if (a[j]<=a[i]&&Length[i]<Length[j]+1) Length[i]=Length[j]+1; 
   }
   printf("%d",Length[n]);
}
