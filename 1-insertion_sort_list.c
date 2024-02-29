#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: Double linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current)
	{
		while ((current->prev) && (current->prev->n > current->n))
		{
			current = swap_current(current, list);
			print_list(*list);
		}
		current = current->next;
	}
}

/**
 *swap_current - swaps a node for his previous one
 *@current: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_current(listint_t *current, listint_t **list)
{
	listint_t *previous = current->prev, *temp = current;

	previous->next = temp->next;
	if (temp->next)
		temp->next->prev = previous;
	temp->next = previous;
	temp->prev = previous->prev;
	previous->prev = temp;
	if (temp->prev)
		temp->prev->next = temp;
	else
		*list = temp;
	return (temp);
}
