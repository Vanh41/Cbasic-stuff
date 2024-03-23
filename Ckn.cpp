#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int D[10000][01000]; 
int C(int n,int k){
    if ((k==0||k==n)) D[n][k]=1;
    else 
        if (D[n][k] ==0) D[n][k] = (C(n-1,k-1)+C(n-1,k))%(1000000000+7);
    return D[n][k];
}

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    for (int i =0; i<=n;i++){
        for (int j=0;j<=n;j++){
            D[i][j]= 0;
        }
    }
    printf("%d",C(n,k));
}
