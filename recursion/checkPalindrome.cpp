#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

bool checkPaline(char s[],int first,int last){
	if (first>=last) return true;
	else 
	if (s[first]==s[last]) return checkPaline(s,first+1,last-1);
	else return false;
}

int main(){
 char s[1000];
  scanf("%s",s);
  bool ans=checkPaline(s,0,strlen(s)-1);
  if (ans==0) printf("Not Palindrome");
  else printf("Palindrome");
}
