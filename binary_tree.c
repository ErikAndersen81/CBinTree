#include "binary_tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
  
void IntIntBinaryTree_ctor(IntIntBinaryTree *tree) {
  struct IntIntBinaryTree t = {.root=NULL, .size=0};
  tree = &t;
}

void IntIntBinaryTree_dtor(IntIntBinaryTree *tree) {
  while(tree->root != NULL){
    IntIntBinaryTree_remove(tree, tree->root);
  }
  free(tree);
  return;
}

// find the node that should be the parent of the inserted node
IntIntBinaryTreeNode *IntIntBinaryTree_insert_find(IntIntBinaryTreeNode *node, int key) {
  if (node->key < key) {
    if (node->right == NULL) {
      return node;
  }
    return IntIntBinaryTree_insert_find(node->right, key);
  }
  if (node->key > key){
    if (node->left == NULL){
      return node;
    }
    return IntIntBinaryTree_insert_find(node->left, key);
  }
  else {
    return node;
  }
}


IntIntBinaryTreeNode *IntIntBinaryTree_insert(IntIntBinaryTree *tree, int key, int value) {
  struct IntIntBinaryTreeNode *n = malloc(sizeof(IntIntBinaryTreeNode));
  n->key=key;                       // Set the key of the new node
  n->value=value;                   // Set the value of the new node
  
  if (tree->root == NULL) {         // If the tree is empty set new node as root
    tree->root = n;
    tree->size++;                     // Increase size of the tree
    return n;
  }
  IntIntBinaryTreeNode *par = IntIntBinaryTree_insert_find(tree->root, key);
  if (par->key == key){
    par->value = value;
    free(n);
    return par;
  }
  if (par->key > key) {
    par->left = n;
  }
  else {
    par->right = n;
  }
  n->parent = par;
  tree->size++;                     // Increase size of the tree
  return n;
}



IntIntBinaryTreeNode *IntIntBinaryTree_find(IntIntBinaryTree *tree, int key) {
  IntIntBinaryTreeNode *node = tree->root;
  while(1){
    if (node == NULL){
      return NULL;
    }
    if (node->key > key) {
      node = node->left;
    }
    if (node->key < key) {
      node = node->right;
    }
    if (node->key == key) {
      return node;
    }
  }
}

void IntIntBinaryTree_remove(IntIntBinaryTree *tree, IntIntBinaryTreeNode *node) {
  IntIntBinaryTreeNode *temp;
  if (node->parent == NULL) {
    if (node->left != NULL) {
      tree->root = node->left;
      temp = node->left;
      while(temp->right != NULL) {
	temp = temp->right;
      }
      temp->right = node->right;
    }
    else if (node->right != NULL) {
      tree->root = node->right;
      temp = node->right;
      while(temp->left != NULL) {
	temp = temp->left;
      }
      temp->left = node->left;
    }
    else {
      tree->root = NULL;
      free(node);
      tree->size--;
      return;
    }
    tree->root->parent = NULL;
    free(node);
    tree->size--;
    return;
  }
  // Is the node to the left or right of its parent?
  if (node->parent->left == node){
    // Does the node have any childen with a higher key?"
    if (node->right != NULL) {
      // Set that node's parent to be the parent of the note we are deleting"
      node->right->parent = node->parent;
      temp = node->right;
      // Find the child of that node with the lowest key"
      while (temp->left != NULL){
	temp = temp->left;
      }
      // Attach the left subtree of the node we are deleting to that node"
      temp->left=node->left;
      free(node);
      tree->size--;
      return;
    }
    // No nodes in the subtree have a higher key"
    if (node->left != NULL) {
      node->left->parent = node->parent;
      node->parent->left = node->left;
      free(node);
      tree->size--;
      return;
	}
  }
  if (node->parent->right == node){
    // Does the node have any childen with a lower key?"
    if (node->left != NULL) {
      // Set that node's parent to be the parent of the note we are deleting"
      node->left->parent = node->parent;
      temp = node->left;
      // Find the child of that node with the highest key."
      while (temp->right != NULL){
	temp = temp->right;
      }
      // Attach the right subtree of the node we are deleting to that node."
      temp->right=node->right;
      free(node);
      tree->size--;
      return;
    }
    // No nodes in the subtree have a lower key"
    if (node->right != NULL) {
      node->right->parent = node->parent;
      node->parent->right = node->right;
      free(node);
      tree->size--;
      return;
    }
  }
}


// Private helper function
static int IntIntBinaryTreeNode_print(const IntIntBinaryTreeNode *const node, const int indent) {
	if(!node) return 0;
	const int sizeRight = IntIntBinaryTreeNode_print(node->right, indent + 1);
	for(int i = 0; i != indent; ++i)
		printf("  ");
	printf("%d: %d\n", node->key, node->value);
	const int sizeLeft = IntIntBinaryTreeNode_print(node->left, indent + 1);
	return sizeRight + sizeLeft + 1;
}

void IntIntBinaryTree_print(const IntIntBinaryTree *tree) {
	assert(tree);
	printf("IntIntBinaryTree: size = %d\n", tree->size);
	const int size = tree->root
		? IntIntBinaryTreeNode_print(tree->root, 0)
		: 0;
	if(size != tree->size)
		printf("WARNING: tree size is not up-to-date, tree->size = %d, but actual size is %d\n", tree->size, size);
}
