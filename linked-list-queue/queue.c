#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;

struct q_item {
  double item;
  q_item next;
};

struct queue {
  q_item first;
  q_item last;
  int length;
};

queue queue_new() {
  queue result = emalloc(sizeof *result);
  result->first = NULL;
  result->last = NULL;
  result->length = 0;

  return result;
}

void enqueue(queue q, double item) {
  q_item i = emalloc(sizeof *i);

  i->item = item;
  i->next = NULL;

  if (q->length == 0) {
    q->first = i;
  } else {
    q->last->next = i;
  }

  q->last = i;
  q->length++;
}

double dequeue(queue q) {
  q_item dq_item;
  double val;

  dq_item = q->first; // will be dequeueing the first item in the list
  val = dq_item->item; // get the value to be returned

  q->first = q->first->next; // first now points to the next item in the list
  q->length--; // the length has decreased

  free(dq_item); // free the item

  return val; // return the value of what was released
}

void queue_print(queue q) {
/* print queue contents one per line to 2 decimal places */
  q_item i = q->first;
  while (i->next != NULL && q->length > 0) {
    printf("%.2f\n", i->item);
    i = i->next;
  }
  printf("%.2f\n", i->item);
}

void queue_print_info(queue q) {
  if (q->length == 0) {
    printf("The queue is empty\n");
  } else {
    printf("first %.2f, last %.2f, length %d\n", q->first->item,
    q->last->item, q->length);
  }
}

int queue_size(queue q) {
  return q->length;
}

void queue_free_aux(q_item i) {
  if (i->next != NULL) {
    queue_free_aux(i->next);
  }
  free(i);
}

queue queue_free(queue q) {
    if (q->length > 0) {
      queue_free_aux(q->first);
    }
    free(q);
    return q;
}
