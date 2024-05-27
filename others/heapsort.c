#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int a[],int i,int n){
	int l=2*i;int r=2*i+1;
	int maxidx=i;
	if (l<=n&&a[l]>a[maxidx]) maxidx=l;
	if (r<=n&&a[r]>a[maxidx]) maxidx=r;
	if (maxidx!=i){
		swap(&a[i],&a[maxidx]);
		heapify(a,maxidx,n);
	}
}

void buildheap(int a[],int n){
	for (int i=n/2;i>=1;i--) heapify(a,i,n);
}

void heapsort(int a[],int n){
	buildheap(a,n);
	for (int i=n;i>=2;i--){
		swap(&a[1],&a[i]);
		heapify(a,1,i-1);
	}
}

int main(){
	int n;
	int arr[100000];
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&arr[i]);
	heapsort(arr,n);
	for (int i=1;i<=n;i++) printf("%d ",arr[i]);
}
