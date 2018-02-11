 /*
  * algebra.c: contains all the fonctions code from
  * algebra.h
  *
  *
  */

# include <stdio.h>
# include <stdlib.h>

# include "algebra.h"

void vector_apply(func_t f, double vect[], size_t size, double res[]) {
	for (size_t i = 0; i < size; i++) {
		res[i] = f(vect[i]);
	}
}

void product(double M[], double v[], size_t m, size_t n, double res[]) {
	for (size_t j = 0; j < m; j++) {
		for (size_t i = 0; i < n; i++) {
			res[j] += M[i + j * n] * v[i];
		}
	}
}

void vector_sum(double v1[], double v2[], size_t size, double res[]) {
	for (size_t i = 0; i < size; i++) {
		res[i] = v1[i] + v2[i];
	}
}