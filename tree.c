#include <stdio.h>
#include <stdlib.h>

// A node in a binary search tree
typedef struct node {
  int number;
  struct node *left;
  struct node *right;
} node;

node *insert(node *root, int number);
bool search(node *root, int number);
void free_tree(node *root);

int main(void) {
  int array[] = {4, 2, 6, 1, 3, 5, 7};
  int n = sizeof(array) / sizeof(array[0]);

  node *root = NULL;

  for (int i = 0; i < n; i++) {
    root = insert(root, array[i]);
  }

  int x = 5;
  if (search(root, x)) {
    printf("%i found.\n", x);
  } else {
    printf("%i not found.\n", x);
  }

  free_tree(root);

  return 0;
}

// Inserts a number into the tree, keeping BST ordering
node *insert(node *root, int number) {
  // Empty spot reached: put the new node here
  if (root == NULL) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {
      exit(1);
    }
    temp->number = number;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }

  // Recurse into the subtree where the number belongs
  if (number < root->number) {
    root->left = insert(root->left, number);
  } else if (number > root->number) {
    root->right = insert(root->right, number);
  }

  return root;
}

// Searches the tree for a number
bool search(node *root, int number) {
  if (root == NULL) {
    return false;
  }

  if (number < root->number) {
    return search(root->left, number);
  } else if (number > root->number) {
    return search(root->right, number);
  }

  return true;
}

// Frees every node in the tree
void free_tree(node *root) {
  if (root == NULL) {
    return;
  }

  // Free children before freeing the node itself
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
