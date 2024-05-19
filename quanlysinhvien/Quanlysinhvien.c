#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

struct list{
    char username[100];
    char password[100];
    float point;
    struct list *next;
};
typedef struct list node;

node *head;
node *cur;

node *makenode(char acc[100], char pass[100], float p){
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->username,acc);
    strcpy(newnode->password,pass);
    newnode->point=p;
    newnode->next=NULL;
    return newnode;
}

void addlist(char acc[100], char pass[100], float p){
    node *new=makenode(acc,pass,p);
    new->next=head;
    head=new;
}

void generatelist(){
    FILE *fptr=fopen("sinhvien.txt","r+w");
    char acc[100];
    char pass[100];
    float p;
    while(fscanf(fptr,"%s %s %f",acc,pass,&p)!=EOF){
        addlist(acc,pass,p);
    }
    fclose(fptr);
}



void printsolution(){
    node *tmp;
    tmp=head;
    while(tmp != NULL){
        printf("%s %s %f\n",tmp->username,tmp->password,tmp->point);
        tmp=tmp->next;
    }
}

void printscore(){
    node *tmp;
    tmp=head;
    while(tmp != NULL){
        if (strcmp(tmp->username,"Admin")!=0){
        printf("%s %s %f\n",tmp->username,tmp->password,tmp->point);
        tmp=tmp->next;
        }
        else tmp=tmp->next;
    }
}

void addstudent(){
    char acc[100],pass[100];
    float point;
    printf("Input username:\n");
    scanf("%s",acc);
    printf("Input password:\n");
    scanf("%s",pass);
    printf("Input student point:\n");
    scanf("%f",&point);
    addlist(acc,pass,point);
    system("clear");
    printf("Add student successfully\n");
}

node *check(char acc[100],char pass[100]){
    node *traverse=head;
    while (traverse!=NULL){
        if (strcmp(traverse->username,acc)==0&&strcmp(traverse->password,pass)==0) return traverse;
        else traverse=traverse->next;
    }
    return NULL;
}


bool checkpass(char password[100]){
	if (strlen(password)<6) return false;
	if (strtok(password," ")!=NULL) return false;
	return true;
}

void changepass(){
    char temp1[100],temp2[100];
    printf("Input new password: \n");
    scanf("%s",temp1);
    printf("Repeat new password: \n" );
    scanf("%s",temp2);
    if (strcmp(temp1,temp2)!=0) {
        system("clear");
        printf("The new password is invalid\n");
        return;
    }
    if (strcmp(temp1,temp2)==0){
        system("clear");
        printf("Password changed successfully\n");
        strcpy(cur->password,temp1);
        return;
    }
}



void login(){
    int count=0;
    while (count<=3){
        char username[100];
        char password[100];
        printf("Username: \n");
        scanf("%s",username);
        printf("Password: \n");
        scanf("%s",password);
        // check valid 
        if (checkpass(password)==false) {
            system("clear");
            printf("Invalid password\n");
            count++;
        }
        node *temp=check(username,password);
        if (temp==NULL) {
            system("clear");
            printf("Invalid username or password\n");
            count++;
        } 
        if (temp!=NULL){
            system("clear");
            printf("Login successfully\n");
            cur=temp;
            return;
        }

    }
}

void studentmode(){
    while(1){
    printf("1. Show score \n");
    printf("2. Change password \n");
    printf("3. Save and quit \n");
    int n;
    scanf("%d",&n);
    if (n==1) {
        system("clear");
        printf("%.2f\n",cur->point);
        int k;
        printf("1. Quit\n");
        scanf("%d",&k);
        if (k==1) {
            system("clear");
            continue;
        }
    }
    if (n==3) {
        system("clear");
        return;
    }
    if (n==2) {
        system("clear");
        changepass();
    }
    }
}

void adminmode(){
    while (1){
        printf("1. Add student\n");
        printf("2. Print all score\n");
        printf("3. Delete student\n");
        printf("4. Save and quit\n");
        int n;
        scanf("%d",&n);
        if (n==4) {
            system("clear");
            return;
        }
        if (n==2){
            system("clear");
            printscore();
            int k;
            printf("1. Quit\n");
            scanf("%d",&k);
            if (k==1) {
            system("clear");
            continue;
        }
        }
        if (n==1){
            system("clear");
            addstudent();
        }
    }
}




int main(){
    system("clear");
    generatelist();
    while (1){
        // menu 
        int n;
        printf("1. LOGIN \n");
        printf("2. QUIT \n");
        scanf("%d",&n);
        //quit command
        if (n==2) {
            system("clear");
            break;
        }
        //log command
        if (n==1){
            system("clear");
            login();
            getchar();
            //studentmode();
            adminmode();

        }
        else {
            system("clear");
            break;
        }
    }
    printsolution();
    return 0;
}