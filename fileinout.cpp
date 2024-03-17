#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  FILE *fptr1,*fptr2;
  fptr1=fopen("temp.txt","r");
  fptr2=fopen("bangdiem.txt","w");
 char student_id[100];
 char phonenumber[20];
 char name[1000];
 int count;
 int score;
 while (fscanf(fptr1,"%d %s %s %s",&count,student_id,name,phonenumber)!=EOF){
 	scanf("%d",&score);
 	fprintf(fptr2,"%d %s %s %s %d\n",count,student_id,name,phonenumber,score);
 }
fclose(fptr1);
fclose(fptr2);
}
