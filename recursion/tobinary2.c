#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int ans[100000];
int count=0;
void bin(int k){
    if (k!=0){
        ans[count++]=k%2;
        bin(k/2);
    }
    else return;
}


int main(){
    scanf("%d",&n);
    bin(n);
    for (int i=count-1;i>=0;i--) printf("%d",ans[i]);
}