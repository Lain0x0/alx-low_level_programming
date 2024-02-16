#include "hash_table.h"

/**
 * hash_table_create - Function to create a new hash table
 * @size: The size of the hash table
 *
 * Return: A pointer to the newly created hash table, NULL if allocation fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
	{
		return (NULL); /* Allocation failed */
	}

	hash_table->array = malloc(size * sizeof(hash_node_t *));

	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL); /* Allocation failed */
	}

	for (unsigned long int i = 0; i < size; i++)
	{
		hash_table->array[i] = NULL;
	}

	hash_table->size = size;

	return (hash_table);
}
