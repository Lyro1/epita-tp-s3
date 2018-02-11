# include "queue.h"
# include <stddef.h>
# include <stdlib.h>

void queue_init(struct queue *queue)
{
  queue->store = NULL;
  queue->size = 0;
}

int queue_is_empty(struct queue *queue)
{
  return (queue->store == NULL);
}

void queue_push(struct queue *queue, void *elm)
{
  struct list *new = malloc(sizeof(struct list));
  if (new != NULL) {
    new->next = queue->store->next;
    new->data = elm;
    queue->store->next = new;
    queue->store = new;
  }
}

void* queue_pop(struct queue *queue)
{
  if (queue_is_empty(queue) == 0) {
    return NULL;
  }
  void *elm = queue->store;
  (queue->store->data) = NULL;
  while (queue->store->next->data != NULL) {
    queue->store = queue->store->next;
  }
  return elm;
}
