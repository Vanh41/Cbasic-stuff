#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int a[100000]={0};
bool comp[100000]={0};
int mem[100000]={0};

int max(int x,int y){
	if (x>y) return x;
	return y;
}

int maxsum(int i){
	if (i == 1) return a[i];
	if (comp[i]) return mem[i];
	int res = max(a[i],a[i]+maxsum(i-1));
	mem[i]=res;
	comp[i]=true;
	return res;
}

int main(){
  int n;
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&a[i]);
  int maximum=0;
  maxsum(n);
  for (int i=1;i<=n;i++){
	maximum=max(maximum,mem[i]);
  }
  printf("%d",maximum);
}
