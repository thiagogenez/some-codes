//
//  reverse-linked-list.c
//  
//
//  Created by Thiago Genez on 10/6/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next;
    int value;
}node;

void insert_front(node **head, int value){
    node *aux = (node *) malloc(1*sizeof(node));
    aux->value = value;
    aux->next = (*head);
    (*head) = aux;
}

void print(node **head){
    if((*head) != NULL){
        printf("%d, ",(*head)->value);
        print(&(*head)->next);
    }
}

node *reverse_iterative(node *head){
    node *new_head = NULL;
    while(head != NULL){
    	node *tmp = head->next;
	head->next = new_head;
	new_head = head;
	head = tmp;
    }
    return new_head;
}

node* reverse_recursive(node *head, node *previous){
    if(head == NULL){
        return previous;
    }
    node *tmp = head->next;
    head->next = previous;
    return reverse_recursive(tmp, head);
}

int main(void){
    int i = 0;
    node *head = NULL;
    
    for(i = 0; i <= 10; i++)
        insert_front(&head,i);
    
    printf("Linked list: ");
    print(&head);
    printf("\n");
    
    head = reverse_recursive(head,NULL);
    printf("Recursive reverse linked list: ");
    print(&head);
    printf("\n");
    
    head = reverse_iterative(head);
    printf("Recursive iterative linked list: ");
    print(&head);
    printf("\n");
}
