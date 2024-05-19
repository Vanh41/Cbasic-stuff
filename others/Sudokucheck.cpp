#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
int checkrow(int a[]){
	int count[10];
	for (int i=0;i<10;i++) count[i]=0;
	for (int i=0;i<9;i++)
	count[a[i]]++;
	for (int i=1;i<=9;i++)
	if (count[i]!=1) return 0;
	return 1;
}
int checkcolumn(int a[9][9],int n){
	int count[10];
	for (int i=0;i<10;i++) count[i]=0;
	for (int i=0;i<9;i++)
	count[a[i][n]]++;
	for (int i=1;i<=9;i++)
	if (count[i]!=1) return 0;
	return 1;
}

int checksubsquare(int a[9][9],int n,int m){
	int count[10];
	for (int i=0;i<10;i++) count[i]=0;
	for (int i=n;i<n+3;i++)
	 for (int j=m;j<m+3;j++)
	  	count[a[i][j]]++;
	for (int i=1;i<=9;i++)
	if (count[i]!=1) return 0;
	return 1;
}

int checksudoku(int a[9][9]){
	int x,y,z=0;
  for (int i=0;i<9;i++) if (checkrow(a[i])==0) return 0;
  for (int i=0;i<9;i++) if (checkcolumn(a,i)==0) return 0; 	
  for (int i=0;i<9;i=i+3)
   for (int j=0;j<9;j=j+3)
    if (checksubsquare(a,i,j)==0) return 0;
  return 1;
} 



int main(){
	int t;
 scanf("%d",&t);
 int ans[1000];
 int index;
 for (int n=0;n<t;n++){
 	int a[9][9];
 	for (int i=0;i<9;i++) 
 	 for (int j=0;j<9;j++)
 	 scanf("%d",&a[i][j]);	 
 	 ans[index++]=checksudoku(a);
 }  
 for (int i=0;i<index;i++) printf("%d\n",ans[i]);
}
