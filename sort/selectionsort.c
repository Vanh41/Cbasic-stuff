#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

#define N 1000001

int n;
int a[N];

int min;


void selectionsort(){
    for (int k=0;k<=n-2;k++){
    min=a[k];
    int index=k;
    for (int i=k+1;i<=n-1;i++){
        if (a[i]<min) {
            min=a[i];
            index=i;
        }
    int temp=a[k];
    a[k]=a[index];
    a[index]=temp;
    }
 }
}

int main () {
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    selectionsort();
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}