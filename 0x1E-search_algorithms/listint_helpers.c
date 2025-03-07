#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * create_list - Creates a linked list from an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: Pointer to the head of the linked list.
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *head = NULL, *new_node, *temp;
	size_t i;

	for (i = 0; i < size; i++)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);
		new_node->n = array[i];
		new_node->index = i;
		new_node->next = NULL;

		if (head == NULL)
			head = new_node;
		else
		{
			temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
	}
	return (head);
}

/**
 * print_list - Prints a linked list.
 * @list: Pointer to the head of the list.
 */
void print_list(const listint_t *list)
{
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
}

/**
 * free_list - Frees a linked list.
 * @list: Pointer to the head of the list.
 */
void free_list(listint_t *list)
{
	listint_t *temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}
