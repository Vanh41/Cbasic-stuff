#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int count=0;

struct list{
  int coefficient;
  int exponent;
  struct list *next;
};
typedef struct list node;

struct pol{
  int poly_id;
  node *polynomial;
  struct pol *tail;
};
typedef struct pol poly; 
poly *head;

node *makenewnode(int coef,int ex){
  node *new =(node*)malloc(sizeof(node));
  new->coefficient=coef;
  new->exponent=ex;
  new->next=NULL;
  return new;
}

poly *makenewpoly(int id){
  poly *new=(poly*)malloc(sizeof(poly));
  new->poly_id=id;
  new->tail=NULL;
  return new;
}

void create(int id){
  poly *new=makenewpoly(id);
  new->tail=head;
  head=new;
}



int main(){
  char command[1000];
}
