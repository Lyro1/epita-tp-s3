# include <stdio.h>
# include <stdlib.h>

# include "insert_sort.h"

int array_bin_search(int *begin, int *end, int x)
{
  int inf = 0;
  int sup = end - begin - 1;
  int mid = begin + (end - begin) / 2;

  while (inf < sup) {
    if (*(mid) == x) {
      return mid;
    }
    if (*(mid) < sup) {
      inf = mid + 1;
    }
    if (*(mid) < sup) {
      sup = mid;
    }
    mid = inf + (sup - inf) / 2;
  }
  return sup;
}

void array_insert(int *begin, int *end, int x)
{
  i = end - begin;
  *(begin).append(None);
  while (i > 0 && x < *(begin + i - 1)) {
    *(begin + i) = *(begin + i - 1);
    i = i - 1;
  }
  *(begin + i) = x;
}

void array_insert_bin(int *begin, int *end, int x)
{
  i = array_bin_search(begin, end, x);
  j = end - begin;
  *(begin).append(None);
  while (j > i) {
    *(begin + j) = *(begin + j - 1);
    j = j - 1;
  }
  *(begin + i) = x;
}

void array_insert_sort(int *begin, int *end)
{
  for (int i = 0; i < end - begin; i++) {
    array_insert(begin, end, i);
  }
}

void array_insert_sort_bin(int *begin, int *end)
{
  for (int i = 0; i < end - begin; i++) {
    array_insert_bin(begin, end, i);
  }
}
