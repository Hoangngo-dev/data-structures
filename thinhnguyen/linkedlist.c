/* 
Thinh Nguyen
LinkedList implementation 
*/

#include <stdio.h>
#include <stdlib.h>

/* Definition of linkedlist */
typedef struct node 
{
  int val;
  struct node* next;
} node;

/* create new node */
node* createNode(int element) {
  node* newNode = malloc(sizeof(node));
  if (!newNode) {
    printf("Malloc Failed");
  }

  newNode->val = element;
  newNode->next = NULL;
  return newNode;
}

/* search element in list */
node* search(node** head, int element) {
  if (*head == NULL) return NULL;
  node* pointer = *head;
  while (pointer != NULL && pointer->val != element) {
    pointer = pointer->next;
  }
  return pointer;
}

/* add element to end of list */
void addTail(node** head, int element) {
  if (*head == NULL) {
    *head = createNode(element);
  } else {
    node* pointer = *head;
    while (pointer->next != NULL) {
      pointer = pointer->next;
    }
    pointer->next = createNode(element); 
  }
}

/* add element to begin of list */
void addHead(node** head, int element) {
  if (*head == NULL) {
    *head = createNode(element);
  } else {
    node* newNode = createNode(element);
    newNode->next = *head;
    *head = newNode;
  }
}

int delete(node** head, int element) {
  if (*head == NULL) return 0;
  node* headPtr = *head;
  if (headPtr->val == element) {
    *head = headPtr->next;
    free(headPtr);
    return 1;
  } else {
    node* searchPtr = headPtr->next;
    node* prevPtr = headPtr;
    
    while (searchPtr != NULL && searchPtr->val != element) {
      searchPtr = searchPtr->next;
      prevPtr = prevPtr->next;
    }

    if (searchPtr == NULL) return 0; //could not find element in list
    else {
      node* nextPtr = searchPtr->next;
      free(searchPtr); //delete the current node
      prevPtr->next=nextPtr;
      return 1;
    }
  }
}

/* print out the list */
void printList(node* head) 
{
  if (head == NULL) printf("NULL\n");
  node* pointer = head;
  
  while (pointer != NULL) 
  {
    printf("%d\n", pointer->val);
    pointer = pointer->next;
  }
}

int main() {
  node* list = NULL;
  addHead(&list, 40);
  addTail(&list, 12);
  addTail(&list, 20);
  addHead(&list, 30);
  printList(list);
  printf("Delete\n");
  delete(&list, 20);
  delete(&list, 40);
  delete(&list, 30);
  delete(&list, 21);
  //delete(&list, 12);
  delete(&list, 20);
  printList(list);
  printf("------Search----\n");
  node* found = search(&list, 12);
  printList(found);
  return 0;
}
