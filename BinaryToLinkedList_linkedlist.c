/* status - not yet done
desc - 14. **Convert Binary Number in a Linked List to Integer** [Easy] - *Why:* Directly reads bit values from a list, simulating data parsing .
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// linked list
typedef struct Node{
    int data;
    struct Node* next;
}node;

// function declearation
void print_linkedlist(node *head);
node* createNode(int data);
void insert_linkedList(node** head,int data);

int main(){
    node* head = NULL;
    insert_linkedList(&head,1);
    insert_linkedList(&head,0);
    print_linkedlist(head);
    
    return 0;
}
// function defination


void insert_linkedList(node** head,int data){
    if(*head == NULL){ // insert head 
        *head = createNode(data);
        return;
    }
    node* temp = *head;
    while(temp->next != NULL){ // insert at the end

        temp = temp->next;
    }
    temp->next = createNode(data);
}

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print_linkedlist(node *head){
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
