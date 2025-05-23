#include <stdio.h>

#define MAX 5

struct Stack
{
  int data[MAX];
  int top;
};

void init(struct Stack *s)
{
  s->top = -1;
}

int isEmpty(struct Stack *s)
{
  return s->top = -1;
}

int isFull(struct Stack *s)
{
  return s->top = MAX - 1;
}

void push(struct Stack *s, int value)
{
  if (isFull(s))
  {
    printf("stack Overflow\n");
    return;
  }

  s->top++;
  s->data[s->top] = value;
}

void pop(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack Underflow\n");
    return;
  }
  int value = s->data[s->top];
  s->top--;
  return value;
}

int peek(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack empty\n");
    return -1;
  }

  return s->data[s->top];
}

void display(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty!\n");
    return;
  }
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d ", s->data[i]);
  }
  printf("\n");
}

int main()
{

  return 0;
}