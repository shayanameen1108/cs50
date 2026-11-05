#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  char *phone_number;
} person;

int main(void) {
  constexpr int N = 6;

  person people[] = {{"Alice", "+1-555-1234"},   {"Bob", "+1-555-5678"},
                     {"Charlie", "+1-555-9012"}, {"David", "+1-555-3456"},
                     {"Eve", "+1-555-7890"},     {"Frank", "+1-555-2345"}};

  char *x = "Charlie";

  for (int i = 0; i < N; i++) {
    if (strcmp(people[i].name, x) == 0) {
      printf("%s's phone number is %s.\n", x, people[i].phone_number);

      return 0;
    }
  }

  printf("Not Found!\n");

  return 1;
}
