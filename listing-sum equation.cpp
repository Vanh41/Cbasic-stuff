#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>

int n,k,m;
int ans[100]={0};
int mark[100]={0};
int value[100]={0};
int sum=0;
int count=0;
void backtrack(int a){
    int i;
    for (i=1;i<=n;i++)
        if (mark[value[i]]==0){
            ans[a]=value[i];
            mark[value[i]]=1;
            sum=sum+value[i];
    if (a==k&&sum==m) {
        //for (int j=1;j<=k;j++) printf("%d ", ans[j]);
        //printf("\n");
        /*
        for (int j=1;j<k;j++) if (ans[j]>ans[j+1]) {
            mark[i]=0;
            sum-=value[i];
            return;
        }
        count++;*/
         for (int j=1;j<=k;j++) printf("%d ", ans[j]);
         printf("\n");
    }
    else backtrack(a+1);
    mark[i]=0;
    sum-=value[i];
    }
}

int main(){
  scanf("%d %d %d",&n,&k,&m);
  for (int i=1;i<=n;i++) scanf("%d",&value[i]);
  backtrack(1);
  //printf("%d",count);

}
