#include "sort.h"

/* Function Prototypes */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Apply Lomuto partition scheme */
	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - implements the Lomuto partition scheme for quicksort
 * @array: the array to be sorted
 * @low: starting index of the array partition to be sorted
 * @high: ending index of the array partition to be sorted
 * @size: total size of the array
 */
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;

	if (high - low > 0)
	{
		/* Partition the array and get the final pivot position */
		pivot = lomuto_partition(array, low, high, size);

		/*Sort elements before pivot and after pivot*/
		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions the array using Lomuto partition scheme
 * @array: the array to be sorted
 * @low: starting index of the array partition to be sorted
 * @high: ending index of the array partition to be sorted
 * @size: total size of the array
 * Return: final pivot position
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;
	ssize_t i, j;

	pivot = array[high];/*Pivot always last element*/
	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			if (i != j)/*Swap arrays*/
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

