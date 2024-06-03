#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct ca{
	char code[11];
	int score;
};
typedef struct ca candidate;


int n,m;
candidate a[100001];



void swap(int i,int j){
	candidate temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void heapify(int i,int n){
	int l=2*i;int r=2*i+1;
	int maxidx=i;
	if (l<=n&&a[l].score<a[maxidx].score) maxidx=l;
	if (r<=n&&a[r].score<a[maxidx].score) maxidx=r;
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
	int i=1;
	while (1){
	scanf("%s",a[i].code);
	if (strcmp(a[i].code,"#")==0) break;
	else scanf("%d",&a[i].score);
	i++;
	}
	int n=i-1;
//	for (int i=1;i<=n;i++) printf("%s %d\n",a[i].code,a[i].score);
	heapsort(n);
	for (int i=1;i<=n;i++) printf("%s %d\n",a[i].code,a[i].score);
}
