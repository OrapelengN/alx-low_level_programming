#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, i;  /* Declare all variables at the top */
	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);  /* The block size (step) */
	prev = 0;

	/* Jump in steps of sqrt(size) */
	while (array[step - 1] < value && step < size)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (step > size)
			step = size;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, step - 1);

	/* Linear search within the block */
	for (i = prev; i < step; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);  /* If the value is not found */
}
