#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array of integers
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
    size_t count, a, min_index;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (count = 0; count < size - 1; count++)
    {
        min_index = count;

        for (a = count + 1; a < size; a++)
        {
            if (array[a] < array[min_index])
                min_index = a;
        }

        if (min_index != count)
        {
            temp = array[count];
            array[count] = array[min_index];
            array[min_index] = temp;
            print_array(array, size);
        }
    }
}
