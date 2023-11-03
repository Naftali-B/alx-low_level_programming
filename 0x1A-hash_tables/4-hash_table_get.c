#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to look up the value for.
 *
 * Return: If the key cannot be found or is invalid - NULL.
 *         Otherwise - the value associated with the key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *node;
    unsigned long int index;

    /* Check for invalid or missing parameters */
    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Calculate the index for the key using the key_index function */
    index = key_index((const unsigned char *)key, ht->size);

    if (index >= ht->size)
        return (NULL);

    /* Traverse the linked list at the calculated index */
    node = ht->array[index];
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value); // Return the value if the key is found
        node = node->next;
    }

    return (NULL); // Key not found, return NULL
}

