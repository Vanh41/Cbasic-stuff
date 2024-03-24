#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
//not finish
int check(int a[9][9],int i,int j,int k){
   for (int x=0;x<9;x++)
	if (a[i][x]==k) return 0;
   for (int x=0;x<9;x++)
	if (a[x][j]==k) return 0;
    int n=i-i%3;
	int m=j-j%3;
	for (int x=0;x<3;x++)
	 for (int y=0;y<3;y++)
	  	if (a[n+x][m+y]==k) return 0;
    return 1;
} 
int checkzero(int a[9][9]){
	for (int i=0;i<9;i++)
	 for (int j=0;j<9;j++)
	  if (a[i][j]==0) return 0;
 return 1;
}

int count=0;
void backtrack(int i,int j,int a[9][9]){
   if (i==8&&j==9){
   	    count++;
		return;
	}
	if (j==9){
		i++;
		j=0;
	}	
	if (a[i][j]!=0)
		backtrack(i,j+1,a);
	for (int k=1;k<=9;k++) 
	{
		if (check(a,i,j,k)==1) 
		{
			a[i][j] = k;	
			backtrack(i,j+1,a);
			//if (checkzero(a)==1) count++;
		}
	 a[i][j] = 0;
	}
	return;
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
