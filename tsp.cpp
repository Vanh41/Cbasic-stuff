#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int n;
int min=999999;
int c[100][100];
int x[100];
int f=0;
int visited[100]={0};
void Try(int k){
	for (int i=2;i<=n;i++)
	if (visited[i]==0){
		x[k]=i;
		visited[i]=1;
		f+=c[x[k-1]][x[k]];
		if (k==n){
			f+=c[x[n]][x[1]];
			if (f<min) min=f;
			f-=c[x[n]][x[1]];
		}
		else Try(k+1);
		f-=c[x[k-1]][x[k]];
		visited[i]=0;
	}
}


int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
   for (int j=1;j<=n;j++) scanf("%d",&c[i][j]);
   x[1]=1;
   Try(2);
   printf("%d",min);
}
