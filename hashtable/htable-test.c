/* htable-test.c */
#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"

int main() {
  int size = 17;
  htable h = htable_new(size);
  char word[80];

  while (getword(word, sizeof word, stdin) != EOF) {
    htable_insert(h, word);
  }

  htable_print(h, stdout);
  htable_free(h);
  return EXIT_SUCCESS;
}
