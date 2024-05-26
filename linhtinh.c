#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include<stdbool.h>

void ham3(unsigned int n,unsigned int b){
    if (n==0||b==0) return;
    else{
        ham3(n/b,b);
        printf("%d",n%b);
    }
}

int main(){
 ham3(2020,8);
}
