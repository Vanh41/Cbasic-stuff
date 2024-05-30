#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

#define N 1000001

int n;
int a[N];

int max(int a, int b) {
    return a>b?a:b;
}

int main () {
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; i++) scanf("%d", &a[i]);
    int maximum = a[1]*a[1]*a[1], maxSum = maximum;
    for(i = 2; i <= n; i++){
        int cube = a[i]*a[i]*a[i];
        maxSum = max(cube, cube + maxSum);
        if(maxSum > maximum) maximum = maxSum;
    }
    printf("%d", maximum);
    return 0;
}