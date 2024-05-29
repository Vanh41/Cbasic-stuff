#include <stdio.h>
#include <stdlib.h>

int n=4, m=23,S=0, count=0;

void Try(int k, int last){
    for(int v=last+1; v<=m; v++){
        S+=v;
        if(k==n){
            if(S==m) count++;
        }
        else Try(k+1, v);
        S-=v;
    }
}

int main(){
    Try(1,0);
    printf("%d", count);
}