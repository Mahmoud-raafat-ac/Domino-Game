#ifndef board
#define board

#include "playerandcomp.h"
 
struct Node* head = NULL;

// A linked list node
struct Node
{
    
    int data1,data2;
    Node* next=NULL;
    Node* prev=NULL;
};
 
/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void push( int new_data1,int new_data2,int data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    if(data==1)
    {
     new_node->data1 = new_data1;
     new_node->data2 = new_data2;
    }
    else 
    {
     new_node->data1 = new_data2;
     new_node->data2 = new_data1;
    }
    /* 3. Make next of new node as head
    and previous as NULL */
    new_node->next = head;
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if (head != NULL)
        head->prev = new_node;
 
    /* 5. move the head to point to the new node */
    head = new_node;
}
 
/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append( int new_data1,int new_data2,int data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    Node* last = head; /* used in step 5*/
 
    /* 2. put in the data */
    if(data==0)
    {
    new_node->data1 = new_data1;
    new_node->data2 = new_data2;
    }
    else
     {
         new_node->data1 = new_data2;
    new_node->data2 = new_data1;
    }
    /* 3. This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
        node as head */
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
 
    
}
 
// This function prints contents of
// linked list starting from the given node
void printList()
{
    Node* last;
    while (head != NULL)
    {
        cout<<" "<<head->data1<<" | "<<head->data2<<endl;
        last = head;
        head = head->next;
    }
}
void deleteAllNodes() \
{
  //1. create a temp node
  Node* temp = new Node();
  
  //2. if the head is not null make temp as head and 
  //   move head to head next, then delete the temp,
  //   continue the process till head becomes null
  while(head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}


#endif 