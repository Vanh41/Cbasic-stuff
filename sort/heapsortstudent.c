#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001
typedef struct Student{
	char ID[10];
	int grade;
	int pos;
}student;

student S[N];
int n;

void input(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s %d",S[i].ID,&S[i].grade);
	}
}
void swap(int i, int j){
	student t=S[i];S[i]=S[j];S[j]=t;
}

void heapify(int i, int n){
	int l=2*i; int r=2*i+1;
	int max=i;
	if(l<=n&&S[max].grade<S[l].grade) max=l;
	if(r<=n&&S[max].grade<S[r].grade) max=r;
	if(max!=i){
		swap (i,max);
		heapify(max,n);
	}
}

void buildHeap(){
	for(int i=n/2; i>=1; i--){
		heapify(i,n);
	}
}

void heapSort(){
	buildHeap();
	for(int i=n; i>=2; i--){
		swap(1,i);
		heapify(1,i-1);
	}
}
void heapify2(int i, int n){
	int l=2*i; int r=2*i+1;
	int max=i;
	if(l<=n&&strcmp(S[max].ID,S[l].ID)<0) max=l;
	if(r<=n&&strcmp(S[max].ID,S[r].ID)<0) max=r;
	if(max!=i){
		swap(i,max);
		heapify2(max,n);
	}
}

void buildHeap2(){
	for(int i=n/2;i>=1;i--){
		heapify2(i,n);
	}
}

void heapSort2(){
	buildHeap2();
	for (int i=n;i>=2;i--){
		swap(1,i); heapify2(1,i-1);
	}
}

void print(){
	for (int i=1;i<=n;i++){
		printf("%s %d\n",S[i].ID,S[i].pos);
	}
}

int main(){
	input();
	heapSort();
	for (int i=1; i<=n; i++){
		S[i].pos=i-1;
	}
	heapSort2();
	print();
	return 0;
}