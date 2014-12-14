/**
   THINH NGUYEN
   Binary Search Tree (ref Introduction to Algorithms CLRS)
 **/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* left;
  struct node* right;
  struct node* parent;
} node;

int createNode(node** newNode, int element, node* parent) {
  *newNode = malloc(sizeof(node));
  if (!(*newNode)) return 0;
  else {
    (*newNode)->value = element;
    (*newNode)->left = NULL;
    (*newNode)->right = NULL;
    (*newNode)->parent = parent;
    return 1;
  }
}

/* insert an element into bst */
int insert(node** root, int element) {
  node* newNode;
  node* current = *root;
  node* parent = NULL;
  
  while (current != NULL) {
    parent = current;
    if (current->value <= element) {
      current = current->right;
    } else {
      current = current->left;
    }
  }

  if(createNode(&newNode, element, parent)) {
    if (parent == NULL) *root = newNode; //if the tree is empty
    else if (parent->value < element) parent->right = newNode;
    else parent->left = newNode;
    return 1;
  } else return 0;

}

/* the the minimum from a particular node */
node* minimum(node* tree) {
  node* min = tree;
  while (min->left != NULL) {
    min = min->left;
  }
  return min;
}

/* find successor of tree*/
node* successor(node* tree) {
  node* ptr = tree;

  if (ptr->right != NULL) {
    return minimum(ptr->right);
  } else {
    node* n = ptr->parent;
    while (n != NULL && n->right == ptr) {
      ptr = n;
      n = n->parent;
    }
    return n;
  }
}

/* replace node x by y. however, must be careful about x's reference */
void transplant(node** root, node* x, node* y) {
  if (x->parent == NULL) //it must be the root
    *root = y;
  else if (x == x->parent->left)
    x->parent->left = y;
  else 
    x->parent->right = y;
  if (y != NULL)
    y->parent = x->parent;
}

/* search an element in tree */
node* search(node* root, int element) {
  node* current = root;
  
  while (current != NULL && current->value != element) {
    if (current->value < element) current = current->right;
    else current = current->left;
  }
  return current;
}

/* delete an element from tree */
int delete(node** root, int element) {
  node* found = search(*root, element);
  if (found == NULL) return 0; //false

  if (found->left == NULL)
    transplant(root, found, found->right);
  else if (found->right == NULL)
    transplant(root, found, found->left);
  else {
    node* suc = successor(found); //finding successor or minimum in this case perform identical due to the above conditions. The book uses minimum
    if (suc->parent != found) {
      transplant(root, suc, suc->right);
      suc->right = found->right;
      suc->right->parent = suc;
    }
    transplant(root, found, suc);
    suc->left = found->left;
    suc->left->parent = suc;
    free(found); //finally, you are a free man, !DELETE IT;
  }
  return 1;
}

/* in order tree traversal */
void printTree(node* root) {
  if (root == NULL) printf("E");
  else {
    printTree(root->left);
    printf("%d", root->value);
    printTree(root->right);
  }
}

/* TEST DRIVE*/
int main() {
  int insertElement[11] = {12, 7, 17, 5, 10, 9, 8, 11, 15, 16, 18};
  node* root = NULL;
  for (int i = 0; i < 11; i++) {
    insert(&root, insertElement[i]);
  }
  printTree(root);
  printf("\n");
  
  printf("------Search------\n");
  node* found = search(root, 14);
  printTree(found);
  printf("\n");

  printf("-----Find successor---\n");
  node* n = search(root, 11);
  node* s = successor(n);
  printf("%d\n",s->value);
  
  printf("-----DELETE--------\n");
  printTree(root);
  printf("\n");
  delete(&root, 12);
  //delete(&root, 9);
  printTree(root);
  printf("\n");
  return 0;
}


