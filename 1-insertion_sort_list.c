#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order
 * @list: list sort
 * Return: Sorted list
 */

void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *tmp = NULL, *step = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
			if (tmp->next->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;

			tmp->prev = tmp->next;
			tmp->next = tmp->next->next;
			tmp->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = tmp;

			tmp = tmp->prev;
			print_list(*list);

			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				if (!flag)
					step = tmp->next;
				flag = true;
				tmp = tmp->prev;
				continue;
			}
		}
		if (!flag)
			tmp = tmp->next;
		else
			tmp = step, flag = false;
	}
}
