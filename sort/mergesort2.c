#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int a[100001]={0};
void merge(int b[],int l,int m,int r){
    int temp[100001];
    int i=l;
    int j=m+1;
    int k=0;
    while (i<=m&&j<=r){
        if (b[i]<b[j]) {
            temp[k]=b[i];
            i++;
            k++;
        }
        if (b[i]>b[j]){
            temp[k]=b[j];
            j++;
            k++;
        }
    }
    while (i<=m) {
        temp[k]=b[i];
        k++;
        i++;
    }
    while (j<=r) {
        temp[k]=b[j];
        k++;
        j++;
    }
    int x=0;
    i=l;
    while (x<k&&i<=r){
        b[i]=temp[x];
        i++;
        x++;
    }
}

void mergeSort(int b[],int l,int r){
    if (l<r){
        int m=(l+r)/2;
        mergeSort(b,l,m);
        mergeSort(b,m+1,r);
        merge(b,l,m,r);
    }
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
    mergeSort(a,0,n-1);
    printArray(a,n);
}