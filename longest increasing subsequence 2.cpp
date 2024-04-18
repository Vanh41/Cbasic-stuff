#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int a[100000]={0};
int Length[100000]={0};
int Truyvet[100000];

int main(){
  int n;
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&a[i]);
  int i,j;
  int lengthmax=0; // luu lai gia tri tot nhat tai a[i]
  Length[1]=1;
//   cai dat quy hoach dong
   for (i=1;i<=n;i++){
      lengthmax=0;
      for (int j=1;j<=i;j++)
       if (a[i]>a[j]&&Length[j]>lengthmax) lengthmax=Length[j];
       Length[i]=lengthmax+1; 
   }
   for (i=1;i<=n;i++)
   if (Length[i]>lengthmax) lengthmax=Length[i];
   printf("%d\n",lengthmax);
}
