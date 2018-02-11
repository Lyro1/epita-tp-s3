# include "queue.h"
# include <time.h>
# include <stddef.h>
# include <stdio.h>

void print_queue(struct queue *queue)
{
  printf("[");
  if (queue->size > 0)
  {
    struct list *first = queue->store;
    queue->store = queue->store->next;
    while (queue->store != first)
    {
      printf("%d, ", queue->store->data);
      queue->store = queue->store->next;
    }
  }
  printf("]");
}

int main()
{
  printf("Starting a few tests...\n\n");

  printf("Initializing a queue :\n");
  struct queue *q = malloc(sizeof(struct queue));
  queue_init(q);
  printf("Initialized successfully.\n\n");

  printf("Adding random numbers in the queue...\n");
  srand(time(NULL));
  for (int i = 0; i < 10; i++)
  {
    int *elm;
    *elm = rand() % 20;
    printf("Adding %d \n", *elm);
    queue_push(q, elm);
    print_queue(q);
  }
}
