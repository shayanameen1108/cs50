#include <stdio.h>

int main(void) {
  int n = 10;
  int *p = &n;

  printf("%i\n", n);
  printf("%p\n", &n);
  printf("%p\n", &p);
  printf("%i\n", *p);

  return 0;
}
