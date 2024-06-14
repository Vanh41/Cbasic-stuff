#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int DP[1000];
int n;
int m;
int a[10000]={0};

int min(int x,int y){
    if (x>y) return y;
    return x;
}


int main(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    // base case
    for (int i=0;i<=m;i++) DP[i]=9999;
    DP[0]=0;
    //qhd
    for (int i=0;i<=m;i++)
        for (int j=1;j<=n;j++){
            if (i-a[j]>=0) DP[i]=min(DP[i-a[j]]+1,DP[i]);
        }
    //for (int i=0;i<=m;i++) printf("%d",DP[i]);
    if (DP[m]==9999) printf("-1");
    else printf("%d",DP[m]);
}
