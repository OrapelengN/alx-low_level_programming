#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - Searches for a value in an array using Linear Search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index where value is located, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
    size_t i;

    if (array == NULL) /* Check if array is NULL */
        return (-1);

    for (i = 0; i < size; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i); /* Return index when value is found */
    }

    return (-1); /* Return -1 if value is not found */
}
