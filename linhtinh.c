#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include<stdbool.h>

int ham4(unsigned int n){
    if (n==0) return 0;
    else{
        printf("%d ",n);
        return ham4(n-1)+ham4(n-1);
    }
}

int main(){
 ham4(6);
}
