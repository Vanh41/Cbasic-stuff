#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int a[100001]={0};



void quicksort(int b[],int l,int r){
    
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main () {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    printArray(a,n);
    quicksort(a,0,n-1);
    printArray(a,n);
}