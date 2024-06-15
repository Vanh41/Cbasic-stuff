#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int n;
unsigned int a[100001]={0};

typedef struct hashnode{
    int key;
    struct hashnode *next;
}node;

node *makenode(int k){
    node *p=(node*)malloc(sizeof(node));
    p->key=k;
    p->next=NULL;
    return p;
}

typedef struct hashmap{
    node *arr[100001];
}hashmap;

void init(hashmap *map){
    for (int i=0;i<100001;i++) map->arr[i]=NULL; 
}

unsigned int hashfunction(unsigned int val){
    return val%10000;
}

void insert(hashmap *map,unsigned int val){
    unsigned int idx=hashfunction(val);
    node *p=makenode(val);
    if (map->arr[idx]==NULL) map->arr[idx]=p;
    else {
        node *temp=map->arr[idx];
        while (temp->next!=NULL) temp=temp->next;
        temp->next=p;
    }
}

int find(hashmap *map,unsigned int val){
    unsigned idx=hashfunction(val);
    node *temp=map->arr[idx];
    while (temp!=NULL){
        if (temp->key==val) return 1;
        temp=temp->next;
    }
    return 0;
}



int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    hashmap map;
    init(&map);
    insert(&map,a[0]);
    printf("0\n");
    for (int i=1;i<n;i++){
        printf("%d\n",find(&map,a[i]));
        insert(&map,a[i]);
    }
}
