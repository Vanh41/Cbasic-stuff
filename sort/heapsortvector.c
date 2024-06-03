#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n,m;
int *a[100001];

int cmp(int i,int j){
	for (int k=1;k<=m;k++)
	 if (a[i][k]<a[j][k]) return -1;
	 else if (a[i][k]>a[j][k]) return 1;
	return 0;
}

void swap(int i,int j){
	int *temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void heapify(int i,int n){
	int l=2*i;int r=2*i+1;
	int maxidx=i;
	if (l<=n&&cmp(l,maxidx)==1) maxidx=l;
	if (r<=n&&cmp(r,maxidx)==1) maxidx=r;
	if (maxidx!=i){
		swap(i,maxidx);
		heapify(maxidx,n);
	}
}

void buildheap(int n){
	for (int i=n/2;i>=1;i--) heapify(i,n);
}

void heapsort(int n){
	buildheap(n);
	for (int i=n;i>=2;i--){
		swap(1,i);
		heapify(1,i-1);
	}
}


int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
	 a[i]=(int*)malloc(sizeof(int)*(m+1));
	 for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	heapsort(n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
}
