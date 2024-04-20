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
    printf("%-20s\t%-15s\t%-25s%-p\n",tmp.name,tmp.tel,tmp.email,p->next);
}

contact readnode(){
    contact tmp;
    printf("Input full name: ");
    fgets(tmp.name,sizeof(tmp.name),stdin);
    printf("Input Tel: ");
    fgets(tmp.tel,sizeof(tmp.tel),stdin);
    printf("Input Email: ");
    fgets(tmp.email,sizeof(tmp.email),stdin);
}

void insertAthead(contact ct){
    node *new=makenewnode(ct);
    new->next=root;
    root=new;
    cur=root;
}

void main(){
    int i;contact tmp;
    for (int i=0;i<2;i++){
        tmp=readnode();
        insertAthead(tmp);
        displayNode(root);
    }
}
