#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * create_skiplist - Creates a skip list from an array
 * @array: Array of integers to build the list from
 * @size: Size of the array
 * Return: Pointer to the head of the skip list, or NULL on failure
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *head = NULL, *tail = NULL, *express = NULL;
	size_t i, step;

	if (!array || size == 0)
		return (NULL);

	step = sqrt(size);  /* Express lane every sqrt(size) steps */

	for (i = 0; i < size; i++)
	{
		skiplist_t *new_node = malloc(sizeof(skiplist_t));
		if (!new_node)
			return (NULL);

		new_node->n = array[i];
		new_node->index = i;
		new_node->next = NULL;
		new_node->express = NULL;

		if (!head)
			head = tail = new_node;
		else
		{
			tail->next = new_node;
			tail = new_node;
		}

		/* Add express links at step intervals */
		if (i % step == 0)
		{
			if (express)
				express->express = new_node;
				express = new_node;
		}
	}

	return (head);
}

/**
 * print_skiplist - Prints a skip list
 * @list: Pointer to the head of the skip list
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *express = list;

	printf("List :\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}

	printf("\nExpress lane :\n");
	while (express)
	{
		printf("Index[%lu] = [%d]\n", express->index, express->n);
		express = express->express;
	}
	printf("\n");
}

/**
 * free_skiplist - Frees a skip list
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
