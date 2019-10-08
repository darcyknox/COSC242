#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main() {
  queue q = queue_new();
  char c;
  double num;
  while (1 == scanf(" %c", &c)) {
    if (c == 'p') {
      queue_print(q);
    } else if (c == 'i') {
      queue_print_info(q);
    } else if (c == 'r' && queue_size(q) > 0) {
      printf("%.2f\n", dequeue(q));
    } else if (c == 'a' && 1 == scanf("%lg", &num)) {
      enqueue(q, num);
    }
  }
  q = queue_free(q);
  return EXIT_SUCCESS;
}
