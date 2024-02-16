#include "hash_tables.h"

/**
 * hash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int x = 0;
	hash_node_t  *bucket;
	int n_fin = 0;

	if (!ht)
		return;

	printf("{");
	for (x = 0; x < ht->size; x++)
	{
		bucket = ht->array[x];
		while (bucket)
		{
			if (n_fin)
				printf(", ");
			printf("'%s': '%s'", bucket->key, bucket->value);
			not_fin = 1;
			bucket = bucket->next;
		}
	}
	printf("}\n");
}
