#include <stdio.h>
#include <math.h>

int fibo(int x){
  if (x<0) return(-1);
  else if ((x==0)||(x==1)) return(x);
  else return(fibo(x-1)+fibo(x-2));
}


int main(){
	int n,i,j,a,b;
	scanf("%d",&a);
    for (i=0;i<a;i++) printf("%d ",fibo(i));
return 0;
}
