#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int a[1000000];
int mem[1000000];
bool comp[1000000];

void Memset(bool t[], int n){
	for (int i=0; i<1000000; i++) a[i] = 0;
}

int max_sum(int i){
	if (i == 1) return a[i];
	if (comp[i]) return mem[i];
	int res = fmax(a[i], a[i] + max_sum(i - 1));
	mem[i] = res;
	comp[i] = true;
	return res;
}

int main(){
	memset(comp, 0, sizeof(comp));
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	
	int MAX = -999999999;
	for (int i=1; i<n; i++){
		int s = max_sum(i);
		if (s > MAX) MAX = s;
	}
	printf("%d", MAX);
	
	return 0;
}
