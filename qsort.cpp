#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp1(const void *ptr1, const void *ptr2){
    int *x = (int*)ptr1;
    int *y = (int*)ptr2;
    return abs(*x) - abs(*y);
}

int main(){
    int n = 10;
    int a[10] = {3, -1, 2, 4, -5, -9, 8, 7, -10, 6};
    printf("Sap xep theo tri tuyet doi tang dan :\n");
    qsort(a, n, sizeof(int), cmp1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
//Output : 

//Sap xep theo tri tuyet doi tang dan :
//-1 2 3 4 -5 6 7 8 -9 -10
