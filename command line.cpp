#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int main(int argc,char *argv[]){
    double width,height;
    if (argc!=3){
        printf("Wrong number of argument!\n");
        printf("CORRECT SYNTAX: RECT <WIDTH> <HEIGHT>\n");
        return 1;
    }
    width=atof(argv[1]);
    height=atof(argv[2]);
    printf("The rectangle's area is %f\n",width*height);
    return 0;
}
