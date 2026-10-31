#include <stdio.h>
#include <string.h>

int main(void) {
  const char *message = "Hello, World!";

  printf("Length of '%s' is: %zu\n", message, strlen(message));

  for (int i = 0, n = strlen(message); i < n; i++) {
    printf("%i. %c\n", i + 1, message[i]);
  }

  return 0;
}
