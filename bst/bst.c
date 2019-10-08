#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst_node {
  char *key;
  bst left;
  bst right;
};

void bst_inorder(bst b, void f(char *str)) {
  if (b == NULL) {
    return;
  }
  bst_inorder(b->left, f);
  f(b->key);
  bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *str) {
/* if nothing is at that node, create a tree with 2 subtrees */
  if (b == NULL) {
    b = emalloc(sizeof *b);
    b->left = NULL;
    b->right = NULL;
    b->key = emalloc((strlen(str) + 1) * sizeof str[0]);
    strcpy(b->key, str);
  } else {
/* otherwise evaluate whether the key should go in the left or right subtree */
    if (strcmp(str, b->key) < 0) {
      b->left = bst_insert(b->left, str);
    } else if (strcmp(str, b->key) > 0) {
      b->right = bst_insert(b->right, str);
    }
  }
  return b;
}

bst bst_new() {
  return NULL;
}

void bst_preorder(bst b, void f(char *str)) {
  if (b == NULL) {
    return;
  }
  f(b->key);
  bst_preorder(b->left, f);
  bst_preorder(b->right, f);
}

int bst_search(bst b, char *str) {
  if (b == NULL) {
    return 0;
  } else if (strcmp(b->key, str) == 0) {
    return 1;
  } else if (strcmp(str, b->key) < 0) {
    return bst_search(b->left, str);
  } else if (strcmp(str, b->key) > 0) {
    return bst_search(b->right, str);
  } else {
    exit(EXIT_FAILURE);
  }
}

/* do this my way - read lab book */
bst bst_free(bst b) {
 if (NULL == b) {
   return b;
 }
 bst_free(b->left);
 bst_free(b->right);
 free(b->key);
 free(b);

 return b;

}
