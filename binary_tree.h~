#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Public
// =======================================================

typedef struct IntIntBinaryTree IntIntBinaryTree;
typedef struct IntIntBinaryTreeNode IntIntBinaryTreeNode;

struct IntIntBinaryTree {
	IntIntBinaryTreeNode *root;
	int size;
};

struct IntIntBinaryTreeNode {
    IntIntBinaryTreeNode *left, *right;
    IntIntBinaryTreeNode *parent;
    int key;
    int value;
};

// Public
// =======================================================

// Initialise a binary tree.
void IntIntBinaryTree_ctor(IntIntBinaryTree *tree);
// Deallocates all node memory for the given binary tree.
// Does not deallocate the memory pointed to by tree.
void IntIntBinaryTree_dtor(IntIntBinaryTree *tree);
// Insert a new key-value pair in the binary tree.
// Returns: NULL on error, otherwise a pointer to the inserted node.
IntIntBinaryTreeNode *IntIntBinaryTree_insert(IntIntBinaryTree *tree, int key, int value);
// Searches for a given key in the binary tree.
// Returns: a pointer to a node with the given key, or NULL if no such node exists.
IntIntBinaryTreeNode *IntIntBinaryTree_find(IntIntBinaryTree *tree, int key);
// Removes a given node from the binary tree.
void IntIntBinaryTree_remove(IntIntBinaryTree *tree, IntIntBinaryTreeNode *node);

// A simple way to visualize the created tree.
// Prints the right child above and the left child below.
// Example:
//     100: 0
//   10: 0
//     8: 0
// 5: 0
//     4: 0
//   3: 0
//     2: 0
//       1: 0
void IntIntBinaryTree_print(const IntIntBinaryTree *tree);

#endif // BINARY_TREE_H
