#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

void f(int n, int b){
    if(n==0) return; else{
    f(n/b,b);
    printf("%d",n%b); }
}

int main(){
   f(2020,8);
}