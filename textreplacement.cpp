#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int check(int i,int j,char p1[],char text[]){
    for (int x=i;x<=j;x++){
       if (text[x]!=p1[x]) return 0;
    }
    return 1;
}



int main(){
   char p1[2000];
   char p2[2000];
   char text[2000];
   fflush(stdin);
   scanf("%s",p1);
   scanf("%s",p2);
   getchar();
   fflush(stdin);
   fgets(text,1000,stdin);
   for (int i=0;i<strlen(text);i++)
    for (int j=i;j<strlen(text);j++)
     if (check(i,j,p1,text)==1) {
         for (int k=i;k<=j;k++) text[k]=p2[k];
     }
   printf("%s\n%s\n%s",p1,p2,text);
   return 0;
}
