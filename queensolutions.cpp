#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#define N 9
int n;
void print(int **grid){
	for (int i=0;i<n;i++){
	 for (int j=0;j<n;j++)
	 printf("%d",grid[i][j]);
	 printf("\n");
     }
     printf("\n");
}
int checkrowcolumn(int **grid,int i,int j){
	for (int k=0;k<n;k++) if (grid[i][k]==1&&k!=j) return 0;
	for (int k=0;k<n;k++) if (grid[k][j]==1&&k!=i) return 0;
	return 1;
}
int checkdiagonal(int **grid,int i,int j){
	int x,y;
	x=i;
	y=j;
	while (x<n&&y<n){
	  if (grid[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x++;
	  y++;
	}
	x=i;
	y=j;
	while (x>=0&&y>=0){
	  if (grid[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x--;
	  y--;
	}
	x=i;
	y=j;
	while (x>=0&&y<n){
	  if (grid[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x--;
	  y++;
	}
	x=i;
	y=j;
	while (x<n&&y>=0){
	  if (grid[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x++;
	  y--;
	}
	return 1;
}
int checkqueen(int **grid,int i,int j){
	if (checkrowcolumn(grid,i,j)==0||checkdiagonal(grid,i,j)==0) return 0;
	return 1;
}
int count_1(int **grid){
	int tmp=0;
	for (int i=0;i<n;i++)
	 for (int j=0;j<n;j++)
	  if (grid[i][j]==1) tmp++;
	return tmp;
}

int temp=0;
int dem1;
int count;
void backtrack(int **grid,int x){

    for (int i=x;i<n;i++)
     for (int j=0;j<n;j++)
     {
     	if(checkqueen(grid,i,j)==1&&grid[i][j]!=1){
     		grid[i][j]=1;
     		temp++;
     		if (count_1(grid)==n) {
			 count++;
			}
     		backtrack(grid,i+1);
     		grid[i][j]=0;
     		temp--;
		 }
	 }
}



int main()
{  
    scanf("%d",&n);
    int **grid;
    grid=(int**)malloc(n*sizeof(int*));
    for (int i=0;i<n;i++) 
     grid[i]=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
	 for (int j=0;j<n;j++) {
	  scanf("%d",&grid[i][j]);
	  if (grid[i][j]==1) dem1++;
}

     backtrack(grid,0);
     printf("%d",count);
}
