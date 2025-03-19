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

// Insert at the middle
// struct Node *insertAtMiddle(struct Node *head, int data, int position)
// {
//    struct Node *fourth;
//    fourth = malloc(sizeof(struct Node));
//    fourth->data = data;

//    struct Node *temp = head;
//    int i = 1;

//    // while (i < position-1)
//    // {
//    //    temp = temp->next;
//    //    i++;
//    // }
//    for (int i = 2; i < position; i++)
//    {
//       if (temp->next != NULL)
//       {
//          temp = temp->next;
//       }
//    }

//    fourth->next = temp->next;
//    temp->next = fourth;

//    return head;
// }

void insertAtMiddle(struct Node **head, int data, int position)
{
   struct Node *fourth;
   fourth = malloc(sizeof(struct Node));
   fourth->data = data;

   struct Node *temp = *head;
   int i = 1;

   for (int i = 2; i < position; i++)
   {
      if (temp->next != NULL)
      {
         temp = temp->next;
      }
   }

   fourth->next = temp->next;
   temp->next = fourth;
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

   // Insert at the middle
   insertAtMiddle(&head, 4, 2);

   // Print the Node
   display(head);

   // Free the memory
   free(head);
   free(second);
   free(third);

   return 0;
}