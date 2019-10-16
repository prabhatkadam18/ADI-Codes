#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int v, Node *next)
{
  Node *newnode = (Node *)malloc(sizeof(Node *));
  newnode->value = v;
  newnode->next = next;

  return newnode;
}

void insertNode(int v)
{
  Node *newnode = createNode(v, NULL);
  if (head == NULL)
  {
    head = newnode;
  }
  else
  {
    Node *ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = newnode;
  }
}

void printList(Node *head)
{
  Node *ptr = head;
  if (head == NULL)
  {
	printf("NULL");
  }
  //return;
  while (ptr != NULL)
  {
	printf("%d",ptr->value);
	ptr = ptr->next;
  }
  printf("\n");
}


Node *middleOfList()
{
  Node *fast = head, *slow = head;
  if(head==NULL){
    return NULL;
  }
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main()
{
  insertNode(1);
  insertNode(2);
  insertNode(3);
  insertNode(4);
  insertNode(5);
  insertNode(5);
  printList(head);

  printf("\nMiddle: %d\n",middleOfList()->value);
  return 0;
}
