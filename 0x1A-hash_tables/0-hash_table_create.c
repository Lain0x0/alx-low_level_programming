#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 *
 * @size: The size of the array.
 *
 * Return: If something went wrong it returns NULL, otherwise it
 * returns a pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *n_table = malloc(sizeof(hash_table_t));
	unsigned long int index = 0;

	if (n_table == NULL)
		return (NULL);

	n_table->size = size;
	n_table->array = malloc(sizeof(hash_node_t *) * size);

	if (n_table->array == NULL)
		return (NULL);

	for (; index < size; index++)
		n_table->array[index] = NULL;

	return (n_table);
}
