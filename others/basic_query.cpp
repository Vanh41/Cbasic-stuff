#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>


int findmax(int a[],int n){
	int max=-99999;
	for (int i=0;i<n;i++) if (a[i]>max) max=a[i];
	return max;
}
int findmin(int a[],int n){
	int min=99999;
	for (int i=0;i<n;i++) if (a[i]<min) min=a[i];
	return min;
}
int sum(int a[],int n){
	int s=0;
	for (int i=0;i<n;i++) s+=a[i];
	return s;
}
int compute(int a[],int i,int j){
	int max=-99999;
	for (int k=i-1;k<=j-1;k++) if (a[k]>max) max=a[k];
	return max;
}

int main(){
	int n;
	int a[10000];
	char s[10000];
	scanf("%d",&n);
	int i,j;
	int ans[10000];
	int count=0;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("\n*");
	while (strcmp(s,"***")!=0){
		scanf("%s",s);
		if (strcmp(s,"find-max")==0) ans[count++]=findmax(a,n);
		if (strcmp(s,"find-min")==0) ans[count++]=findmin(a,n);
		if (strcmp(s,"sum")==0) ans[count++]=sum(a,n);
		if (strcmp(s,"find-max-segment")==0) {
			scanf(" %d %d",&i,&j);
			ans[count++]=compute(a,i,j);
		}
	}
	for (int i=0;i<count;i++) printf("%d\n",ans[i]);
}
