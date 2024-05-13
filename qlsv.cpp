#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkpass(char password[1000]){
	if (strlen(password)<6) return false;
	if (strtok(password," ")!=NULL) return false;
	return true;
}

bool checkusername(char username[1000]){
	if (strtok(username," ")!=NULL) return false;
	return true;
}



int main(){
	FILE *fptr1,*fptr2;
	fptr1=fopen("sinhvien.txt","r");
	char username[1000];
	char password[1000];
	float diem;
	char command[1000];
	//command 1
	while (1){
		printf("1. login\n");
		printf("2. quit\n");
		scanf("%s",command);
		if (strcmp(command,"quit")==0) break;
		if (strcmp(command,"login")==0){
			char temp1[1000];
			char temp2[1000];
			int count=0;
			//nhapp tk mk
			while (count<=3){
			printf("username:\n");
			scanf("%s",temp1);
			printf("password:\n");
			scanf("%s",temp2);
			int ok1=0;
			int ok2=0;
			fptr1=fopen("sinhvien.txt","r");
			while (fscanf(fptr1,"%s %s %f",username,password,&diem)!=EOF){
				if (strcmp(temp1,username)==0&&strcmp(temp2,password)==0) {
					ok1=1;
					ok2=1;
					break;
				}
			 }
			if (ok1==1&&ok2==1) break;
			else count++;
			}
		if (count==4) break;
		char command2[1000];
		//command 2
		while(1){
			printf("1. show score\n");
			printf("2. change pass\n");
		scanf("%s",command2);
		if (strcmp(command2,"show")==0) printf("%f\n",diem); //show diem
		if (strcmp(command2,"changepass")==0){
			char temp3[1000];
			char temp4[1000];
			printf("input new password #1:\n");
			scanf("%s",temp3);
			printf("input new password #2:\n");
			scanf("%s",temp4);
			if (strcmp(temp3,temp4)==0) {
				fptr1=fopen("sinhvien.txt","r");
				fptr2=fopen("temp.txt","r+w");
				while (fscanf(fptr1,"%s %s %f\n",username,password,&diem)!=EOF){
					if (strcmp(temp1,username)==0) fprintf(fptr2,"%s %s %f\n",username,temp3,diem);
					else fprintf(fptr2,"%s %s %f\n",username,password,diem);
				}
			}
			fptr1=fopen("sinhvien.txt","w");
			FILE *fptr3=fopen("temp.txt","r");
			while (fscanf(fptr3,"%s %s %f\n",username,password,&diem)!=EOF){
				fprintf(fptr1,"%s %s %f\n",username,password,diem);
			}
		}
		if (strcmp(command2,"quit")==0) break;
		}
		//Admin
		if (strcmp(temp1,"Admin")==0){
			printf("1. show all\n");
			printf("2. add\n");
		 	char command2[1000];
		 	while(1){
		 		scanf("%s",command2);
		 		if (strcmp(command2,"showall")==0){
		 			fptr1=fopen("sinhvien.txt","r");
					while (fscanf(fptr1,"%s %s %f",username,password,&diem)!=EOF){
						if (strcmp(username,"Admin")==0) continue;
						printf("%s %s %f\n",username,password,diem);
					}
					
				 }
				 if (strcmp(command2,"quit")==0) break;
			
			 }
		}
		
		}
	}
	
	
}
