#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *prev;
  struct Node *next;
} Node;


Node *head = NULL;

Node *createNode(int v,Node* prev, Node *next)
{
  Node *newnode = (Node *)malloc(sizeof(Node *));
  newnode->value = v;
  newnode->prev=prev;
  newnode->next = next;
  return newnode;
}

void insertEnd(int v,Node **head)
{
  Node *newnode=(Node *)malloc(sizeof(Node *));
  if (*head == NULL){
    newnode = createNode(v, NULL , NULL);
    *head = newnode;
  }
 
  else{
    Node *ptr = *head;
    while (ptr->next!= NULL){
      ptr = ptr->next;
    }
    newnode = createNode(v, ptr , NULL);
    ptr->next = newnode;
  }
}

void printList(Node *head)
{
  Node *ptr = head;
  if (head == NULL)
  {
    return;
  }
  while (ptr != NULL)
  {
  	printf("%d",ptr->value);
	  ptr = ptr->next;
  }
  printf("\n");
}

void addFirstLastRec(Node* node, Node** np){
  if(node->next==NULL){
    insertEnd(node->value, np);
  }
  else{
    addFirstLastRec(node->next,np);
    insertEnd(node->value,np);
  }
  
}

Node* addFirstLast(Node *head){
  Node *newLL = NULL;
  Node *tmp=NULL;
  addFirstLastRec(head,&tmp);

  int count=0;
  Node* ptr=head,*ptr2=tmp;
  while(ptr!=NULL){
    count++;
    ptr=ptr->next;
  }
  ptr = head;
  ptr2=tmp;
  for(int i=0;i<count/2;i++){
    insertEnd(ptr->value+ptr2->value,&newLL);
    ptr2=ptr2->next;
    ptr=ptr->next;
  }
  if(count%2){
    insertEnd(ptr->value,&newLL);
  }
  return newLL;
}


int main()
{
  insertEnd(1,&head);
  insertEnd(2,&head);
  insertEnd(3,&head);
  insertEnd(4,&head);
  insertEnd(5,&head);


  printList(head);

  Node* newLL = addFirstLast(head);
  printList(newLL);
  
  return 0;
}
