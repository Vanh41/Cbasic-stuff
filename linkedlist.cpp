#include <stdio.h>
#include <stdlib.h>

typedef struct contact_t
{
        char name[20];
        char tel[11];
        char email[25];
}contact;
struct list_el{
       contact el;
       struct list_el *next;
};
typedef struct list_el node ;

node *root,*cur;
node *prev;
node *makenewnode(contact ct){
    node *new = (node*)malloc(sizeof(node));
    new->el=ct;
    new->next=NULL;
    return new;
}
void displayNode(node*p){
    if (p==NULL) {
        printf("NULL pointer error.\n");
        return ;
    }
    contact tmp=p->el;
    printf("\t%-15s\t%-15s\t%-15s%-p\n",tmp.name,tmp.tel,tmp.email,p->next);
}

contact readnode(){
    contact tmp;
    printf("Input full name: ");
    fgets(tmp.name,20,stdin);
    printf("Input Tel: ");
    fgets(tmp.tel,11,stdin);
    printf("Input Email: ");
    fgets(tmp.email,25,stdin);
    return tmp;
}

void insertAthead(contact ct){
    node *new=makenewnode(ct);
    new->next=root;
    root=new;
    cur=root;
}
void insertaftercur (contact ct){
    node *new=makenewnode(ct);
    if (root==NULL) {
        root=new;
        cur=root;
    }
    else if (cur==NULL) return;
    else {
    new->next=cur->next;
    cur->next=new;
    cur=cur->next;
    }
}
void deletefirstelement(){
    node* del=root;
    if (del==NULL) return;
    root=del->next;
    free(del);
    cur=root;
    prev=NULL;
}

void main(){
    int i;contact tmp;
    for (int i=0;i<2;i++){
        tmp=readnode();
        root=makenewnode(tmp);
        displayNode(root);
    }
}
