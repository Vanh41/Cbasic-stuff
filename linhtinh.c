#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

// a:n x m , xuất phát từ ô 1,1 tìm tổng đường đi lớn nhất, chỉ đc đi sang phải hoặc xuống dưới




int n,m;
int a[1000][1000]={0};
int DP[1000][1000]={0};


int max(int x,int y){
    if (x>y) return x;
    return y;
}

void print(){
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++) printf("%d ",DP[i][j]);
        printf("\n");
    }
}

int main(){
    scanf("%d %d",&n,&m);
    // input
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    // base case:
     print();
    // dp
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
     DP[i][j]=max(DP[i][j-1],DP[i-1][j]) + a[i][j];
   // print();
    printf("%d",DP[m][n]);
}