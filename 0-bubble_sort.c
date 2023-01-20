#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: list to be sorted
 * @size: length of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t flag = size - 1, i;
	int current, next;

	if (size < 2){
		return;
	}

	while (true){
		for(i = 0; i < size - 1; i++){
			current = array[i];
			next = array[i + 1];

			if (current > next){
				array[i] = next;
				array[i + 1] = current;
				flag += 1;
			}else{
				flag -= 1;
			}
		}
		if (!flag){
			break;
		}
		flag = size - 1;
	}
}
