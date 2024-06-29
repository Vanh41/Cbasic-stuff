#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int parent[1000]={0};
int sz[1000]={0};
int res=0;
int nums[1000];
int mark[1000];
int n;

void makeset(int x){
    parent[x]=x;
    sz[x]=1;
}

int find(int x){
    if (parent[x]==x) return x;
    parent[x]=find(parent[x]);
    return parent[x];
}

void uni(int x,int y){
    if (sz[x]>sz[y]){
        sz[x]+=sz[y];
        parent[y]=x;
        if (res<sz[x]) res=sz[x];
    }
    else {
        sz[y]+=sz[x];
        parent[x]=y;
        if (res<sz[y]) res=sz[y];
    }
}

void longestconsecutive(){
    for (int i=0;i<n;i++) makeset(nums[i]);
    for (int i=0;i<n;i++) mark[nums[i]]=i;
    int identifier1,identifier2;
    for (int i=0;i<n;i++){
        int k=nums[i];
        if (mark[k-1]!=0){
            identifier1=find(k);
            identifier2=find(k-1);
            if (identifier1!=identifier2) uni(identifier1,identifier2);
        }
        if (mark[k+1]!=0){
            identifier1=find(k);
            identifier2=find(k+1);
            if (identifier1!=identifier2) uni(identifier1,identifier2);
        }
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&nums[i]);
    longestconsecutive();
    printf("%d",res);
}