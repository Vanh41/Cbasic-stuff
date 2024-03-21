#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdio.h>
#include <math.h>

void hanoitower(int n,int start,int finish,int temp){
	if (n==1) printf("%d %d\n",start,finish);
	else
	{
		hanoitower(n-1,start,temp,finish);
		hanoitower(1,start,finish,temp);
		hanoitower(n-1,temp,finish,start);
	}
}



int main(){
  int n,a,b,c;
  scanf("%d %d %d %d",&n,&a,&b,&c);
  hanoitower(n,a,b,c);
}
