#include <stdio.h>

float avg(int numbers[], int size);

int main() {
  constexpr int N = 3;

  int scores[N];

  scores[0] = 72;
  scores[1] = 73;
  scores[2] = 33;

  for (int i = 0; i < N; i++) {
    printf("Score %i: %i\n", i + 1, scores[i]);
  }

  printf("Average Score: %f\n", avg(scores, N));
}

float avg(int numbers[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += numbers[i];
  }

  return sum / (float)(size);
}
