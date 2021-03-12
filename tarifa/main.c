#include <stdio.h>

int
main(
  void
) {
  int x, n;

  scanf("%d", &x);
  scanf("%d", &n);

  int total_spent = 0;

  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    total_spent += v;
  }

  printf("%d\n", ((x * (n + 1)) - total_spent));
}
