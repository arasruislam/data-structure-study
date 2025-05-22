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

// Insert at beginning
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

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
  return;
}

void insertAtMiddle(struct Node **head, int data, int position)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;

  if (position == 0)
  {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  for (int i = 0; i < position - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Invalid position\n");
    free(temp);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtBeginning(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty!!!\n");
    return;
  }

  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
  return;
}

void deleteAtEnd(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty!!!\n");
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

void deleteAtMiddle(struct Node **head, int position)
{
  if (*head == NULL)
  {
    printf("List is empty!!!\n");
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

  if (temp == NULL)
  {
    printf("Invalid position!\n");
    return;
  }

  struct Node *nodeToDelete = temp->next;
  temp->next = nodeToDelete->next;
  free(nodeToDelete);
  return;
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

  // testing
  printf("Inserting at beginning:\n");
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 10);
  display(head);

  printf("\nInserting at end:\n");
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  display(head);

  printf("\nInserting at position 2:\n");
  insertAtMiddle(&head, 25, 2); // 10 → 20 → 25 → 30 → 40
  display(head);

  printf("\nDeleting at beginning:\n");
  deleteAtBeginning(&head);
  display(head);

  printf("\nDeleting at end:\n");
  deleteAtEnd(&head);
  display(head);

  printf("\nDeleting at position 2:\n");
  deleteAtMiddle(&head, 2); // 20 → 25 → 30
  display(head);

  return 0;
}