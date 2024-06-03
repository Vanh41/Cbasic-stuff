#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n,m;
int a[100001],b[100001];
int count=0;

int cmp(const void *ptr1, const void *ptr2){
	int *x=(int*)ptr1;
	int *y=(int*)ptr2;
	return *x-*y;
}

void maxcommonsubset(){
	int i=0,j=0;
	while (i<n&&j<m){
		if (a[i]==b[j]) {
			count++;
			i++;
			j++;
		}
		else if (a[i]>b[j]) j++;
		else i++;
	}
}


int main(){
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	int i=0,j=0;
	qsort(a,n,sizeof(int),cmp);
	qsort(b,m,sizeof(int),cmp);
	//for (int i=0;i<n;i++) printf("%d ",a[i]);
	//printf("\n");
	//for (int i=0;i<m;i++) printf("%d ",b[i]);
	//printf("\n");
	maxcommonsubset();
	printf("%d",count);	
}
