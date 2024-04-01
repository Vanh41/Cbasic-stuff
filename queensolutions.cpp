#include <stdio.h>
#include <math.h>
#include <string.h>
int a[20], b[20], c[20], count=0, k=0;
int ok(int x, int y){ 
	for(int i=0; i<x; ++i) if(a[c[i]]==y||abs(c[i]-b[x-k])==abs(a[c[i]]-y)) return 0; 
	return 1;
}

void Try(int i, int n){ //xep thu
	for(int j=0; j<n; ++j){ //xep thu vao tung cot tu 0 den n-1
	    if(ok(i, j)){
		    a[b[i-k]]=j; c[i]=b[i-k];
		    if(i==n-1) count++;
		    else Try(i+1, n); 
	    }
    }
}

int main(){

	int n, h=0;
	memset(a, -1, sizeof(a));
	scanf("%d", &n);
	int q[13][13];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &q[i][j]);
			if(q[i][j]==1){
			    a[i]=j;
			    c[k++]=i; //chua nhung hang da dat hau
			}
		}
	}
	for(int i=0; i<n; i++) if(a[i]==-1) b[h++]=i; //chua nhung hang chua xep hau
    Try(k, n);
	printf("%d", count);
	return 0;

}
