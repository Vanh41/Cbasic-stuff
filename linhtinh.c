#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

typedef struct time{
    int h;
    int m;
    int s;
}time;

typedef struct transaction{
    char from[21];
    int total;
    struct transaction *next;
}node;

typedef struct hashmap{
    node *arr[100001];
}hashmap;

hashmap m;

int hash(char s[]){
    int code=0;
    for (int i=1;i<=strlen(s);i++)
    code=(code*256+s[i-1])%100001;
    return code;
}

node *makenode(char f[]){
    node *p=(node*)malloc(sizeof(node));
    strcpy(p->from,f);
    p->total=0;
    p->next=NULL;
    return p;
}

void insert(char f[],int money){
   int idx=hash(f);
   node *p=makenode(f);
   node *temp=m.arr[idx];
   if (m.arr[idx]==NULL){
        m.arr[idx]=p;
        m.arr[idx]->total=money;
   }
   else {
        while (temp->next!=NULL){
            if (strcmp(temp->from,f)==0) {
                temp->total+=money;
                // free(p);
                return;
            }
            temp=temp->next;
        }
        if (strcmp(temp->from,f)==0) {
            temp->total+=money;
            // free(p);
            return;
        }
        else {
            temp->next=p;
            temp->next->total=money;
            // free(p);
        }
        
   }
}

int totalsac(char f[]){
    int idx=hash(f);
    node *temp=m.arr[idx];
    // if (temp==NULL) return 0;    
    while (temp!=NULL){
        if (strcmp(f,temp->from)==0) {
            int s=temp->total;
            // free(temp);
            return s;
        }
        temp=temp->next;
    }
    // free(temp);
   return 0;
}



void input1(){
    char a[1000],b[1000],c[1000];
    int h,m,s;
    int money;
    while (1){
        scanf("%s",a);
        if (strcmp(a,"#")==0) return;
        scanf("%s %d %d:%d:%d %s",b,&money,&h,&m,&s,c);
        insert(a,money);
    }
}

void input2(){
    char cmd[1000];
    while (1){
        scanf("%s",cmd);
        if (strcmp(cmd,"?total_money_transaction_from")==0) {
            char a[1000];
            scanf("%s",a);
            printf("%d\n",totalsac(a));
    }
    if (strcmp(cmd,"#")==0) return;
    }
}

int main(){
    input1();
    input2();
}
