#include "list.h"
#include <stdlib.h>

void list_init(struct list *list) 
{
    list->next = NULL;
    list->data = 0;
}

int list_is_empty(struct list *list) 
{
	if (list->next == NULL) {
		return 1;
	}
	return 0;
}

size_t list_len(struct list *list) 
{
	if (list_is_empty(list)) {
		return 0;
	}
	size_t res = 0;
	while (list->next != NULL) {
		res += 1;
		list = list->next;
	}
	return res;
}

void list_push_front(struct list *list, struct list *elm)
{
	struct list *wait = list->next;
	list->next = elm;
	elm->next = wait;
}

struct list* list_pop_front(struct list *list) 
{
	struct list *end = list->next->next;
	struct list *elm = list->next;
	list->next = end;
	return elm;
}

struct list* list_find(struct list *list, int value) 
{
	while (list->next != NULL && list->next->data != value) {
		list = list->next;
	}
	if (list->next == NULL) {
		return list->next;
	}
	return list;
}

struct list* list_lower_bound(struct list *list, int value) 
{
	while (list->next != NULL && list->next->data <= value) {
		list = list->next;
	}
	if (list->next == NULL) {
		return NULL;
	}
	return list;
}

int list_is_sorted(struct list *list) 
{
	while (list->next != NULL && list->next->data <= list->data) 
	{
		list = list->next;
	}
	if (list->next == NULL) {
		return 1;
	}
	return 0;
}

void list_insert(struct list *list, struct list *elm) 
{
	while (list->next != NULL && list->next->data <= elm->data)
	{
		list = list->next;
	}
	struct list *after = list->next;
	list->next = elm;
	list->next->next = after;
}

void list_half_split(struct list *list, struct list *second)
{
	size_t lenlist = list_len(list);
	for (int i = 0; i < lenlist/2; i++) 
	{
		list = list->next;
	}
	second = list->next;
	list->next = NULL;
}
