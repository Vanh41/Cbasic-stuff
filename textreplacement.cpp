#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char ans[2000];

void replaceString(const char *find, const char *replace,char *text) {
    char *pos = strstr(text, find);
    while (pos != NULL) {
        int lenFind = strlen(find);
        int lenReplace = strlen(replace);
        memmove(pos + lenReplace, pos + lenFind, strlen(pos + lenFind) + 1);
        memcpy(pos, replace, lenReplace);
        pos = strstr(pos + lenReplace, find);
    }
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
   replaceString(p1,p2,text);
   printf("%s",text);
   return 0;
}
