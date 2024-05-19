#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Có 𝑛 đồ vật, vật thứ 𝑖 có trọng lượng Weight𝑖 và giá trị Value𝑖
// mỗi vật một cái để xếp vào 1 vali có trọng lượng tối đa 𝑊 sao cho tổng giá trị của vali là lớn nhất.
// chọn 1 lần

int Maxweight;
int Weight[1000]={0};
int Value[1000]={0};
int n;
int F[1000][1000];


int max(int x,int y){
  if (x>y) return x;
  return y;
}


int main(){
  scanf("%d %d",&n,&Maxweight);
  for (int i=1;i<=n;i++) scanf("%d %d",&Weight[i],&Value[i]);
  int i,j;
  // 
  for (i=1;i<=n;i++)
   for (j=1;j<=Maxweight;j++)
    if (Weight[i]<=j) F[i][j]=max(F[i-1][j-Weight[i]]+Value[i],F[i-1][j]);
    else F[i][j]=F[i-1][j]; 
  printf("%d",F[n][Maxweight]);
}
