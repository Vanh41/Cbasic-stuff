#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int a[10000]={0};
int check[10000]={0};

void print(){
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}

void Try(int k){
    for (int i=1;i<=n;i++){
        if (check[i]==0) {
            a[k]=i;
            check[i]=1;
        }
        else continue;
        if (k==n) print();
        else Try(k+1);
        check[i]=0;
    }
}



int main(){
    scanf("%d",&n);
    Try(1);
}
