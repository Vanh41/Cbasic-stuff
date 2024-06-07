#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

// n cuoc hop, bat dau o ai, ket thuc o bi, bo tri phong hop
// sao cho phuc vu nhieu cuoc hop nhat
// hint: sap xep cac cuoc hop theo tg bat dau ai, cuoc hop i se duoc bo
// tri sau cuoc hop j <=> j<i && b[j]<=a[i]

typedef struct meeting{
    int id;     // stt
    int a;  // thoi diem bat dau
    int b;    // thoi diem ket thuc
}meeting;

int n;
meeting m[100000];
int DP[1000];
int T[1000]; // mang truy vet

int cmp(const void *ptr1,const void *ptr2){
    meeting *x=(meeting*)ptr1;
    meeting *y=(meeting*)ptr2;
    if (x->a>y->a) return 1;
    if (x->a==y->a&&x->b>y->b) return 1;
    return -1;
}

void print(){
    for (int i=0;i<n;i++){
        printf("%d %d\n",m[i].a,m[i].b);
    }
}


int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        m[i].id=i+1;
        scanf("%d %d",&m[i].a,&m[i].b);
    }
    qsort(m,n,sizeof(meeting),cmp);
    printf("\n");
    // print();
    //cai dat qhd
    for (int i=0;i<n;i++){
        DP[i]=1;
        for (int j=0;j<n;j++){
            if (m[j].b<=m[i].a&&DP[i]<DP[j]+1) {
                DP[i]=DP[j]+1;
                T[i]=j;
            }
        }
    }
    printf("%d\n",DP[n-1]);
}
