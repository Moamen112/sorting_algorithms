#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *arr, size_t size, int left, int right);
void lomuto_sort(int *arr, size_t size, int left, int right);
void quick_sort(int *arr, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Description: This function takes two integer
 * pointers and swaps their values in place.
 */

void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition a subset of an integer
 * array using the Lomuto partition scheme.
 * @arr: The array to partition.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: This function partitions a subset of an
 * integer array using the Lomuto partition scheme
 * where the last element of the array is chosen
 * as the pivot. It returns the final partition
 * index and swaps elements within the subset as needed.
 */

int lomuto_partition(int *arr, size_t size, int left, int right)
{
	int *pivot = arr + right;
	int above, below;

	for (above = below = left; below < right; below++)
	{
		if (arr[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}

	if (arr[above] > *pivot)
	{
		swap_ints(arr + above, pivot);
		print_array(arr, size);
	}


	return (above);
}

/**
 * lomuto_sort - Sort an integer array using
 * the Lomuto partition scheme and recursion.
 * @arr: The array to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 *
 * Description: This function uses the Lomuto partition
 * scheme to sort an integer array through recursion.
 */

void lomuto_sort(int *arr, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(arr, size, left, right);
		lomuto_sort(arr, size, left, part - 1);
		lomuto_sort(arr, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an integer array in
 * ascending order using the quicksort algorithm.
 * @arr: The array to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts an integer array in
 * ascending order using the quicksort algorithm
 * with the Lomuto partition scheme.
 * It prints the array after each swap of two elements.
 */

void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	lomuto_sort(arr, size, 0, size - 1);
}
