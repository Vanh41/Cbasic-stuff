#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int main(){
  int a,b,c,i,j,k;
  int ans1=0;
  int ans2=0;
  int ans3=0;
  int x=0;
  scanf("%d %d %d",&a,&b,&c);
  if (c<0)
  for (i=c;i<=-c;i++){
   for (j=i;j<=-c;j++){
    for (k=j;k<=-c;k++)
     if ((-i)*(-j)*(-k)==c&&(-i+-j+-k)==a&&(i*j+j*k+i*k)==b) {
     	ans1=i;
     	ans2=j;
     	ans3=k;
     	x=1;
     	break;
	 }
	 if (x==1) break;
}
if (x==1) break;
}

if (ans1==0||ans2==0||ans3==0) printf("NO SOLUTION");
else {
	if (ans1==ans2&&ans2==ans3) printf("%d 3",ans1);
	else if (ans1==ans2) {
		printf("%d 2\n",ans1);
		printf("%d 1",ans3);
	}
		else if (ans1==ans3) {
		printf("%d 2\n",ans1);
		printf("%d 1",ans2);
	}
		else if (ans2==ans3) {
		printf("%d 1\n",ans1);
		printf("%d 2",ans2);
	}
	else {
		printf("%d 1\n%d 1\n%d 1",ans1,ans2,ans3);
	}
}
}
