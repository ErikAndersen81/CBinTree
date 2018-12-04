#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  IntIntBinaryTree *tree = malloc(sizeof(IntIntBinaryTree));
  printf("Constructing an empty tree.\n");
  IntIntBinaryTree_ctor(tree);
  printf("Inserting the following {key:value} pairs in tree:\n");
  IntIntBinaryTree_insert(tree, 2, 4);
  IntIntBinaryTree_insert(tree, 1, 3);  
  IntIntBinaryTree_insert(tree, 4, 2);  
  IntIntBinaryTree_insert(tree, 7, 7);
  IntIntBinaryTree_insert(tree, 8, 4);
  IntIntBinaryTree_insert(tree, 9, 3);
  IntIntBinaryTree_insert(tree, 0, 2);
  IntIntBinaryTree_insert(tree, 5, 9);
  printf("{2:4, 1:3, 4:2, 7:7, 8:4, 9:3, 0:2, 5:9}\n");
  printf("\nThe tree now looks like this:\n");
  IntIntBinaryTree_print(tree);
  printf("\nTrying to insert a key that already exists ({7:7} <- {7:1})");
  IntIntBinaryTree_insert(tree, 7, 1);
  printf("\nThe tree now looks like this:\n");
  IntIntBinaryTree_print(tree);
  printf("Trying to find the node with key 8\n");
  if (IntIntBinaryTree_find(tree, 8) != NULL){
    IntIntBinaryTreeNode *n = IntIntBinaryTree_find(tree, 8);
    printf("Found node {%d:%d}\n", n->key, n->value);
    printf("Trying to remove node!\n");
    IntIntBinaryTree_remove(tree, n);
    printf("\nThe tree now looks like this:\n");
    IntIntBinaryTree_print(tree);
  }
  else {printf("Trick question, there's no key 8...\n");}
  
  return 0;
}
