#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int k;
int n;
unsigned long long a[100000],b[100000];

int cmp(const void *ptr1, const void *ptr2){
    unsigned long long *x=(unsigned long long*)ptr1;
    unsigned long long *y=(unsigned long long*)ptr2;
    return *x-*y;
}

unsigned long long binsearch(int l,int r,int k){
    if (l>r) return -1;
    if (l==r){
        if (a[l]==k) return l;
        else return -1;
    }
    int m=(l+r)/2;
    if (a[m]==k) return m;
    if (a[m]<k) return binsearch(m+1,r,k);
    else return binsearch(l,m-1,k);
}




int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    qsort(a,n,sizeof(unsigned long long),cmp);
    int x;
    for (int i=0;i<n;i++){
        x=binsearch(0,i-1,b[i]);
        if (x==-1) printf("0\n");
        else printf("1\n");
    }
}
