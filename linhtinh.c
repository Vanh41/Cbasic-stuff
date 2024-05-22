#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int a[1000];
int n;


int main(){
  scanf("%d",&n);   
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
  for (int i=0;i<n;i++) printf("%d",a[i]);

}