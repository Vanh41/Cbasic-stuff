#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
// ex: n=3,C={8,3,1,2}
// co 3 cach de lay dc 3 dong :
//  {1,1,1} ; {1,2} ; {3}
// 

int n,m;
int C[1000];
int F[1000][1000];


int main(){
 scanf("%d %d",&n,&m);
 for (int i=0;i<m;i++) scanf("%d",&C[i]);
//  base case 
for (int i=0;i<m;i++) F[i][0]=1;
// cai dat qhd
 for (int i=0;i<m;i++)
  for (int j=1;j<=n;j++){
    if (i>0) F[i][j]+=F[i-1][j];
    if (C[i]<=j) F[i][j]+=F[i][j-C[i]];
      }
// in table
  for (int i=0;i<m;i++)
   {
    for (int j=1;j<=n;j++) printf("%d ",F[i][j]);
    printf("\n");
   }
 printf("%d",F[m-1][n]);
}
