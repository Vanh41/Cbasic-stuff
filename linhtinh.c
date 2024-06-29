#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int parent[1000]={0};
int sz[1000]={0};
int res=0;

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

int main(){
    char cmd[100];

}