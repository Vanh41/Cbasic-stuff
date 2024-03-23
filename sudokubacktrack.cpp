#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
//not finish
int checkrow(int a[9][9],int i,int k){
	for (int j=0;j<9;j++)
	if (a[i][j]==k) return 0;
	return 1;
}
int checkcolumn(int a[9][9],int j,int k){
	for (int i=0;i<9;i++)
	if (a[i][j]==k) return 0;
	return 1;
}

int checksubsquare(int a[9][9],int n,int m,int k){
	n=(n/3)*3;
	m=(m/3)*3;
	for (int i=n;i<n+3;i++)
	 for (int j=m;j<m+3;j++)
	  	if (a[i][j]==k) return 0;
	return 1;
}

int checkzero(int a[9][9]){
 for (int i=0;i<9;i++)
  for (int j=0;j<9;j++) 
   if (a[i][j]==0) return 0;
 return 1;
} 

int count=0;
int backtrack(int i,int j,int a[9][9]){
  	if (a[i][j]==0){
  	 for (int k=1;k<=9;k++) 
  	 if (checkrow(a,i,k)==1&&checkcolumn(a,j,k)==1&&checksubsquare(a,i,j,k)==1) a[i][j]=k;
  	if (i==8&&j==8&&checkzero(a)==1) {
	  count++;
    }
  else {
  	if (i<9) backtrack(i+1,j,a);
  	if (j<9)backtrack(i,j+1,a);
  	if (i<9&&j<9)backtrack(i+1,j+1,a);
  }
 // a[i][j]=0;
}
}



int main(){
	int a[9][9];
	for (int i=0;i<9;i++)
	 for (int j=0;j<9;j++) 
	  scanf("%d",&a[i][j]);
	  
	
   backtrack(0,0,a);
for (int i=0;i<9;i++){
	 for (int j=0;j<9;j++) 
	  printf("%d ",a[i][j]);
	  printf("\n");
}
   printf("%d",count);
}
