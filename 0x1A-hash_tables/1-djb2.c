#include "hash_tables.h"

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_t;
	int x;

	hash_t = 5381;
	while ((x = *str++))
	{
		hash_t = ((hash_t << 5) + hash_t) +c;
	}
	return (hash_t);
}
