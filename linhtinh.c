#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int a[10000];
int n;
int m;
int x[10000];
int T=0;
int count;

void print(){
    for (int i=1;i<=n;i++) printf("%d",a[i]);
    printf("\n");
}

bool check(){
    for (int i=1;i<n;i++) 
        if (a[i]==a[i+1]&&a[i]==1) return false;
        return true;
}

void Try(int k){
    for (int v=0;v<=1;v++){
        a[k]=v;
        if (k==n){
            if (check()==true) print();
        }
        else Try(k+1);
    }    
}

int main(){
    scanf("%d",&n);
    Try(1);
}