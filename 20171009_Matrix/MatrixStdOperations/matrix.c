 /*
  * matrix.c: contains all the fonctions code from
  * matrix.h.
  *
  *
  */

# include <stdio.h>
# include <stdlib.h>

void transpose(double mat[], size_t lines, size_t cols, double res[]) {
   
   for (size_t j = 0; j < lines; j++) {
      for (size_t i = 0; i < cols; i++) {
         res[i + j * cols] = mat[j + i * cols];
      }
   }
}

void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[]) {
   
   for (size_t j = 0; j < lines; j++) {
      for (size_t i = 0; i < cols; i++) {
         res[i + j * cols] = mat1[i + j * cols] + mat2[i + j * cols];
      }
   }
}

void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[]) {
   
   for (size_t j = 0; j < n; j++) {
      for (size_t i = 0; i < p; i++) {
         for (size_t k = 0; k < m; k++) {
		  res[j + i * p] = m1[k + i * m] * m2[j + k * p]; 
		}
      }
   }
}

void print_matrix(double mat[], size_t lines, size_t cols) {
 
   for (size_t j = 0; j < lines; j++) {
      for (size_t i = 0; i < cols; i++) {
         printf("%4g ", mat[i + j * cols]);	      
      }	   
      printf("\n");
   }
   
}

