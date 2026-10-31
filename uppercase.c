#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char message[] = "Hello, World!";

  printf("Before: %s\n", message);

  for (int i = 0, n = strlen(message); i < n; i++) {
    //   if (message[i] >= 'a' && message[i] <= 'z') {
    //     message[i] -= 32;
    //   }

    message[i] = toupper(message[i]);
  }

  printf("After: %s\n", message);

  return 0;
}
