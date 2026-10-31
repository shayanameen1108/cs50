#include <stdio.h>
#include <string.h>

int main() {
  char *message = "Hello, World!";

  printf("Length of '%s' is: %zu\n", message, strlen(message));

  return 0;
}
