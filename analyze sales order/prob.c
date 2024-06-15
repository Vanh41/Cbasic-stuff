#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct time{
    int hour;
    int minute;
    int second;
}time;


typedef struct node{
    char CustomerID[20];
    char ProductID[20];
    int price;
    char ShopID[20];
    time TimePoint;
    struct node *next;
}node;

node *root;
int count=0;

node *makenode(char a[],char b[],int c,char d[],time e){
    node *p=(node*)malloc(sizeof(node));
    strcpy(p->CustomerID,a);
    strcpy(p->ProductID,b);
    p->price=c;
    strcpy(p->ShopID,d);
    p->TimePoint=e;
    p->next=NULL;
    return p;
}

void addlist(char a[],char b[],int c,char d[],time e){
    node *p=makenode(a,b,c,d,e);
    p->next=root;
    root=p;
}

int totalorders(){
    return count;
}

int totalrevenue(){
    node *temp=root;
    int total=0;
    while (temp!=NULL){
        total+=temp->price;
        temp=temp->next;
    }
    return total;
}

int revenueofshop(char s[]){
    node *temp=root;
    int total=0;
    while (temp!=NULL){
        if (strcmp(temp->ShopID,s)==0) total+=temp->price;
        temp=temp->next;
    }
    return total;
}

int totalconsume(char cus[],char shop[]){
    node *temp=root;
    int total=0;
    while (temp!=NULL){
        if(strcmp(temp->ShopID,shop)==0&&strcmp(temp->CustomerID,cus)==0) total+=temp->price;
        temp=temp->next;
    }
    return total;
}

bool check(time a,time b,time c){
    int as=a.hour*60*60+a.minute*60+a.second;
    int bs=b.hour*60*60+b.minute*60+b.second;
    int cs=c.hour*60*60+c.minute*60+c.second;
    if (as<=cs&&cs<=bs) return true;
    return false;
}

int totalrevenueinperiod(time a,time b){
    node *temp=root;
    int total=0;
    while (temp!=NULL){
        if (check(a,b,temp->TimePoint)==true) total+=temp->price;
        temp=temp->next;
    }
    return total;
}

void input1(){
    char a[20],b[20],d[20];
    int c;
    int h,m,s;
    time e;
    while(1){
        scanf("%s",a);
        if (strcmp(a,"#")==0) return;
        scanf("%s %d %s %d:%d:%d",b,&c,d,&h,&m,&s);
        e.hour=h;
        e.minute=m;
        e.second=s;
        addlist(a,b,c,d,e);
        count++;
    }
}

int sol[100001]={0};
int idx=0;

void input2(){
    char command[100];
    while(1){
        scanf("%s",command);
        if (strcmp(command,"?total_number_orders")==0) sol[idx++]=totalorders();
        else
        if (strcmp(command,"?total_revenue")==0) sol[idx++]=totalrevenue();
        else
        if (strcmp(command,"?revenue_of_shop")==0){
            char temp[100];
            scanf("%s",temp);
            sol[idx++]=revenueofshop(temp);
        }
        else
        if (strcmp(command,"?total_consume_of_customer_shop")==0){
            char cus[100],shop[100];
            scanf("%s %s",cus,shop);
            sol[idx++]=totalconsume(cus,shop);
        }
        else
        if (strcmp(command,"?total_revenue_in_period")==0){
            time a;
            time b;
            scanf("%d:%d:%d %d:%d:%d",&a.hour,&a.minute,&a.second,&b.hour,&b.minute,&b.second);
            sol[idx++]=totalrevenueinperiod(a,b);
        }
        else if (strcmp(command,"#")==0) return;
    }
}

int main(){
    input1();
    input2();
    for (int i=0;i<idx;i++) printf("%d\n",sol[i]);
}
