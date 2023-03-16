/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: pointer to the previous element of the list
 * @next: pointer to the next element of the list
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
