
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#define N 9

int grid[N][N];
bool get_RC(int &row, int &col);

int check(int i,int j,int k){
   for (int x=0;x<9;x++)
	if (grid[i][x]==k) return 0;
   for (int x=0;x<9;x++)
	if (grid[x][j]==k) return 0;
    int n=i-i%3;
	int m=j-j%3;
	for (int x=0;x<3;x++)
	 for (int y=0;y<3;y++)
	  	if (grid[n+x][m+y]==k) return 0;
    return 1;
} 
//int *get_R=(int*)malloc(2*sizeof(int));
bool get_RC(int &row, int &col)
{
    for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
        if (grid[row][col] == 0)
            return true;
    return false;
}

int checkzero(){
	for (int i=0;i<9;i++)
	 for (int j=0;j<9;j++)
	 if (grid[i][j]==0) return 0;
	return 1;
}


int count_Solution(int ans)
{
    int i, j;

    if (get_RC(i, j))
    {
        for (int k=1;k<=9;k++)
        {
            if (check(i,j,k)==1)
            {
                grid[i][j]=k;
                ans = count_Solution(ans);
                    grid[i][j] = 0;
            }
        }
    }
    else
        ans++;
    return ans;
}

int main()
{
    for (int i=0;i<9;i++)
	 for (int j=0;j<9;j++) 
	  scanf("%d",&grid[i][j]);
	int ans = count_Solution(0);
    printf("%d",ans);
}

