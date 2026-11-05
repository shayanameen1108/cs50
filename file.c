#include <stdio.h>

int main() {
  FILE *file = fopen("file.csv", "a");

  if (file == NULL) {
    return 1;
  }

  char *name_1 = "John";
  char *name_2 = "Jane";

  fprintf(file, "%s, %s\n", name_1, name_2);

  fclose(file);

  return 0;
}
