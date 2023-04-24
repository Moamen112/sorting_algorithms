#include "sort.h"

/**
 * swap_values - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_values(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the sorting algorithm (selection sort)
 * @array: An array of integers.
 * @size: The size.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;

		if ((array + i) != minimum)
		{
			swap_values(array + i, minimum);
			print_array(array, size);
		}
	}
}
