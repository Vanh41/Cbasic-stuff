#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct student{
	char id[11];
	int grade;
	int pos;
	
}student;
student s[100001];
int n;

void swap(int i,int j){
	student temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}

void heapify(int i,int n){
	int l=2*i;
	int r=2*i+1;
	int maxidx=i;
	if (l<=n&&s[l].grade>s[maxidx].grade) maxidx=l;
	if (r<=n&&s[l].grade>s[maxidx].grade) maxidx=r;
	if (maxidx!=i){
		swap(i,maxidx);
		heapify(maxidx,n);
	}
}

void buildheap(){
	for (int i=n/2;i>=1;i--) heapify(i,n);
}

void heapsort(){
	buildheap();
	for (int i=n;i>=2;i--){
		swap(1,i);
		heapify(1,i-1);
	}
}


void heapify2(int i,int n){
	int l=2*i;
	int r=2*i+1;
	int maxidx=i;
	if (l<=n&&strcmp(s[l].id,s[maxidx].id)>0) maxidx=l;
	if (r<=n&&strcmp(s[r].id,s[maxidx].id)>0) maxidx=r;
	if (maxidx!=i){
		swap(i,maxidx);
		heapify2(maxidx,n);
	}
}

void buildheap2(){
	for (int i=n/2;i>=1;i--) heapify2(i,n);
}

void heapsort2(){
	buildheap2();
	for (int i=n;i>=2;i--){
		swap(1,i);
		heapify2(1,i-1);
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s %d",s[i].id,&s[i].grade);
	}
	heapsort(n);
	for (int i=1;i<=n;i++) s[i].pos=i-1;
	heapsort2();
	for (int i=1;i<=n;i++)
		printf("%s %d\n",s[i].id,s[i].pos);
		
}
