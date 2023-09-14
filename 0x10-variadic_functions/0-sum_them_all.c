#include "variadic_functions.h"
#include <stdio.h>

/**
 *sum_them_all - Returns the sum of all its paramters.
 *@n: The number of paramters passed to the function.
 *@...: A variable number of paramters to calculate the sum of.
 *
 *Return: If n == 0 - 0.
 *Otherwise - the sum of all parameters.
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	int i;
	va_list arg;

	if (n == 0)

		return (0);
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum = sum + va_arg(arg, int);
	}

	va_end(arg);
	return (sum);
}



