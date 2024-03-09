#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
int main(){
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	float delta=b*b-4*a*c;
	if (delta<0) printf("NO SOLUTION");
	else if (delta==0){
		float x;
		x=-b/(2*a);
		printf("%.2f",x);
	}
	else if (delta>0){
		float x1,x2;
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		if (x1<x2) printf("%.2f %.2f",x1,x2);
		else printf("%.2f %.2f",x2,x1);
	}
}
