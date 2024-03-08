#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int check(int i,int j,char p1[],char text[]){
    int count=0;
    for (int x=i;x<=j;x++){
       if (text[x]!=p1[count++]) return 0;
    }
    return 1;
}



int main(){
   char p1[2000];
   char p2[2000];
   char text[2000];
   scanf("%[^\n]s",p1);
   getchar();
   scanf("%[^\n]s",p2);
   getchar();
   fflush(stdin);
   fgets(text,2000,stdin);
   for (int i=0;i<strlen(text);i++)
    for (int j=i;j<strlen(text);j++)
     if (check(i,j,p1,text)==1) {
        strncpy(text+i,"",strlen(p1)); 
        strncpy(text+i,p2,strlen(p2));
     }
   printf("%s",text);
   return 0;
}
