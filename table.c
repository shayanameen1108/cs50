#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// One bucket per letter of the alphabet
#define BUCKETS 26

// A node in a bucket's chain
typedef struct node {
  char *name;
  char *number;
  struct node *next;
} node;

unsigned int hash(char *name);
void insert(node *table[], char *name, char *number);
char *lookup(node *table[], char *name);
void free_table(node *table[]);

int main(void) {
  char *names[] = {"Emma", "Rodri", "Brian", "Ben", "David"};
  char *numbers[] = {"555-0100", "555-0101", "555-0102", "555-0103",
                     "555-0104"};
  int n = sizeof(names) / sizeof(names[0]);

  node *table[BUCKETS] = {NULL}; // Every bucket starts empty

  for (int i = 0; i < n; i++) {
    insert(table, names[i], numbers[i]);
  }

  char *name = "David";
  char *number = lookup(table, name);
  if (number != NULL) {
    printf("%s: %s\n", name, number);
  } else {
    printf("%s not found.\n", name);
  }

  free_table(table);

  return 0;
}

// Hashes a name to a bucket index using its first letter
unsigned int hash(char *name) { return toupper(name[0]) - 'A'; }

// Adds a name and number to the front of the right bucket's chain
void insert(node *table[], char *name, char *number) {
  node *temp = malloc(sizeof(node));
  if (temp == NULL) {
    exit(1);
  }

  temp->name = name;
  temp->number = number;

  int h = hash(name);
  temp->next = table[h]; // Prepend: new node becomes the head
  table[h] = temp;
}

// Searches the bucket that the name hashes to
char *lookup(node *table[], char *name) {
  for (node *ptr = table[hash(name)]; ptr != NULL; ptr = ptr->next) {
    if (strcmp(ptr->name, name) == 0) {
      return ptr->number;
    }
  }
  return NULL;
}

// Frees every chain in the table
void free_table(node *table[]) {
  for (int i = 0; i < BUCKETS; i++) {
    node *ptr = table[i];
    while (ptr != NULL) {
      node *next = ptr->next; // Save the next node before freeing
      free(ptr);
      ptr = next;
    }
  }
}
