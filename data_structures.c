#include <stdio.h>
#include <stdlib.h> // provides free, malloc funcs
#include <string.h> // gives strdup func
#include <assert.h>

// to run
//  gcc data_structures.c -o data_structures
// ./data_structures

/* LinkedList: structs and forward declarations
Methods include: 
    add
    add_from_left
    search
    delete
*/ 

void test_LinkedList(void);

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

All operations take the pointer to the BST as argument and 
return int for success/failure. Either way, the BST is available under the same pointer
*/

typedef struct BSTNode {
  int key; // comparable key - make it an int
  BSTNode struct BSTNode *left;
  BSTNode struct BSTNode *right;
} BSTNode;

/* Forward declaring test funcs */

void test_BST(void); 

// declarations over

int BST_search(int value, BSTNode *node)
{
  // check that tree is not empty
  assert(node); 

  // if tree empty or no such value, return 0, else 1
  if !(node->key) {
    return 1; } 
  else if (node->key == value) {
    return 0; }
  else if (node->key < value) {
    BST_search(value, node->right); }
  else {
    BST_search(value, node->left);}
  return 1;
}

int BST_insert(int value, BSTNode *tree)
{
  /* Given a value and a pointer to a Binary Search Tree, insert the value
  return 0 if successful, 1 otherwise. 
  The updated (or not, if return 1) tree 
  will be available at the same pointer address */
  if (!tree) {
    node = (BSTNode *)malloc(sizeof(BSTNode)); 
    node->key = value;
    node->left = NULL;
    node->right = NULL; 
    return 0;
}
  else if (node->key > value) {
    BST_insert(value, node->left);
    } else {
    BST_insert(value, node->right);}
  return 1; // if it ever gets here, it never inserted a node
}

int get_option() {
  /* Prints a numbered list of options and returns the chosen value, restarts if the value isn't allowed */
  int answer;
  printf("Which simulation do you want to run\n1. Linked List\n2. Binary Search Tree\n");
  fscanf(stdin, "%d", &answer);
  if (answer < 3) {
    printf("ERROR! Invalid option, try again.\n");
    return answer;
} else {
    get_option();
}
}

int main(int argc, char *argv[])
{
  switch(get_option()) {
    case 1:
      //test_LinkedList();
      return 0;
      break;
    case 2:
      //test_BST();
      return 0;
      break;
    default:
      return 1;

  return 0;
}
}
