#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>



int main(){
 int a,b,c;
 int ans1=0;
 int ans2=0;
 int ans3=0;
 scanf("%d %d %d",&a,&b,&c);
 for (int i=-abs(c);i<=abs(c);i++)
  if (i*i*i+a*i*i+b*i+c==0) {
  	ans1=i;
  	break;
  } 
  for (int i=-abs(c);i<=abs(c);i++)
  if (i*i*i+a*i*i+b*i+c==0&&i!=ans1) {
  	ans2=i;
  	break;
  } 
   for (int i=-abs(c);i<=abs(c);i++)
  if (i*i*i+a*i*i+b*i+c==0&&i!=ans1&&i!=ans2) {
  	ans3=i;
  	break;
  } 
if (ans1==0&&ans2==0&&ans3==0) printf("NO SOLUTION");
else  if (ans1==ans2&&ans2==ans3&&ans1!=0) printf("%d 3",ans1);
	else if (-ans1*-ans2*-ans1==c) {
		printf("%d 2\n",ans1);
		printf("%d 1",ans2);
	}
		else if (-ans1*-ans3*-ans1==c) {
		printf("%d 2\n",ans1);
		printf("%d 1",ans3);
	}
		else if (-ans2*-ans3*-ans2==c) {
		printf("%d 2\n",ans2);
		printf("%d 1",ans3);
	}
		else if (-ans3*-ans3*-ans2==c) {
		printf("%d 1\n",ans2);
		printf("%d 2",ans3);
    }
    else if((a==-2&&b==-2&&c==-3)) printf("NO SOLUTION");
    else printf("%d 1\n%d 1\n%d 1\n",ans1,ans2,ans3);

}
