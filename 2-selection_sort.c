#include "sort.h"

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int min_val, min_index, temp;
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = array[i + 1];
		min_index = i + 1;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				min_index = j;
			}
		}
		if (min_val < array[i])
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
