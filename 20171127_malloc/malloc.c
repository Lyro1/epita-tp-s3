#include "malloc.h"

static inline
size_t word_align(size_t n)
{
  size_t res = n & sizeof(size_t);
  while (res < n)
  {
    res += 8;
  }
  return res; 
}

void zerofill(void *ptr, size_t len)
{
  int *locptr = ptr;
  for (size_t i = 0; i < len; i++)
  {
    *locptr = 0;
    locptr++;
  }
}

void wordcpy(void *dst, void *src, size_t len)
{
  int *locdst = dst;
  int *locsrc = src;
  for (size_t i = 0; i < len; i++)
  {
    *locdst = *locsrc;
    locdst++;
    locsrc++;
  }
}

static
struct chunk* get_base(void) {
  static struct chunk *base = NULL;
  if (!base) {
    base = sbrk(sizeof(struct chunk));
    if (base == (void*)(-1))
    {
      _exit(71); // OS Error
    }
    base->next = NULL;
    base->prev = NULL;
    base->size = 0;
    base->free = 0;
  }
  return base;
}

static
int extend_heap(struct chunk *last, size_t size)
{
  struct chunk *new = sbrk(size + sizeof(struct chunk));
  if (new != (void*)(-1))
  {
    last->next = new;
    new->prev = last;
    new->next = NULL;
    new->size = size;
    new->free = 1;
    return 1;
  }
  return 0;
}

static
struct chunk* find_chunk(size_t size)
{
  struct chunk *base = get_base(); 
  while(base && base->size < size)
  {
    base = base->next;
  }
  return base;
}

static
struct chunk* get_chunk(void *p)
{
  struct chunk *base = get_base();
  if (p && p%sizeof(size_t) == 0 && p > base && p < sbrk(0) && *p == p->data)
  {
    return p;
  }
  return NULL;
}   

static
void* malloc(size_t size)
{
  size = word_align(size);
  struct chunk *place = find_chunk(size);
  if (!place)
  {
    if (extend_heap(sbrk(0), size) == 0)
    {
      return NULL;
    }
    place = find_chunk(size);
  }
  place->free = 0;
  return place;
}

static
void free(void *p)
{
    struct chunk chunktofree = get_chunk(void *p);
    chunktofree->free = 1;
}

static
void* calloc(size_t size)
{
  void* ptr = malloc(size);
  if (ptr) 
  {
    zerofill(ptr, size);
  } 
  return ptr;
}

static
void realloc(void *ptr, size_t size)
{
  if (ptr)
  {
    struct chunk *ptrchunk = malloc(size);
    if (ptrchunk)
    {
      wordcpy(ptrchunk, ptr, size);
    }
    free(ptr);
  }
}
