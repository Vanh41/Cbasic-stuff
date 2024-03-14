#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int checkrowcolumn(int **a,int i,int j,int n){
	for (int k=0;k<n;k++) if (a[i][k]==1&&k!=j) return 0;
	for (int k=0;k<n;k++) if (a[k][j]==1&&k!=i) return 0;
	return 1;
}
int checkdiagonal(int **a,int i,int j,int n){
	int x,y;
	x=i;
	y=j;
	while (x<n&&y<n){
	  if (a[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x++;
	  y++;
	}
	x=i;
	y=j;
	while (x>=0&&y>=0){
	  if (a[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x--;
	  y--;
	}
	x=i;
	y=j;
	while (x>=0&&y<n){
	  if (a[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x--;
	  y++;
	}
	x=i;
	y=j;
	while (x<n&&y>=0){
	  if (a[x][y]==1&&(x!=i&&y!=j)) return 0;
	  x++;
	  y--;
	}
	return 1;
}
int checkqueen(int **a,int n){
	for (int i=0;i<n;i++) 
 	 for (int j=0;j<n;j++) if (a[i][j]==1&&checkrowcolumn(a,i,j,n)==0&&checkdiagonal(a,i,j,n)==0) return 0;
	return 1;
}



int main(){
	int t;
	int i,j;
	int count=0;
 scanf("%d",&t);
 int ans[1000];
 for (i=0;i<t;i++) ans[i]=0;
 int **array;
 for (int n=0;n<t;n++){
 	int k;
 	scanf("%d",&k);
  array = (int**) malloc(k * sizeof(int*));
   for (i = 0; i < k; i++) {
        array[i] = (int*) malloc(k * sizeof(int));
    }
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    
    ans[n]=checkqueen(array,k);
}
for (i=0;i<t;i++) printf("%d\n",ans[i]);
}
