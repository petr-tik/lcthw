#include <stdio.h>
#include <stdlib.h> // provides free, malloc funcs
#include <string.h> // gives strdup func
#include <assert.h>

struct Node {
  /* This LinkedList node stores a int data and a ptr to the next Node struct */ 
  int data;
  Node struct Node *next;
};

struct LinkedList {
  
};


/* Binary Search Trees 
   Need a different Node structure with pointers to left and right
   Methods include:
      search
      delete
      insert


*/

struct BSTNode {
  int key; // comparable key - make it an int
  BSTNode struct BSTNode *left;
  BSTNode struct BSTNode *right;
};


int search(int value, struct BSTNode *node)
{
  // if tree empty or no such value, return 1, else 0
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

int insert(int value, struct BSTNode *tree)
{
  // given a value and a pointer to a Binary Search Tree, insert the value
  // return 0 if successful, 1 otherwise
  assert(tree != NULL); 

  

}

int main(int argc, char *argv[])
{


  return 0;
}
