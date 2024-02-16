#include "hash_tables.h"

/**
 * k_index - returns the index of a key
 * @key: key
 * @size: size of the array of the hash table
 * Return: index
 */
unsigned long int k_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int i = hash_djb2(key) % size;

	return (i);
}
