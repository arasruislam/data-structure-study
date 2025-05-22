// Create a Node
// Initisation of Node
// Allocation the memory for Node
// Assign the value to Node
// Connect the Node
// Print the Node

#include <stdio.h>
#include <stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

// Display the Node
// void display(struct Node *head){
//    struct Node *temp = head;
//    while(temp != NULL){
//       printf("%d\n", temp->data);
//       temp = temp->next;
//    }
// }

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

   // Print the Node
   struct Node *temp = head;
   while(temp != NULL){
      printf("%d\n", temp->data);
      temp = temp->next;
   }
   // display(head);

   // Free the memory
   free(head);
   free(second);
   free(third);

   return 0;
}