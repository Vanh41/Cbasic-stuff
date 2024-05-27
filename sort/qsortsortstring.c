#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int cmpstr(const void* a, const void* b) {
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa, bb);
}



int main(){
	int n;
	scanf("%d",&n);
	char **a;
	a=(char**)malloc((n)*sizeof(char*));
	for (int i=0;i<n;i++) {
	char temp[100000];
	scanf("%s",temp);
	a[i]=(char*)malloc((strlen(temp)+1)*sizeof(char));
	strcpy(a[i],temp);
	}
	qsort(a,n,sizeof(a[0]),cmpstr);
	for (int i=0;i<n;i++) printf("%s\n",a[i]);
}
