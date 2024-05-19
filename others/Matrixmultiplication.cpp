#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n][m];
	for (int i=0;i<n;i++)
	 for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	int k,l;
	scanf("%d %d",&k,&l);
	int b[k][l];
	for (int i=0;i<k;i++)
	 for (int j=0;j<l;j++) scanf("%d",&b[i][j]);
	int c[n][l];
   for (int i=0;i<n;i++){
   
    for  (int j=0;j<l;j++){
	 c[i][j]=0;	 
	 for (int k=0;k<m;k++)
	  c[i][j]+=a[i][k]*b[k][j];
	 printf("%d ",c[i][j]);
}
 printf("\n");
}
}
