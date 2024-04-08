#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int grid[9][9];
int markR[100][100], markC[100][100],markS[100][100][100];
bool check(int i,int j,int k){
   if (markR[i][k]==0&&markC[j][k]==0&&markS[i/3][j/3][k]==0) return true;
   return false;
}
void print(){
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++) printf("%d ",grid[i][j]);
		printf("\n");
	}
	printf("\n");
}
int count=0;
void Try(int i,int j){
	if (grid[i][j]>0) {
		if (i==8&&j==8) count++;
	else {
		if (j==8) Try(i+1,0);
		else Try(i,j+1);
	} 
	return;
	}
	for (int k=1;k<=9;k++){
		if (check(i,j,k)){
			grid[i][j]=k;
			markR[i][k]=1; markC[j][k]=1; markS[i/3][j/3][k]=1;
			if (i==8&&j==8) count++;
			else {
				if (j==8) Try(i+1,0);
		     	else Try(i,j+1);
			}
		grid[i][j]=0;
		markR[i][k]=0; markC[j][k]=0; markS[i/3][j/3][k]=0;	
		}
	}
}


int main(){
  for (int i=0;i<9;i++)
   for (int j=0;j<9;j++){
    scanf("%d",&grid[i][j]);
    if (grid[i][j]>0) 	markR[i][grid[i][j]]=1; markC[j][grid[i][j]]=1; markS[i/3][j/3][grid[i][j]]=1;
}
  Try(0,0);
  printf("%d",count);
}
