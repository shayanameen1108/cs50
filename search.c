#include <stdio.h>
#include <string.h>

int main(void) {
  constexpr int N = 6;

  char *strings[] = {"battleship", "boot",    "cannon",
                     "iron",       "thimble", "top hat"};

  char *x = "cannon";

  for (int i = 0; i < N; i++) {
    if (strcmp(strings[i], x) == 0) {
      printf("%s found at index %i.\n", x, i);

      return 0;
    }
  }

  printf("Not Found!\n");

  return 1;
}
