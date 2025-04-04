#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

void printlist(node *p){
    while (p != NULL){
        printf("%2d",p->val);
        p = p->next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    for (int n = 1; n <= 10; n++){
        node* nnode = malloc(sizeof(node));
        nnode->val = n;
        nnode->next = NULL;
        if (head == NULL){
            head = nnode;
            tail = nnode;
        }else{
            tail->next = nnode;
            tail = nnode;
        }
    }
    printlist(head);
    return 0;
}