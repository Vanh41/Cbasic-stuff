#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int a[1000];
int n;
int check[1000]={0};
int ans[1000];

void display(){
    for (int i=0;i<n;i++) printf("%d ",ans[i]);
    printf("\n");
}

void Try(int k){
    for (int i=0;i<n;i++){
        if (check[a[i]]==0){
            ans[k]=a[i];
            check[a[i]]=1;
            if (k==n-1) display();
            else Try(k+1);
            check[a[i]]=0;
        }
    }
}


int main(){
  scanf("%d",&n);   
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
  Try(0);
}