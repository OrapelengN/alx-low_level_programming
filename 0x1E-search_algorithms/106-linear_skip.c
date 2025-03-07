#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if value is not present in list or if list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *express, *prev;

	if (list == NULL)
		return (NULL);

	curr = list;
	express = list->express;

	if (express == NULL)
	{
		while (curr != NULL)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
			if (curr->n == value)
				return (curr);
			curr = curr->next;
		}
		return (NULL);
	}

	while (express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
		curr = express;
		express = express->express;
	}

	if (express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
			curr->index, express->index);
	}
	else
	{
		express = curr;
		while (express->next != NULL)
			express = express->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			curr->index, express->index);
	}

	prev = curr;
	while (prev != NULL && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
