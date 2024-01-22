#include <sort.h>

/**
 * bubble_sort - using the Bubble sort algorithm
 * @array: print the array after each time you swap two elements 
 * @size: Size
 * Return: Sorted
 */

void bubble_sort(int *array, size_t size)
{
	int i;
	int start = 0;
	int max = 0;
	int bubbly = 1;

	if (array == NULL || size < 2)
		return;

	max = size - 1;

	for (i = 0; i < max; ++i)
	{
		if (array[i] > array[i + 1])
		{
			start = array[i];
			array[i] = array[i + 1];
			array[i + 1] = start;
			bubbly = 1;
			print_array(array, size);
		}

		if (bubbly == 1 && i == max - 1)
			i = -1, bubbly = 0, --max;
	}
}
