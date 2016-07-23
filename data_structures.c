#include <stdio.h>
#include <stdlib.h> // provides free, malloc funcs
#include <string.h> // gives strdup func
#include <assert.h>

typedef struct Node {
  /* This LinkedList node stores a int data and a ptr to the next Node struct */ 
  int data;
  Node struct Node *next;
} Node;

typedef struct LinkedList {
  Node head;
} LinkedList;


int LinkedList_add(LinkedList *list_ptr, int value) {
  if (*list_ptr->head->data == NULL) {
    *list_ptr->head = value;
    return 0; 
  } else {
    node = *list_ptr->head
    while (node->next != NULL) {
      node = node->next;
    } 
    new_node = Node;
    new_node->data = value;
    new_node->next = NULL;
    node->next = new_node;
}  
  return 0;
}


/* Binary Search Trees 
   Need a different Node structure with pointers to left and right
   Methods include:
      search
      delete
      insert
*/

typedef struct BSTNode {
  int key; // comparable key - make it an int
  BSTNode struct BSTNode *left;
  BSTNode struct BSTNode *right;
} BSTNode;


int BST_search(int value, BSTNode *node)
{
  // if tree empty or no such value, return 0, else 1
  if(node->key == NULL) {
    return 1; } 
  else if (node->key == value) {
    return 0; }
  else if (node->key < value) {
    search(value, node->right); }
  else {
    search(value, node->left);}
    
  return 1;
}

int BST_insert(int value, BSTNode *tree)
{
  // given a value and a pointer to a Binary Search Tree, insert the value
  // return 0 if successful, 1 otherwise. 
  // The updated (or not, if return 1) tree 
  // will be available at the same pointer address
  assert(tree != NULL); 
  
}

int main(int argc, char *argv[])
{
  return 0;
}
