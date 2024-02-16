#include "hash_tables.h"

/**
 * hash_tables_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to hash table
 */

hash_tables_t *hash_tables_create(unsigned long int size)
{
	hash_tables_t *table;

	if (size == 0)
		return (NULL);

	table = calloc(1, sizeof(hash_tables_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
