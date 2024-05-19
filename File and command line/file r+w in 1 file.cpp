#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int main(){
    FILE *fptr1;
    fptr1=fopen("tata.txt","r+w");
    char s[1000];
    while (fgets(s,1000,fptr1)!=NULL){
        for (int i=0;i<strlen(s);i++) s[i]=toupper(s[i]);
        fflush(fptr1);  
        fputs(s,fptr1=fopen("tata.txt","w"));
    }
    fclose(fptr1);
}
