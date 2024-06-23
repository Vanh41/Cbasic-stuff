#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n,k;
int D[1000][1000];

int C(int k,int n){
    if (k==0||k==n) D[k][n]=1;
    else 
        if (D[k][n]==0) D[k][n]=(C(k-1,n-1)+C(k,n-1))%(1000000000+7);
    return D[k][n];
}



int main(){
    scanf("%d %d",&k,&n);
    for (int i =0; i<=n;i++){
        for (int j=0;j<=n;j++){
            D[i][j]= 0;
        }
    }
    printf("%d",C(k,n));
}