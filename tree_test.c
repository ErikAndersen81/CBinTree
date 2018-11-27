#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  IntIntBinaryTree *tree = malloc(sizeof(IntIntBinaryTree));
  IntIntBinaryTree_ctor(tree);
  IntIntBinaryTree_insert(tree, 2, 4);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 1, 3);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 4, 2);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 7, 63);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 8, 4);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 9, 3);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 0, 2);
  IntIntBinaryTree_print(tree);
  IntIntBinaryTree_insert(tree, 5, 63);
  IntIntBinaryTree_print(tree);
  return 0;
}
