#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char a[100000];
char b[100000];
int S[1000][1000]={0};// Store the longest commom subsequence
char Trace[1000][1000];

int max(int x,int y){
  if (x>y) return x;
  return y;
}


int main(){
  scanf("%s",a);
  scanf("%s",b);
  int n=strlen(a);
  int m=strlen(b);
  int i,j;
  // base case
  for (i=0;i<n;i++) S[i][0]=0;
  for (j=0;j<m;j++) S[0][j]=0;
  // cai dat qhd
  for (i=0;i<n;i++)
   for (j=0;j<m;j++)
   if (a[i]==b[j])
        S[i][j]=S[i-1][j-1]+1;
   else S[i][j]=max(S[i][j-1],S[i-1][j]);
  printf("%d\n",S[n-1][m-1]);
//   cai dat truy vet
 i=n;
 j=m;
 char result[1000];
 int count=0;
 //printf("%c",a[i-1]);
 while(i>=0&&j>=0){
    if (a[i-1]==b[j-1]) {
      result[count++]=a[i-1];
      i--;
      j--;
    }
    else if (S[i-1][j]>S[i][j-1]) i--;
    else  j--;
 }
 for (int i=count;i>=0;i--) printf("%c",result[i]);
}
