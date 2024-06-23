#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int grid[1000][1000];
int markR[100][100];
int markC[100][100];
int markS[100][100][100];
int count=0;

bool check(int i,int j,int v){
    if (markC[j][v]==0&&markR[i][v]==0&&markS[i/3][j/3][v]==0) return true;
    return false;
}

void Try(int i,int j){
    if (grid[i][j]>0){
        if (i==8&&j==8) count++;
        else {
            if (j==8) Try(i+1,0);
            else Try(i,j+1);
        }
        return;
    }
    for (int v=1;v<=9;v++)
        if (check(i,j,v)==true){
            grid[i][j]=v;
            markC[j][v]=1;
            markR[i][v]=1;
            markS[i/3][j/3][v]=1;
            if (i==8&&j==8) count++;
            else {
                if (j==8) Try(i+1,0);
                else Try(i,j+1);
            }
            grid[i][j]=0;
            markC[j][v]=0;
            markR[i][v]=0;
            markS[i/3][j/3][v]=0;
        }
}



int main(){
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++){
            scanf("%d",&grid[i][j]);
            if (grid[i][j]>0){
                markR[i][grid[i][j]]=1;
                markC[j][grid[i][j]]=1;
                markS[i/3][j/3][grid[i][j]]=1;
            }
        }
    Try(0,0);
    printf("%d",count);
}