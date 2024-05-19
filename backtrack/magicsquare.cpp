#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>
int grid[4][4];
int mark[16]={0};
bool get_rc(int &i,int &j){
	for ( i=0;i<4;i++)
	 for ( j=0;j<4;j++)
	   if (grid[i][j]==0) 
		return true;
	return false;
}
bool checkzero(){
	for (int i=0;i<4;i++)
	 for (int j=0;j<4;j++)
	 if (grid[i][j]==0) return false;
	 return true;
}
void print(){
	for (int i=0;i<4;i++){
	 for (int j=0;j<4;j++)
	 printf("%d ",grid[i][j]);
	 printf("\n");
}
printf("\n");
}
bool checkrow(int i){
	int j;
   	int sum=34;
    int temp=0;
    for ( j=0;j<4;j++) temp+=grid[i][j];
    if (temp<sum) return false;
	if (temp==sum)return true;
}
bool checkrow1(int i){
	int j;
   	int sum=34;
    int temp=0;
    for ( j=0;j<4;j++) if (grid[i][j]==0) return false;
	return true;
}
bool checkgrid(){
   	int i,j;
   	int sum=34;
    int temp=0;
    //for ( i=0;i<4;i++) sum+=grid[i][0];
    for ( i=0;i<4;i++){
    	temp=0;
    	for ( j=0;j<4;j++) temp+=grid[i][j];
    	if (temp!=sum) return false;
	}
	for ( j=0;j<4;j++){
    	temp=0;
   	    for (i=0;i<4;i++) temp+=grid[i][j];
    	if (temp!=sum) return false;
	}
	temp=0;
	i=0;j=0;
	while(i<=3&&j<=3){
		temp+=grid[i++][j++];
	}
	if (temp!=sum) return false;
    temp=0;
	i=3;j=0;
	while(i>=0&&j<=3){
		temp+=grid[i--][j++];
	}
	if (temp!=sum) return false;
	return true;
}


void Try(int k){
   int i;int j;
   if (get_rc(i,j)==true){
   	for (int value=1;value<=16;value++){
   		if (mark[value]==0){
   		grid[i][j]=value;
   	    mark[value]++;
   	    print();
   	    if (checkrow1(i)==true&&checkrow(i)==false) {
   	    		grid[i][j]=0;
   		mark[value]--;
		   return;
	}	   
   		if (checkzero()&&checkgrid()) {
   			print();
		   return;
		}
   		else Try(k);
   		grid[i][j]=0;
   		mark[value]--;
		}
	   }
   }
}


int main(){
	for (int i=0;i<4;i++)
	 for (int j=0;j<4;j++)
	  grid[i][j]=0;
	Try(1);
	print();
}
