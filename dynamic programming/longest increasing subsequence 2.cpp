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
int Truyvet[100000]={0};

int main(){
  int n;
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf("%d",&a[i]);
  int i,j;
  int lengthmax=0; // luu lai gia tri tot nhat tai a[i]
  Length[1]=1;
  int Endindex;
  int index=-1; //luu vi tri tai do co do dai lon nhat
//   cai dat quy hoach dong
   for (i=1;i<=n;i++){
      lengthmax=0;
      index=-1;
      for (int j=1;j<=i;j++)
       if (a[i]>a[j]&&Length[j]>lengthmax) {
         lengthmax=Length[j];
         index=j;
       }
       Length[i]=lengthmax+1;
       Truyvet[i]=index; 
   }
   for (i=1;i<=n;i++)
   if (Length[i]>lengthmax) {
      lengthmax=Length[i];
      Endindex=i; // Vi tri ket thuc co do dai lon nhat
   }
   printf("%d\n",lengthmax); // do dai day con tang lon nhat 

 for (int i=1;i<=n;i++) printf("%d ",Length[i]); // DP case
  printf("\n");

  for (int i=1;i<=n;i++) printf("%d ",Truyvet[i]); // Vị trí tương ứng tiếp theo kể từ Endindex
  printf("\n");
  
  printf("%d\n", Endindex); // vị trí có độ dài lớn nhất
  // cài đặt truy vết
  while (true){
   i=Endindex;
   printf("%d ",a[i]);
   Endindex=Truyvet[i];
   if (Truyvet[Endindex]==-1) {
      printf("%d ",a[Endindex]);
      break;
  }
  }
}
