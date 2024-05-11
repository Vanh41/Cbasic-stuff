#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int main(){
    FILE *fptr1,*fptr2;
    fptr1=fopen("Fileinput.txt","r");
    fptr2=fopen("Fileoutput.txt","w");
    char line[10000];
    int c;
    while((c=fgetc(fptr1))!=EOF){
        printf("Convert the letter into uppercase letter");
        c=toupper(c);
        fputc(c,fptr2);
        putchar(c);
    }
    fclose(fptr1);
    fclose(fptr2);
}
