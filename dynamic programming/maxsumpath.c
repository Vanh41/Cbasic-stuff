#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

// a:m x n , xuất phát từ ô nào đó cột 1, tìm tổng đường đi lớn nhất, chỉ đc đi (i,j+1),(i-1,j+1),(i+1,j);
// 5 7
// 9 -2 6 2 1 3 4
// 0 -1 6 7 1 3 3
// 8 -2 8 2 5 3 2
// 1 -1 6 2 1 6 1
// 7 -2 6 2 1 3 7
// output : 41 ( 9 -1 8 7 5 6 7)



int n,m;
int a[1000][1000]={0};
int DP[1000][1000]={0};


int max(int x,int y){
    if (x>y) return x;
    return y;
}

void print(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) printf("%d ",DP[i][j]);
        printf("\n");
    }
}

int main(){
    scanf("%d %d",&n,&m);
    // set up DP
    for (int i=0;i<=n+1;i++)
     for (int j=0;j<=m+1;j++) a[i][j]=-90000;
    for (int i=0;i<=n+1;i++)
     for (int j=0;j<=m+1;j++) DP[i][j]=-90000;
    //input
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    // base case:

    for (int i=1;i<=n;i++) DP[i][1]=a[i][1];
    // print();
    // dp
     for (int j=2;j<=m;j++){

      for (int i=1;i<=n;i++){
      DP[i][j]=max(DP[i][j-1],max(DP[i-1][j-1],DP[i+1][j-1]))+a[i][j];
      }
   
    }
    int maxf=-9999;
    for (int i=1;i<=n;i++) if (maxf<DP[i][m]) maxf=DP[i][m];
    printf("%d",maxf);
}