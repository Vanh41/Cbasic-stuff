#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int k;
int n;
int a[10000];

int cmp(const void *ptr1, const void *ptr2){
    int *x=(int*)ptr1;
    int *y=(int*)ptr2;
    return *x-*y;
}

int binsearch(int l,int r){
    if (l>r) return -1;
    if (l==r){
        if (a[l]==k) return l;
        else return -1;
    }
    int m=(l+r)/2;
    if (a[m]==k) return m;
    if (a[m]<k) return binsearch(m+1,r);
    else return binsearch(l,m-1);
}


int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    printf("%d",binsearch(0,n-1));
}
