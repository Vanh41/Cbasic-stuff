#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

#define N 1000001


// Given an integer n, write a program to generate the last k permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
// ////////
//  Note: In C, the terminated command:
// #include <stdlib.h>
// void quit(){
// 	exit(0);
// }
// ////////////
// Input: Two integers: n,k. (n<=10000, k < 1001)
// Output: The last k permutations.

// Example:
// Input:
// 3 2
// Output:
// 3 1 2
// 3 2 1


int n;
int a[N];
int ans[1000][1000];
int check[N]={0};
int count=0;
int k;

void print(int x){
    for (int i=1;i<=n;i++) printf("%d ",ans[x][i]);
    printf("\n");
}

void push(){
    for (int i=1;i<=n;i++) ans[count][i]=a[i];
}

void Try(int x){
   // if (count==k) return;
    for (int i=1;i<=n;i++){
        if (check[i]==0){
            a[x]=i;
            check[i]=1;
            if (x==n) {
                count++;
                push();
            }
            else Try(x+1);
            check[i]=0;
        }
    }
}



int main () {
    scanf("%d %d", &n,&k);
    Try(1);
    for (int i=1;i<=k;i++) print(count-k+i);
}