#include "sort.h"

/**
 * swap_values - Swap two values in an array.
 * @first_value: The first value to swap.
 * @second_value: The second value to swap.
 */
void swap_values(int *first_value, int *second_value)
{
	int temp_value;

	temp_value = *first_value;
	*first_value = *second_value;
	*second_value = temp_value;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, array_len = size;
	bool is_swapped = false;

	if (array == NULL || size < 2)
		return;

	while (is_swapped == false)
	{
		is_swapped = true;
		for (index = 0; index < array_len - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap_values(array + index, array + index + 1);
				print_array(array, size);
				is_swapped = false;
			}
		}
		array_len--;
	}
}
