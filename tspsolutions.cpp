#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int n;int m;
int c[1000][1000];
int visited[1000]={0};
int x[1000]={0};
int f=0;
int count=0;
void Try(int k){
	for (int i=2;i<=n;i++)
	 {
	 	if (visited[i]==0){
	 		visited[i]=1;
	 		x[k]=i;
	 		f=f+c[x[k-1]][x[k]];
	 		if (k==n) {
	 		f=f+c[x[k]][1];	
	 		if (f<=m) count++;
	 		f=f-c[x[k]][1];	
		 	}
		 	else {
			 if (f<=m) Try(k+1);
	     	}
		 	visited[i]=0;
	 		f=f-c[x[k-1]][x[k]];
		 
		}
	 }
}
int main(){
  scanf("%d %d",&n,&m);
  for (int i=1;i<=n;i++)
   for (int j=1;j<=n;j++) scanf("%d",&c[i][j]);
 x[1]=1;
 Try(2);
 printf("%d",count);
}
