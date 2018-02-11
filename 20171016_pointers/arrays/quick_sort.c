/* quick_sort.c : simple quick sort implementation */

# include <stdlib.h>

# include "helper.h"
# include "quick_sort.h"

int* partition(int *begin, int *end)
{
  int pivot = (begin + (end - begin) / 2);
  int pval = *(begin + pivot);
  swap(*(begin + pivot), *(end - 1));
  pivot = begin;

  for (int i = *begin; i < *end; i++) {
    if (*(begin + i) < pval) {
      swap(*(begin + pivot), *(begin + i));
      pivot += 1;
    }
  }
  swap(*(begin + pivot), *(end - 1));
  return pivot;
}

void quick_sort(int *begin, int *end)
{
  if (end - begin > 1) {
    pivot = partition(begin, end);
    quick_sort(begin, pivot);
    quick_sort(pivot + 1, end);
  }
}

void hybrid_sort(int *begin, int *end)
{
  if (end - begin < 2 || array_is_sorted(begin, end))
    return;
  quick_sort(begin, end);
}
