#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                       of integers in ascending order using the Insertion
 *                       sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *h, *current, *previous, *next;
	h = NULL;
	current = NULL;
	previous = NULL;
	next = NULL;
	
	/*empty list*/
	if (!(*list) || !list)
		return;

	/*one element in list*/
	if (!(*list) -> next)
		return;

	h = *list;

	while (h)
	{
		current = h;
		previous = current -> prev;
		next = current -> next;

		/* if current is first node */
		if (!previous)
		{
			h = h -> next;
			continue;
		}

		while (previous && current -> n <= previous -> n)
		{
			/* special case swap for first node */
			if (!(previous -> prev))
			{
				current -> next = previous;
                		current -> prev = NULL;
                		previous -> prev = current;
                		previous -> next = next;
                		next -> prev = previous;
                		*list = current;
				print_list(*list);
                		break;
			}
			else{
				previous -> prev -> next = current;
                		current -> prev = previous -> prev;
                		previous -> next = next;
                		previous -> prev = current;
                		current -> next = previous;
                		if (next)
                    			next -> prev = previous;


                		/* update */
                		next = previous;
                		previous = current -> prev;
				print_list(*list);
			}
		}
		h = h -> next;
	}

}
