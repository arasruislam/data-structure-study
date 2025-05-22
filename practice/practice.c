#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

// Display
void display(struct Node *head)
{
  struct Node *temp = head;

  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main()
{
  // node initialization
  struct Node *head = NULL;
  struct Node *first = NULL;
  struct Node *second = NULL;

  // memory allocation
  head = malloc(sizeof(struct Node));
  first = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));

  // assign the value & Node
  head->data = 0;
  head->next = first;

  first->data = 1;
  first->next = second;

  second->data = 2;
  second->next = NULL;

  display(head);

  return 0;
}