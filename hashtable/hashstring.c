#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
int m;
char s[100000];

int hash(){
    int code=0;
    int k=strlen(s);
    for (int i=1;i<=k;i++) code=(code*256+s[i-1])%m;
    return code;
}



int main(){
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%s",s);
        printf("%d\n",hash());
    }
}
