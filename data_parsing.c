/* status -
description - Convert Binary Number in a Linked List to Integer** [Easy] - 
*Why:* Directly reads bit values from a list, simulating data parsing .
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int32_t linkedlist_size = 0;
typedef struct node{
    int32_t value;
    struct node* next;
}Node;

Node *createNode(int32_t data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}
void deleteHead(Node** head){
    if(head == NULL || *head == NULL){
        printf("linked list empty \n");
        return;
    } // if head is empty

    Node* temp = *head;
    *head = (*head)->next;
    printf("deleting head node : %d \n",temp->value);
    free(temp);
    linkedlist_size--;
}

void freeLinkedList(Node** head){
    Node* temp = *head;
    Node* temp_prev = NULL;
    while(temp != NULL){
        temp_prev = temp;
        temp = temp->next;//for traversing
        free(temp_prev);
    }
    //free(temp_prev);
    linkedlist_size =0;
}

void insertEnd(Node** head,int32_t data){ // insert at end
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode; 
        return;
    }
    Node* temp = *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    linkedlist_size++;
}

void printLinkedList(Node* head){
    Node* temp = head; // temperory pointer
    while(temp != NULL){  // traversing 
        printf("%d",temp->value);
        printf("\n");
        temp = temp->next;  // incrementing pointer
    }
}

int32_t parsing_linkedlist(Node* head){
    if(head == NULL){ //empty case
        return 0;
    }
    Node* temp = head;
    int32_t temp_size = linkedlist_size;
    int32_t value_decimal = 0;
    while (temp != NULL) {
        // Shift existing result to the left (multiply by 2) 
        // and add the current bit (OR operation)
        value_decimal = (value_decimal << 1) | temp->value;
        temp = temp->next;
    }
    return value_decimal;
}


int main(){
    Node* head = NULL;
    insertEnd(&head,1);
    insertEnd(&head,0);
    insertEnd(&head,1);
    printLinkedList(head);

    // begin body 
    printf("%d is linked list size \n",linkedlist_size);

    int a = parsing_linkedlist(head);
    printf("value in decimal : %d \n",a);
    // end body
    
    
    freeLinkedList(&head);
    return 0;
}