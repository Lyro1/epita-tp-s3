/* insert_sort.h : implementing insert sort */

# ifndef EPITA_IP_INSERT_SORT_H_
# define EPITA_IP_INSERT_SORT_H_

# include <stdlib.h>
# include <string.h>

# include "helper.h"


void array_insert(int *begin, int *end, int x);

void array_insert_bin(int *begin, int *end, int x);

void array_insert_sort(int *begin, int *end);

void array_insert_sort_bin(int *begin, int *end);

# endif /* EPITA_IP_INSERT_SORT_H_ */
