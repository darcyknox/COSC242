#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void print_key(char *key) {
  printf("%s\n", key);
}

void dosearch(bst b, char *key) {
  if (bst_search(b, key) == 0) {
    printf("%s -- not found\n", key);
  } else {
    printf("%s -- found\n", key);
  }
}

int main(void) {
  bst b = bst_new();

  printf("inserting d,b,f,a,c,e,g\n");
  b = bst_insert(b, "d");
  b = bst_insert(b, "b");
  b = bst_insert(b, "f");
  b = bst_insert(b, "a");
  b = bst_insert(b, "c");
  b = bst_insert(b, "e");
  b = bst_insert(b, "g");

  printf("inorder traversal\n");
  bst_inorder(b, print_key);

  printf("preorder traversal\n");
  bst_preorder(b, print_key);

  printf("searching\n");
  dosearch(b, "f");
  dosearch(b, "o");
  dosearch(b, "x");
  dosearch(b, "e");
  dosearch(b, "d");

  bst_free(b);
  return EXIT_SUCCESS;
}
