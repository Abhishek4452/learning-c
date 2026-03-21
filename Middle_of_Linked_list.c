/* Aim - To understand the implementation of the linked list
*/

#include <stdio.h>
#include <stdlib.h>
/* ============================== variable =================================*/
int node_count =0;
/* ==========================  function decleration ============================*/

typedef struct Node{ // creating node
    int data;
    struct Node* next; // what's differece btw the node* ,*node
}node;
node* createNode(int data);// creating a new Node
void insert_end(node** head,int data);// inserting new node at end
void print_linkedlist(node *head); 
void linked_list_middle(node* head);
// ============================== MAIN BODY ============================
int main(){
    node * head = NULL;
    insert_end(&head,10);
    insert_end(&head,20);
    insert_end(&head,30);
    insert_end(&head,60);
    insert_end(&head,90);
    insert_end(&head,34);
    insert_end(&head,126);
    insert_end(&head,234);
    print_linkedlist(head);
    linked_list_middle(head);
    return 0;
}

// ======================== functions defination ============================
// creating a new Node
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode ->next = NULL;
   
    return newNode;
}
// inserting new node at end
void insert_end(node** head,int data){
    
    node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next != NULL){
        // traverse till null
        temp = temp->next;
    }

    temp->next = newNode;
    

}

void print_linkedlist(node *head){
    node* temp = head; 
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void linked_list_middle(node* head){ //two pointer approach
    node* mid_temp = head;
    node* temp = head;
    int k=0;
    while(temp != NULL){
        k++;
        if(k%2 == 0){ //find the middle
            
            mid_temp = mid_temp->next;
        }
        temp = temp->next;
        
    }
    
    printf("middle value of linked list is : %d \n",mid_temp->data);
}