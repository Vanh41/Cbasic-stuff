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
    char s[1000];
    int count=0;
    while (fgets(s,1000,fptr1)!=NULL){
        fputs(s,fptr2);
        count++;
    }
    fprintf(fptr2,"\nThis file has %d line",count);
    fclose(fptr1);
    fclose(fptr2);
}
