#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted.
 * @size: number of elements in @array.
 */
void bubble_sort(int *array, size_t size)
{
	/*Variable declarations*/
	size_t i, j;   /* Loop counters. */
	int tmp;/*Temporary variable for swapping elements*/

	/*If the array is NULL or has fewer than 2 elements, no sorting is needed*/
	if (array == NULL || size < 2)
		return;

	/*i loops from 0 to size - 2*/
	for (i = 0; i < size - 1; i++)
	{
		/*j loops from 0 to size - i - 2*/
		for (j = 0; j < size - i - 1; j++)
		{
			/*If the current element is greater than the next one, swap them*/
			if (array[j] > array[j + 1])
			{

				/*Swapping array[j] and array[j+1] using a temporary variable tmp*/
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/*Printing the array after swapping elements*/
				print_array(array, size);
			}
		}
	}
}

