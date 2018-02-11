# include "vector.h"
# include <stddef.h>
// returns false if something goes wrong (realloc fails)
int double_vector_size(struct vector *vect)
{
	int *tmp = realloc(vect->data, 2 * vect->capacity * sizeof (int));
  	if (tmp == NULL) {
   		// oups no more memory ?
    		//warn("realloc of data fails");
    		return 0;
  	}
  	vect->data = tmp;
  	vect->capacity *= 2;
  	return 1;
}

int vector_init(struct vector *vect, size_t capacity)
{
	int *array = malloc(capacity * sizeof(int));
	if (array == NULL)
	{
		return 0;
	}
	vect->capacity = capacity;
	vect->size = 0;
	vect->data = array;
	return 1;
}

struct vector* vector_make(size_t capacity)
{
	struct vector *vect = malloc(sizeof(struct vector));
	if (vect == NULL || vector_init(vect, capacity) == 0)
	{
		return NULL;
	}
	return vect;
}

int vector_push_back(struct vector *vect, int x)
{
	if (vect->size == vect->capacity)
	{
		if (double_vector_size(vect) == 0) {
			return 0;
		}
	}
	*(vect->data + vect->size) = x;
	vect->size++;
	return 1;
}

int vector_pop_back(struct vector *vect, int *x)
{
	if (vect->size > 0)
	{
		*x = *(vect->data + vect->size - 1);
		*(vect->data + vect->size - 1) = 0;
		vect->size--;
		return 1;
	}
	return 0;
}

int vector_push_front(struct vector *vect, int x)
{
	if (vect->size == vect->capacity)
	{
		if (double_vector_size(vect) == 0)
		{
			return 0;
		}
	}
	for (size_t i = vect->size; i > 0; i--)
	{
		*(vect->data + i) = *(vect->data + i - 1);
	}
  *(vect->data) = x;
	vect->size++;
	return 1;
}

int vector_pop_front(struct vector *vect, int *x)
{
	if (vect->size > 0)
	{
		*x = *(vect->data);
		vect->data = 0;
		for (size_t i = 1; i <= vect->size; i++)
		{
			*(vect->data + i - 1) = *(vect->data + i);
		}
		vect->size--;
		return 1;
	}
	return 0;
}

int vector_insert_at(struct vector *vect, size_t pos, int x)
{
	if (pos <= vect->size)
	{
		if (vect->size == vect->capacity && double_vector_size(vect) == 0)
		{
			return 0;
		}
		for (size_t i = vect->size; i > pos; i--)
		{
			*(vect->data + i) = *(vect->data + i - 1);
		}
		*(vect->data + pos) = x;
		vect->size++;
		return 1;
	}
	return 0;
}

int vector_extract_at(struct vector *vect, size_t pos, int *x)
{
	if (vect->size > 0 && pos < vect->size) {
		*x = *(vect->data + pos);
		for (size_t i = pos; i < vect->size; i++)
		{
			*(vect->data + i) = *(vect->data + i + 1);
		}
		vect->size--;
		return 1;
	}
	return 0;
}

struct vector* vector_clone (struct vector *vect)
{
	struct vector *res = vector_make(vect->capacity);
	for (size_t i = 0; i < vect->size; i++) {
		if (vector_insert_at(res, i, *(vect->data + i)) == 0)
		{
			return NULL;
		}
	}
	return res;
}
