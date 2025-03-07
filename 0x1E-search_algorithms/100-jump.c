#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array using Jump Search.
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if value is not found
 */
int jump_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t step = sqrt(size);  /* The block size (step) */
	size_t prev = 0;

	/* Jump forward in the array in steps of size `step` */
	while (array[step - 1] < value && step < size)
	{
		printf("Value checked array[%zu] = [%d]\n", step - 1, array[step - 1]);
		prev = step;
		step += sqrt(size);
		if (step > size)
			step = size;
	}

	/* Print the block range */
	printf("Value found between indexes [%zu] and [%zu]\n", prev, step - 1);

	/* Perform a linear search within the block */
	for (size_t i = prev; i < step; i++)
	{
		printf("Value checked array[%zu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);  /* If the value is not found */
}
