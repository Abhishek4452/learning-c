/* status - not yet complete
description -Reverse Linked List** [Easy] - *Why:* The quintessential pointer exercise. If you can't reverse a list, you don't fully understand pointers
*/
#include <stdio.h>
#include <stdlib.h>
// function declaration
typedef struct Node{
    int data;
    struct Node* next;
}node;
node* create_node(int data);
void insert_element(node** head,int data);
void print_linkedList(node* head);
void delete_linkedList(node** head,int key);
node* reverse_linkedlist(node** head);
int main(){
    node* head = NULL;
    insert_element(&head,25);
    insert_element(&head,2);
    insert_element(&head,29);
    insert_element(&head,40);
    insert_element(&head,93);
    insert_element(&head,37);
    print_linkedList(head);
    node* head2 = NULL;
    head2 = reverse_linkedlist(&head);
    printf("reversing string \n");
    print_linkedList(head2);
    return 0;
}
// ====================== function defination =======================

node* create_node(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insert_element(node** head,int data){
    node* newNode = create_node(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node* temp_head = *head;
    while(temp_head->next != NULL){
        temp_head = temp_head->next;
    }
    temp_head->next = newNode;
}

void print_linkedList(node* head){
    node* temp_head = head;
    while(temp_head != NULL){
        printf("%d ->",temp_head->data);
        temp_head= temp_head->next;
    }
    printf("NULL \n");
}

void delete_linkedList(node** head,int key){
    node* temp_prev = NULL; // need to be null
    node* temp = *head;
    if (*head == NULL){  // empty case .
        return;
    }


    if(temp->data == key){ //head to be delete
        *head = temp->next;
        free(temp);
        return;
    }

    // search case
    while((temp != NULL) && (temp->data != key) ){
        temp_prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){  // not found case
        return;
    }

    // if element is found in between 
    temp_prev->next = temp->next;
    free(temp);
    
}

node* reverse_linkedlist(node** head){
    //Reverse the links (pointers) between nodes
    node *temp_prev = NULL;
    node *curr = *head;
    node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = temp_prev;
        temp_prev = curr;
        curr = next;   
    }
    *head = temp_prev;
    return temp_prev;
}
