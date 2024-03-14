#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int checkrowcolumn(int **a,int i,int j,int n){
	for (int k=0;k<n;k++) if (a[i][k]==1) return 0;
	for (int k=0;k<n;k++) if (a[k][i]==1) return 0;
	return 1;
}



int main(){
	int t;
 scanf("%d",&t);
 int ans[1000];
 int index;
 for (int n=0;n<t;n++){
 	int k;
 	scanf("%d",&k);
  int a[k][k];
 	for (int i=0;i<k;i++) 
 	 for (int j=0;j<k;j++)
 	 scanf("%d",&a[i][j]);
/*	  for (int i=0;i<k;i++) 
 	 for (int j=0;j<k;j++)
 	 if (a[i][j]==1) printf("%d\n",checkrowcolumn(a,i,j,k));*/		 
 }  
 
}
