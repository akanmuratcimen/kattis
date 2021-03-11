#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://open.kattis.com/problems/lektira

void
swap(
  char *a,
  char *b
) {
  char t = *a;

  *a = *b;
  *b = t;
}

void
reverse(
  char *start,
  char *end
) {
  size_t half = (end - start + 1) / 2;

  for (size_t i = 0; i < half; ++i) {
    swap(start + i, end - i);
  }
}

int
main(
  void
) {
  char word[50];
  scanf("%s", word);

  int len = strlen(word);
  char *crr = malloc(len + 1);
  char *result = malloc(len + 1);

  strcpy(result, word);

  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len - 1; ++j) {
      strcpy(crr, word);
      
      reverse(crr, crr + i);
      reverse(crr + i + 1, crr + j);
      reverse(crr + j + 1, crr + len - 1);

      if (strcmp(crr, result) < 0) {
        strcpy(result, crr);
      }
    }
  }

  printf("%s\n", result);

  free(crr);
  free(result);
}
