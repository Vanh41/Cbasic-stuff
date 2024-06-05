#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int a[100001]={0};
int mark[100001]={0};
int max=0;
int n=0;

int sum(int i,int j){
    return mark[j]-mark[i-1];
}

void initsum(){
    for (int i=1;i<=n;i++){
    mark[i]=mark[i-1]+a[i];
    }
}

int main(){
    scanf("%d",&n);
    
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    initsum();

    int q;
    scanf("%d",&q);
    int ans[100001]={0};
    int count=1;
   // for (int i=1;i<=n;i++) printf(" %d ",mark[i]);
    for (int i=1;i<=q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        ans[count++]=sum(x,y);
    }
    for (int i=1;i<count;i++) printf("%d\n",ans[i]);
}
