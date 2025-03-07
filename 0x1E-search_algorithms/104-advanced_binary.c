#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches for a value in a sorted array of
 * integers using recursive binary search.
 * @array: Pointer to the first element of the array to search in.
 * @low: Starting index of the range.
 * @high: Ending index of the range.
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if value is not present.
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (low > high)
		return (-1);

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
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else
		return (advanced_binary_recursive(array, low, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if value is not present.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
