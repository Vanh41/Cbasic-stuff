#include<stdio.h>
int n;
int c[30][30];
int x[30];
int vs[30];
int cmin=999999999;
int f=0;
int fopt=999999999;
void Try(int k){
    for(int i=1;i<=n;i++){
        if(vs[i]==0){
            x[k]=i;
            vs[i]=1;
            if(k==1){
                f+=(c[0][x[k]]+c[x[k]][x[k]+n]);
            }
            else
            f+=(c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n]);
            if(k==n){
                int ftemp=f+c[x[n]+n][0];
                if(ftemp<fopt)
                    fopt=ftemp;
            }
            else{
                int g = f +(2*n-k+1)*cmin;

                if(g<fopt) Try(k+1);
            }
            vs[i]=0;
            if(k==1)
                f-=(c[0][x[k]]+c[x[k]][x[k]+n]);
            else
            f-=(c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n]);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+1;j++){
            scanf("%d",&c[i][j]);
            if(cmin>c[i][j])
                cmin=c[i][j];
        }
    }
    for(int i=0;i<30;i++){
        vs[i]=0;
    }
    x[0]=0;
    Try(1);
    printf("%d",fopt);
    return 0;
}
