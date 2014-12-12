#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node* next;
} node;

int createStack(node** stack) {
  *stack = NULL;
  return 1;
}

/* add element to the front of stack */
int push(node** stack, int data) {
  printf("Push %d\n", data);
  node* newNode = malloc(sizeof(node));
  if (!newNode) {
    return 0;
  }

  //add element to front
  node* head = *stack;
  newNode->data = data;
  newNode->next = head;
  *stack = newNode;
  return 1;
}

/* pop first element out of stack */
int* pop(node** stack) {
  node* head = *stack;
  if (head == NULL) return NULL;
  
  *stack = (*stack)->next;
  int* popValue = &(head->data);
  free(head);
  printf("Pop %d\n", *popValue);
  return popValue;
}

int deleteStack(node** stack) {
  printf("delete stack\n");
  node* head = *stack;
  
  while (*stack) {
    free(head);
    head = (*stack)->next;
    *stack = head;
  }
  return 1;
}

void printStack(node* stack) {
  node* head = stack;
  if (head == NULL)
    printf("EMPTY\n");
  else {
    while (head != NULL) {
      printf("%d\n", head->data);
      head = head->next;
    }
  }
}

int main() {
  node* stack;
  createStack(&stack);
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 23);
  push(&stack, 24);
  printStack(stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  printStack(stack);
  push(&stack, 1);
  push(&stack, 32);
  push(&stack, 43);
  printStack(stack);
  deleteStack(&stack);
  printStack(stack);
  return 0;
}

