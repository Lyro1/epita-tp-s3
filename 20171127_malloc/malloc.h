struct chunk {
  struct chunk *next, *prev;
  size_t        size;
  long          free;
  void         *data;
};

/* word_align(n): returns the least multiple of sizeof (size_t) greater or
   equal to the input value.*/
static inline
size_t word_align(size_t n);

/* zerofill(ptr, len): write len 0 bytes at the address ptr */
void zerofill(void *ptr, size_t len);

/* wordcpy(dst, src, len) copy len bytes from src to dst */
void wordcpy(void *dst, void *src, size_t len);

/* returns the base of the heap or initialize it if needed */
static
struct chunk* get_base(void);

static 
int extend_heap(struct chunk *last, size_t size);

static
struct chunk* find_chunk(size_t size);

static
struct chunk* get_chunk(void *p);

void* malloc(size_t size);

void free(void* ptr);

void* calloc(size_t size);

void realloc(void* ptr, size_t size);
