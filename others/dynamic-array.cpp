#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
int main(){
	int t;
	int i,j;
 scanf("%d",&t);
 int ans[1000];
 for (int i=0;i<t;i++) ans[i]=0;
 int **array;
 for (int n=0;n<t;n++){
 	int k;
 	scanf("%d",&k);
  array = (int**) malloc(k * sizeof(int*));

    for (i = 0; i < k; i++) {
        array[i] = (int*) malloc(k * sizeof(int));

    }
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}

}
