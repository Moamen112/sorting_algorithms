#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers
 * in ascending order using bubble sort
 * @array: the array to sort
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				printf("%d, ", array[j]);
			}
		}
		printf("%d", array[j]);
		if (i != size - 2)
			printf(", ");
	}
	printf("\n");
}
