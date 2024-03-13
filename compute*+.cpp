#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>


int check(char a[]){
	int i=1;
	if (a[0]=='*'||a[0]=='+') return 0;
	while(a[i]!='\0'){
		if ((a[i]=='*'||a[i]=='+')&&(a[i-1]=='*'||a[i-1]=='+'))
		return 0;
		i++;
	}
	if (isdigit(a[i-1])==0) return 0;
	return 1;
}

int compute(char a[]){
	int i=0;
	int num[15000];
	int ans=0;
	int val=0;
	int count=0;
	int tmp[15000];
	int sum=0;
	for (int i=0;i<100;i++) tmp[i]=1;
	while(a[i]!='\0'){
		if (isdigit(a[i])>0){
		val=val*10+a[i]-'0';
		i++;
	}
	   else {
	   	num[i-1]=val;
        val=0;
	   	i++;
	   }
	   if (a[i]=='\0') num[i-1]=val;	
	}
   i=0;
   while (a[i]!='\0'){
   	if (a[i]=='*'){
   		tmp[count]=tmp[count]*num[i-1];
   		num[i-1]=0;
   		i++;
	   }
	   else if (a[i]=='+'&&a[i-2]=='*'){
	   	tmp[count]=tmp[count]*num[i-1];
	   	num[i-1]=0;
	   	count++;
	   	i++;
	   }
	   else i++;
	  if (a[i]=='\0'&&a[i-2]=='*') {
	   	tmp[count]=tmp[count]*num[i-1];
	   	num[i-1]=0;
	   	count++;
	   }
   }
  for (int i=0;i<strlen(a);i++)
   if (num[i]!=0) sum=sum+num[i];
   for (int i=0;i<count;i++)
   if (tmp[i]!=1)
   sum=sum+tmp[i];
   return sum; 	 
}

int main(){
	char a[15000];
	int i=0;
	scanf("%s",a);
	if (check(a)==0) printf("NOT_CORRECT");
	else
	printf("%d",compute(a));
}
