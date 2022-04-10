#include <pthread.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum {food, drink, bag} description;

typedef struct {
    unsigned int barcode;
    description desc;
    double price;
} product;

typedef struct node{
    product p;
    node* next;
} node;

void copyProduct(product* pr1, product* pr2){
    pr1->barcode = pr2->barcode;
    pr1->desc = pr2->desc;
    pr1->price = pr2->price;
};

void push(node** head, product* val){
    node* new = (node*) malloc(sizeof(node));
    copyProduct(&(new->p), val);
    new->next = *head;
    *head = new;
}

int pop(node** head, product* result){
    if(*head == NULL){
        return -1;
    }
    else{
        node* current = *head;
        *head = current->next;
        copyProduct(result, &(current->p));
        free(current);
        return 0;
    }
}


