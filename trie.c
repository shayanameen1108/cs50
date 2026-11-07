#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Each node can point to one child per letter
#define LETTERS 26

// A node in a trie
typedef struct node {
  bool is_word; // True if a word ends at this node
  struct node *children[LETTERS];
} node;

node *insert(node *root, char *word);
bool search(node *root, char *word);
node *new_node(void);
void free_trie(node *root);

int main(void) {
  char *words[] = {"emma", "rodri", "brian", "emily"};
  int n = sizeof(words) / sizeof(words[0]);

  node *root = NULL;

  for (int i = 0; i < n; i++) {
    root = insert(root, words[i]);
  }

  char *word = "emily";
  if (search(root, word)) {
    printf("%s found.\n", word);
  } else {
    printf("%s not found.\n", word);
  }

  free_trie(root);

  return 0;
}

// Inserts a word into the trie, one node per letter
node *insert(node *root, char *word) {
  // Empty spot reached: grow the trie here
  if (root == NULL) {
    root = new_node();
  }

  // End of word: mark this node so prefixes don't count as words
  if (*word == '\0') {
    root->is_word = true;
    return root;
  }

  // Recurse into the child for the next letter
  int index = tolower(*word) - 'a';
  root->children[index] = insert(root->children[index], word + 1);
  return root;
}

// Searches the trie for a word
bool search(node *root, char *word) {
  if (root == NULL) {
    return false;
  }

  // End of word: only a word if this node says so
  if (*word == '\0') {
    return root->is_word;
  }

  // Recurse into the child for the next letter
  int index = tolower(*word) - 'a';
  return search(root->children[index], word + 1);
}

// Allocates a node with no children and no word ending in it
node *new_node(void) {
  node *temp = calloc(1, sizeof(node)); // calloc zeroes children and is_word
  if (temp == NULL) {
    exit(1);
  }
  return temp;
}

// Frees every node in the trie
void free_trie(node *root) {
  if (root == NULL) {
    return;
  }

  // Free children before freeing the node itself
  for (int i = 0; i < LETTERS; i++) {
    free_trie(root->children[i]);
  }
  free(root);
}
