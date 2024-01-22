#include "sort.h"

void swap_int(int *i, int *j);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_int - function that sorts an array of integers in ascending order
 * @i: array of integers
 * @j: size of integer
 * Return: sorted array
 */

void swap_int(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * lomuto_partition - Order an array of integers according to lomuto partition
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - the quicksort algorithm by recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array
 * @right: ending index of the array
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int step;

	if (right - left > 0)
	{
		step = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 * Description: Uses the Lomuto partition scheme
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
