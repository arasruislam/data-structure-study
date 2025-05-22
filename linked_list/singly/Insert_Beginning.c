#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

// Display the Node
void display(struct Node *head)
{
   struct Node *temp = head;
   while (temp != NULL)
   {
      printf("%d\n", temp->data);
      temp = temp->next;
   }
}

// Insert at the beginning
// struct Node *insertAtBeginning(struct Node *head, int data)
// {
//    struct Node *newNode = malloc(sizeof(struct Node));
//    newNode->data = data;
//    newNode->next = head;
//    head = newNode;
//    return head;
// }

void insertAtBeginning(struct Node **head, int data)
{
   struct Node *newNode = malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = *head;
   (*head) = newNode;
}

int main()
{
   // Create a Node
   struct Node *head = NULL;
   struct Node *second = NULL;
   struct Node *third = NULL;

   // Allocate the memory for Node
   head = malloc(sizeof(struct Node));
   second = malloc(sizeof(struct Node));
   third = malloc(sizeof(struct Node));

   // Assign the value to Node & connect the Node
   head->data = 1;
   head->next = second;

   second->data = 2;
   second->next = third;

   third->data = 3;
   third->next = NULL;

   // insert at the beginning
   // struct Node *fourth;
   // fourth = malloc(sizeof(struct Node));
   // fourth->data = 4;
   // fourth->next = head;
   // head = fourth;

   // head = insertAtBeginning(head, 4);
   insertAtBeginning(&head, 4);

   // Print the Node
   display(head);

   // Free the memory
   free(head);
   free(second);
   free(third);

   return 0;
}