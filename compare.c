#include <stdio.h>
#include <string.h>

int main(void) {
  char *name_1 = "Bob";
  char *name_2 = "Bob";

  printf("%p\n", name_1);
  printf("%p\n", name_2);

  if (strcmp(name_1, name_2) == 0) {
    printf("Same\n");
  } else {
    printf("Different\n");
  }

  return 0;
}
