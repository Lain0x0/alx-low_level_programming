#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 *malloc_checked - allocates memory using malloc
 *@b: number of bytes to allocate
 *
 *Return: a pointer to the allocated memory
*/
void *malloc_checked(unsigned int b)
{
	char *output;

	output = malloc(b);

	if (output == NULL)
		exit(98);
	else
		return (output);
}

