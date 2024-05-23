#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int a[1000]={0};
int check[1000]={0};
int ans[1000]={0};
int mark[1000]={0};

void display(int k){
    for (int i=1;i<=k;i++) printf("%d ",ans[i]);
    printf("\n");
}


void Try(int k){
    for (int i=k;i<=n;i++){
        if (check[a[i]]<mark[a[i]]&&a[i]>=ans[k-1]){
            ans[k]=a[i];
            check[a[i]]++;
            display(k);
            Try(k+1);
            check[a[i]]--;
        }
    }
}


int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
     for (int j=1;j<=n;j++)
      if (a[i]<a[j]){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    for (int i=1;i<=n;i++) mark[a[i]]++;
    Try(1);
}