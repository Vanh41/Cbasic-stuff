#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

#define N 1000001

int n;
int a[N];

void insertionsort(){
    for (int i=1;i<=n-1;i++){
    int pos=i-1;
    while (pos>=0&&a[pos]>a[i]) pos--;
    int temp=a[i];
    for (int j=i-1;j>=pos+1;j--){
    a[j+1]=a[j];
    }
    a[pos+1]=temp;
    }
}

int main () {
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    insertionsort();
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    
    return 0;
}