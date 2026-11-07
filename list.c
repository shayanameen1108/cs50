#include <stdio.h>
#include <stdlib.h>

// A node in a singly linked list
typedef struct node {
  int number;
  struct node *next;
} node;

// Frees every node in the list
void free_list(node *head) {
  while (head != NULL) {
    node *next = head->next; // Save the next node before freeing
    free(head);
    head = next;
  }
}

int main(void) {
  int array[] = {1, 2, 3};
  int n = sizeof(array) / sizeof(array[0]);

  node *head = NULL; // Head of the list
  node *tail = NULL; // Last node, so appending is O(1)

  for (int i = 0; i < n; i++) {
    // Allocate a new node
    node *temp = malloc(sizeof(node));

    // Out of memory: free what we already built and fail
    if (temp == NULL) {
      free_list(head);
      return 1;
    }

    temp->number = array[i];
    temp->next = NULL;

    // Append the new node at the end of the list
    if (head == NULL) {
      head = temp; // First node becomes the head
    } else {
      tail->next = temp;
    }
    tail = temp;
  }

  // Walk the list and print each number
  for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
    printf("%i\n", ptr->number);
  }

  free_list(head);

  return 0;
}
