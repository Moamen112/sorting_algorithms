#include "sort.h"

/**
 * swap_integers - Swaps two integers in array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending
 *              order using sorting algo (shell sort).
 * @array: An array of integers.
 * @size: The size.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_integers(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}

