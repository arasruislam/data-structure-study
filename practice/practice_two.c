// Create a Node
// Initisation of Node - NULL
// Allocation the memory for Node
// Assign the value to Node
// Connect the Node
// Print the Node

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void display(struct Node *head)
{
  struct Node *temp = head;

  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

void insertAtBeginning(struct Node **head, int value)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = value;

  newNode->next = *head;
  *head = newNode;
}
void deleteAtBeginning(struct Node **head)
{
  if (*head == NULL)
  {
    printf("The list is empty!!\n");
    return;
  }

  *head = (*head)->next;
  return;
}

void insertAtEnding(struct Node **head, int value)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = value;

  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->next = NULL;
  return;
}
void deleteAtEnding(struct Node **head)
{
  if (*head == NULL)
  {
    printf("The list is empty!!!\n");
    return;
  }

  struct Node *temp = *head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return;
}

void insertAtMiddle(struct Node **head, int value, int position)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = value;

  if (position == 0)
  {
    insertAtBeginning(head, value);
    return;
  }

  struct Node *temp = *head;
  for (int i = 0; i < position - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Invalid input or position\n");
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return;
}

void deleteAtMiddle(struct Node **head, int position)
{
  if (*head == NULL)
  {
    printf("The list is empty!!!\n");
    return;
  }

  if (position == 0)
  {
    deleteAtBeginning(head);
    return;
  }

  struct Node *temp = *head;
  for (int i = 0; i < position - 1 && temp->next != NULL; i++)
  {
    temp = temp->next;
  }

  struct Node *nodeToDelete = temp->next;
  temp->next = nodeToDelete->next;
  free(nodeToDelete);
  return;
}

int main()
{
  struct Node *head = NULL;
  struct Node *first = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  head = malloc(sizeof(struct Node));
  first = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));

  head->data = 0;
  head->next = first;

  first->data = 1;
  first->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  // operation
  // insertAtBeginning(&head, 5);
  // insertAtBeginning(&head, 6);
  // deleteAtBeginning(&head);

  // insertAtEnding(&head, 7);
  // insertAtEnding(&head, 8);
  // deleteAtEnding(&head);

  insertAtMiddle(&head, 9, 2);
  insertAtMiddle(&head, 10, 0);
  display(head);
  printf("-----------\n");
  deleteAtMiddle(&head, 2);

  // display
  display(head);

  return 0;
}