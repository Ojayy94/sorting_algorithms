#include "sort.h"

/**
 * selection_sort - function that sorts array of integers in ascending order
 * @array: array of integers
 * @size: integer size
 * Return: sorted array
 */

void selection_sort(int *array, size_t size)
{
	size_t a = 0;
	size_t b = 1;
	size_t step = 0;
	size_t min = 0;
	size_t max = size - 1;

	if (size < 2)
		return;

	while (a < max)
	{
		if (b == size)
		{
			if (a != min)
			{
				step = array[a];
				array[a] = array[min];
				array[min] = step;
				print_array(array, size);
			}

			++a;
			min = a;
			b = a + 1;
			continue;
		}

		if (array[min] > array[b])
			min = b;

		++b;
	}
}
