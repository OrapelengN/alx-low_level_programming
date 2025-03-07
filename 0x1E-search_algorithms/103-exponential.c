#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search_range - Searches for a value in a sorted array of integers
 * within a specified range using binary search.
 * @array: Pointer to the first element of the array to search in.
 * @low: Starting index of the range.
 * @high: Ending index of the range.
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if value is not present.
 */
int binary_search_range(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");

		mid = low + (high - low) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
		high = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not present
 * in array or if array is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (binary_search_range(array, low, high, value));
}
