/* Home Work */
 
# include <stdlib.h>
 
# include "math_func.h"
 
unsigned long fact(unsigned long n) {
	unsigned long r = 1;
	for (; n > 0; n--)
		r *= n;
	return r;
}
 
unsigned long fibo(unsigned long n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return (fibo(n - 1) + fibo(n - 2));
}
 
unsigned long int_sqrt(unsigned long n) {
	if (n == 0)
		return n;
	unsigned long x = n;
	unsigned long r = n / x;
	while (x > r) {
		x = (x + n / x) / 2;
	}
	return x;
}
 
unsigned long digit_number(unsigned long n) {
	unsigned long digits = 0;
	while (n > 0) {
		digits = digits + 1;
		n = n / 10;
	}
	return digits;
}
 
unsigned long binary_digit_number(unsigned long n) {
	unsigned long digit_number = 0;
	while (n > power_of_2(digit_number)) {
		digit_number++;
	}
	return digit_number;
}
 
unsigned long power_of_2(unsigned long n) {
	unsigned long i = 0;
	unsigned long res = 1;
	while (i < n) {
		res *= 2;
	}
	return res;
}
 
unsigned long divisor_sum(unsigned long n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	unsigned long div = n;
	unsigned long sum = 0;
	while (div > 1) {
		if (n % div == 0) {
			sum += div;
		}
		div -= 1;
	}
	return sum;
}