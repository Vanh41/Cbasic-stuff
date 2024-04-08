#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int n;
int grid[1000][1000];
int count=0;
int markR[1000]={0};
int markD1[1000]={0};
int markD2[1000]={0};
int x[1000]={0};
bool check(int i,int j){
	if (markR[i]==0&&markD1[n+j-i-1]==0&&markD2[i+j]==0) return true;
	return false;
}
void Try(int k){
	if (x[k]>0){
		if (k==n-1) count++;
		else Try(k+1);
		return;
	}
	for (int i=0;i<n;i++){
		if (check(i,k)==true){
		 	x[k]=i;
		 	markR[i]=1;
		 	markD1[n+k-i-1]=1;
		 	markD2[k+i]=1;
		 	if (k==n-1) count++;
		 	else Try(k+1);
		 	markR[i]=0;
		 	markD1[n+k-i-1]=0;
		 	markD2[k+i]=0;
		 x[k]=0;
		}
	}
}



int main(){
	scanf("%d",&n);
  for (int i=0;i<n;i++)
   for (int j=0;j<n;j++){
    scanf("%d",&grid[i][j]);
    if (grid[i][j]>0){
    	markR[i]=1;
		markD1[n+j-i-1]=1;
		markD2[i+j]=1;
		 x[j]=1;
	}
 } 
   
  Try(0);
  printf("%d",count);
}
