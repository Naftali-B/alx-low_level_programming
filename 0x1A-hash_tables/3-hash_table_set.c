#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in the hash table
 * @ht: The hash table to add/update the key/value in
 * @key: The key to be added/updated (cannot be an empty string)
 * @value: The value associated with the key (duplicated; can be an empty string)
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *node;
    unsigned long int i, index;
    char *value_copy;

    /* Check for invalid or missing parameters */
    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);

    /* Duplicate the value to ensure it's safe for storage in the hash table */
    value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    /* Calculate the index for the key using the key_index function */
    index = key_index((const unsigned char *)key, ht->size);

    /* Search for an existing key with the same index (collision) */
    for (i = index; ht->array[i] != NULL; i++)
    {
        if (strcmp(ht->array[i]->key, key) == 0)
        {
            /* If a collision is found, update the value and return success */
            free(ht->array[i]->value);
            ht->array[i]->value = value_copy;
            return (1);
        }
    }

    /* If no collision is found, allocate memory for a new hash_node_t */
    node = malloc(sizeof(hash_node_t));
    if (node == NULL)
    {
        free(value_copy);
        return (0);
    }

    /* Duplicate the key to ensure it's safe for storage */
    node->key = strdup(key);
    if (node->key == NULL)
    {
        free(node);
        free(value_copy);
        return (0);
    }

    /* Set the value and link the new node to the beginning of the list */
    node->value = value_copy;
    node->next = ht->array[index];
    ht->array[index] = node;

    return (1); // Return 1 to indicate success
}

