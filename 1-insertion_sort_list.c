#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: doubly linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current = *list;
    listint_t *key;
    listint_t *j;

    for (current = (*list)->next; current != NULL; current = current->next)
    {
        key = current;
        j = current->prev;
        while (j != NULL && j->n > key->n)
        {
            j->next->prev = j->prev;
            if (j->prev != NULL)
                j->prev->next = j->next;
            else
                *list = j->next;
            j->prev = key->prev;
            j->next = key;
            key->prev->next = j;
            key->prev = j;
            j = j->prev;
            /*print_list(*list);*/
        }
    }
}

