#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct list{
    char username[100];
    char password[100];
    float point;
    struct list *next;
};
typedef struct list node;







void log(){
    int count=0;
    while (count<=3){
        char username[100];
        char password[100];
        printf("Username: \n");
        scanf("%s",username);
        printf("Password: \n");
        scanf("%s",password);
    }
}




int main(){
    FILE *fptr1 , *fptr2;
    system("clear");
    while (1){
        // menu 
        int n;
        printf("1. LOGIN \n");
        printf("2. QUIT \n");
        scanf("%d",&n);
        if (n==2) {
            system("clear");
            break;
        }
        else if (n==1){
            system("clear");
            
        }
    }
    return 0;
}