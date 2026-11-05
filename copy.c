#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *name_1 = "bob";
  char *name_2 = malloc(strlen(name_1) + 1);

  if (name_2 == NULL) {
    return 1;
  }

  printf("%p\n", name_1);
  printf("%p\n", name_2);

  strcpy(name_2, name_1);

  printf("Before Capitalize:\n");

  printf("%s\n", name_1);
  printf("%s\n", name_2);

  if (strlen(name_1) > 0) {
    *name_2 = toupper(*name_2);
  }

  printf("After Capitalize:\n");

  printf("%s\n", name_1);
  printf("%s\n", name_2);

  free(name_2);

  return 0;
}
