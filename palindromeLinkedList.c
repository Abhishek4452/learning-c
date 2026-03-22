/* status - DONE
title - 13. **Palindrome Linked List** [Easy] - *Why:* Combines finding a middle node and reversing a list .
learning  - the createdlinekd list are yet not deleted . so system failure may occur.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
} node;
// ==================================== function decleration ===============================
node* createNode(int data);
void insert_node_end(node** head,int data);
void delete_linkedList(node** head,int data);
node* reverseLinedlist(node *head);
void Palindrome_check(node* head);
void print_linkedlist(node *head);
void free_linkedList(node** head);
int main(){
    node* head = NULL;
    insert_node_end(&head,2);
    insert_node_end(&head,1);
    insert_node_end(&head,1);
    print_linkedlist(head);
    Palindrome_check(head);

    return 0;
}
// ==================================== function defination ===============================
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert_node_end(node** head,int data){
    
    node* newNode = createNode(data);
    if(*head == NULL){ // insert at head
        *head = newNode;
        return; // exit from the linked list
    }
    node* temp_node = *head;
    while(temp_node->next != NULL){ // traverse till end
        temp_node = temp_node->next;
    }
    temp_node->next = newNode;
    

}
void delete_linkedList(node** head,int data);
node* reverseLinedlist(node *head){
    
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void Palindrome_check(node* head){
    node* temp_head = head;
    node* temp_rev = reverseLinedlist(head);
    
    while(temp_head != NULL){
        if(temp_head->data != temp_rev->data){
            printf("the linked list is not a valid palindrome linked list \n");
            free_linkedList(&temp_rev);
            return;
        }
        temp_head = temp_head->next;
        temp_rev = temp_rev->next;
    }
    printf("the linked list is a palindrome linked list \n");
    free_linkedList(&temp_rev);
}
void print_linkedlist(node *head){
    node* temp = head; 
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
void free_linkedList(node** head){

    if(head == NULL) return;
    node* temp_node ;
    while(*head != NULL){
        temp_node = *head;
        *head =(* head)->next;
        free(temp_node);

    }
}
