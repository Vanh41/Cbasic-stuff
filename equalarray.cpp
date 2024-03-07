#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int n,m;
    int ans[t];
    for (int i=0;i<t;i++) ans[i]=0;
    int count=0;
    for (int i=0;i<t;i++){
        scanf("%d %d",&n,&m);
        int x=0;
        int a[n];
        int b[m];
        for (int j=0;j<n;j++) scanf("%d",&a[j]);
        for (int j=0;j<m;j++) scanf("%d",&b[j]);
        if (n!=m) continue;
        for (int j=0;j<n;j++) if (a[j]!=b[j]) { x=1;}
        if (x==1) continue;
        ans[i]=1;
    }
    for (int i=0;i<t;i++) printf("%d\n",ans[i]);
    return 0;
}
