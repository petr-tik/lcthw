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
    search
    delete
*/ 

typedef struct Node {
  /* This LinkedList node stores a int data and a ptr to the next Node struct */ 
  int data;
  struct Node * next;
} Node;


typedef struct LinkedList {
  Node * head;
  int length;
} LinkedList;


Node * create_node(int value) {
  /* Given a value, create a LinkedList node with that value and 
     return the pointer to it */ 
  Node * ll_ptr = (Node *)malloc(sizeof(struct Node));
  ll_ptr->data = value;
  ll_ptr->next = NULL;
  return ll_ptr;
}

int LinkedList_add(LinkedList *list_ptr, int value) {
  /* Function that adds an element to the singly-linked list

   */
  if (list_ptr->head == NULL) {
    // if the list is empty
    Node * new_node_ptr = create_node(value);
    list_ptr->head = new_node_ptr;
    list_ptr->length = 1;
    return 0; 
  } else {
    Node * node = list_ptr->head;
    while (node->next != NULL) {
      node = node->next;
    } 
    node->next = create_node(value);
    list_ptr->length++;
}  
  return 0;
}


int LinkedList_search(LinkedList *list_ptr, int value_to_find) {
  /* Returns 0, if value_to_find is in the list
             1, if value_to_find is not in the list
             -1, if list is empty
   */
  if (list_ptr->head == NULL) return -1;
  Node * node = list_ptr->head;
  while (node->next != NULL) {  
    if (node->data == value_to_find) return 0;
    node = node->next;
}
  // get to the end and never find the value
  return 1;
}


/* int LinkedList_delete(LinkedList *list_ptr, int value_to_delete) { */
/*   /\* Deletes the target value from the LinkedList and returns 0.  */
/*      If list empty - returns -1;  */
/*      if the value isn't in the list, return 1 *\/ */
/*   if ((list_ptr->head).data == NULL) { */
/*     return -1;} */

/* } */

int LinkedList_free_all(LinkedList *list_ptr) {
  /* Given a pointer to a LinkedList, iterate over all nodes and free them */
  Node * node = list_ptr->head;
  while(node != NULL) {
    Node * temp_node = node->next;
    free(node);
    node = temp_node;
}
  return 0;
}



int test_LinkedList(void) {
  /* Function to test LinkedList methods
     Creates a LinkedList, and tests different functions 
     by their return vals
  */
  LinkedList llist;
  LinkedList * llist_ptr = &llist;
  assert(LinkedList_search(llist_ptr, 8) == -1);
  assert(LinkedList_add(llist_ptr, 5) == 0);
  assert(LinkedList_add(llist_ptr, 7) == 0);
  assert(LinkedList_add(llist_ptr, 8) == 0);

  assert(LinkedList_search(llist_ptr, 5) == 0); 
  //assert(LinkedList_add(llist_ptr, 8) == 1);
  //LinkedList_delete(llist_ptr, 5);
  //assert(LinkedList_search(llist_ptr, 6) == -1);
  assert(LinkedList_free_all(llist_ptr) == 0);
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
      test_LinkedList();
      return 0;
    case 2:
      //test_BST();
      return 0;

    default:
      return 1;

  return 0;
}
}
