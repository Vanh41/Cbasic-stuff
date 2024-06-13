#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int DP[1000][1000];
int n;

typedef struct value{
    int a;  //start
    int b;  //end
    int c;  //weight
    int id; //stt
}value;

value net[10000];

int cmp(const void *ptr1,const void *ptr2){
    value *x=(value*)ptr1;
    value *y=(value*)ptr2;
    int xx=x->a;
    int yy=y->a;
    if (xx>yy) return 1;
    if (xx==yy&&x->b>y->b) return 1;
    return -1;
}

int max(int x,int y){
    if (x>y) return x;
    return y;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d %d %d",&net[i].a,&net[i].b,&net[i].c);    
        net[i].id=i+1;
    };
    qsort(net,n,sizeof(value),cmp);
    for (int i=0;i<n;i++) printf("%d %d %d\n",net[i].a,net[i].b,net[i].c);
    // cai dat
    for (int i=0;i<n;i++){
        for (int j=net[i].c;j>=0;j--)
        DP[i][j]=DP[i-1][net[i].c-j]+max(DP[i][j],DP[])
    }
}
