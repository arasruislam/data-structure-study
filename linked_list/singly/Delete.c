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

// Delete the Node
void deleteAtBeginning(struct Node **head)
{
   if(*head == NULL){
      printf("List is empty\n");
      return;
   }

   struct Node *temp = *head;
   *head = temp->next;
   free(temp);
}

void deleteAtEnd(struct Node **head)
{
   if(*head == NULL){
      printf("List is empty\n");
      return;
   }

   struct Node *temp = *head;
   struct Node *prev = NULL;

   while(temp->next != NULL){
      prev = temp;
      temp = temp->next;
   }

   if(prev == NULL){
      *head = NULL;
   }else{
      prev->next = NULL;
   }

   free(temp);
}

void deleteAtMiddle(struct Node **head, int position)
{
   if(*head == NULL){
      printf("List is empty\n");
      return;
   }

   struct Node *temp = *head;
   struct Node *prev = NULL;

   for(int i = 1; i < position; i++){
      if(temp->next == NULL){
         printf("Position not found\n");
         return;
      }
      prev = temp;
      temp = temp->next;
   }

   if(prev == NULL){
      *head = temp->next;
   }else{
      prev->next = temp->next;
   }

   free(temp);
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

   // delete the Node
   // deleteAtBeginning(&head);
   // deleteAtEnd(&head);
   deleteAtMiddle(&head, 2);

   // Print the Node
   display(head);

   // Free the memory
   free(head);
   free(second);
   free(third);

   return 0;
}