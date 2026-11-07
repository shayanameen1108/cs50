#include <stdio.h>
#include <stdlib.h>

// A node in a singly linked list
typedef struct node {
  int number;
  struct node *next;
} node;

// Frees every node in the list
void free_list(node *list) {
  while (list != NULL) {
    node *next = list->next; // Save the next node before freeing
    free(list);
    list = next;
  }
}

int main(void) {
  int array[] = {1, 2, 3};
  int n = sizeof(array) / sizeof(array[0]);

  node *list = NULL; // Head of the list
  node *tail = NULL; // Last node, so appending is O(1)

  for (int i = 0; i < n; i++) {
    // Allocate a new node
    node *temp = malloc(sizeof(node));

    // Out of memory: free what we already built and fail
    if (temp == NULL) {
      free_list(list);
      return 1;
    }

    temp->number = array[i];
    temp->next = NULL;

    // Append the new node at the end of the list
    if (list == NULL) {
      list = temp; // First node becomes the head
    } else {
      tail->next = temp;
    }
    tail = temp;
  }

  // Walk the list and print each number
  for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
    printf("%i\n", ptr->number);
  }

  free_list(list);

  return 0;
}
