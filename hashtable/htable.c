#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
  int capacity;
  int num_keys;
  char **keys;
};

static unsigned int htable_word_to_int(char *word) {
  unsigned int result = 0;

  while (*word != '\0') {
    result = (*word++ + 31 * result);
  }
  return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
  return i_key % h->capacity;
}

htable htable_new(int capacity) {
  int i;
  htable table = emalloc(sizeof *table);
  table->capacity = capacity;
  table->num_keys = 0;
  table->keys = emalloc(capacity * sizeof table->keys[0]);

  for (i = 0; i < capacity; i++) {
    /* allocates space for the strings themselves */
    table->keys[i] = NULL;
  }

  fprintf(stderr, "Memory allocation successful.\n");

  return table;
}

void htable_free(htable h) {
  int i;
  for (i = 0; i < h->capacity; i++) {
    free(h->keys[i]);
  }
  free(h->keys);
  free(h);
}

int htable_insert(htable h, char *str) {

  unsigned int index = htable_word_to_int(str);
  int position = htable_hash(h, index);
  int start = position;

  if (h->num_keys >= h->capacity) {
    fprintf(stderr, "Table capacity exceeded. Key was not entered.\n");
    return 0;
  }

  do {
    if (h->keys[position] == NULL) {
      h->keys[position] = emalloc((strlen(str) + 1) * sizeof str[0]);
      strcpy(h->keys[position], str);
      h->num_keys++;
      return 1;
    } else if (strcmp(h->keys[position], str) != 0) {
      position = htable_hash(h, position + 1);
    }
  } while(position != start);

  return 0;

}

void htable_print(htable h, FILE *stream) {
  int i;
  for (i = 0; i < h->capacity; i++) {
    fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
  }
}
