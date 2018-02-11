#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

uint32_t hash(char *data)
{
	uint32_t h = 0;
	for (; *data != 0; data++)
	{
		h += *data + (*data * 1024);
		h = h ^ h/64;
	}
	h = h * 8;
	h = h ^ h/2048;
	h = h * 32768;
	return h;
}

struct htable *create_htable(size_t capacity)
{
	struct htable *table = malloc(sizeof(struct htable));
	table->size = 0;
	table->capacity = capacity;
	struct pair **tab = malloc(sizeof(struct pair) * capacity);
	for (size_t i = 0; i < capacity; i++)
	{
		*(tab + i) = NULL;
	}
	table->tab = tab;
    return table;
}

struct pair *access_htable(struct htable *htable, char *key)
{
	uint32_t h = hash(key);
	size_t index = h % htable->capacity;
	struct pair *list = htable->tab[index];
    if (list != NULL)
    {
	    while (list->next != NULL && strcmp(key, list->next->key) != 0)
	    {
	    	list = list->next;
	    }
        return list->next;
    }
    else
    {
        return NULL;
	}
}

void clear_pair(struct pair *pair)
{
    if (pair && pair->next)
    {
				clear_pair(pair->next);
    }
    free(pair);
}

void clear_htable(struct htable *htable)
{
    for (size_t i = 0; i < htable->capacity; i++)
    {
    	clear_pair(htable->tab[i]);
    }
}

struct htable *autoresize(struct htable *htable)
{
    struct htable *newtable = create_htable(htable->capacity * 2);
	for (size_t i = 0; i < htable->capacity; i++)
	{
		while(htable->tab[i] != NULL)
		{
			add_htable(newtable, htable->tab[i]->key, htable->tab[i]->value);
			htable->tab[i] = htable->tab[i]->next;
		}
	}
	clear_htable(htable);
return newtable;
}

int add_htable(struct htable *htable, char *key, void *value)
{
    struct pair *search = access_htable(htable, key);
    if (search == NULL)
    {
		if ((htable->size / htable->capacity) > 0.75)
		{
		    htable = autoresize(htable);
		}
        struct pair *new = malloc(sizeof(struct pair));
        new->hkey = hash(key);
        new->key = key;
        new->value = value;
        size_t index = new->hkey % htable->capacity;
        new->next = (htable->tab[index]);
        htable->tab[index] = new;
        htable->size += 1;
		return 1;
    }
    else
    {
        return 0;
    }
}

void remove_htable(struct htable *htable, char *key)
{
    uint32_t h = hash(key);
    size_t index = h % htable->capacity;
    struct pair *list = htable->tab[index];
    while (list->next != NULL && strcmp(key, list->next->key) != 0)
    {
        list = list->next;
    }
    if (list->next != NULL)
    {
		struct pair *after = list->next->next;
        clear_pair(list->next);
		list->next = after;
    }
}
