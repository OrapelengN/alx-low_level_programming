#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if value is not present in list or if list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, prev_index;
	listint_t *curr, *prev;

	if (!list || size == 0)
		return (NULL);

	step = sqrt(size);
	prev = NULL;
	curr = list;

	while (curr->next && curr->n < value)
	{
		prev = curr;
		for (prev_index = 0; prev_index < step && curr->next; prev_index++)
			curr = curr->next;


		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev_index, curr->index);

	while (prev && prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
