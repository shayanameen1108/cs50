#include <stdio.h>
#include <stdlib.h>

// Number of buckets in the hash table
#define SIZE 10

// A node in a bucket's chain
typedef struct node {
  int number;
  struct node *next;
} node;

unsigned int hash(int number);
node *insert(node *head, int number);
bool search(node *table[], int number);
void free_table(node *table[]);

int main(void) {
  int array[] = {1, 2, 3, 12, 23, 34};
  int n = sizeof(array) / sizeof(array[0]);

  node *table[SIZE] = {NULL}; // Every bucket starts empty

  for (int i = 0; i < n; i++) {
    // Hash decides which bucket the number goes into
    int h = hash(array[i]);
    printf("%i -> bucket %i\n", array[i], h);
    table[h] = insert(table[h], array[i]);
  }

  int x = 12;
  if (search(table, x)) {
    printf("%i found.\n", x);
  } else {
    printf("%i not found.\n", x);
  }

  free_table(table);

  return 0;
}

// Hashes a number to a bucket index
unsigned int hash(int number) { return number % SIZE; }

// Adds a number to the front of a bucket's chain
node *insert(node *head, int number) {
  node *temp = malloc(sizeof(node));
  if (temp == NULL) {
    exit(1);
  }

  temp->number = number;
  temp->next = head; // Prepend: new node becomes the head
  return temp;
}

// Searches the bucket that the number hashes to
bool search(node *table[], int number) {
  for (node *ptr = table[hash(number)]; ptr != NULL; ptr = ptr->next) {
    if (ptr->number == number) {
      return true;
    }
  }
  return false;
}

// Frees every chain in the table
void free_table(node *table[]) {
  for (int i = 0; i < SIZE; i++) {
    node *ptr = table[i];
    while (ptr != NULL) {
      node *next = ptr->next; // Save the next node before freeing
      free(ptr);
      ptr = next;
    }
  }
}
