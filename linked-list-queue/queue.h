#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queue *queue;

queue queue_new();
queue queue_free(queue q);
void enqueue(queue q, double item);
double dequeue(queue q);
void queue_print(queue q);
void queue_print_info(queue q);
int queue_size(queue q);

#endif
