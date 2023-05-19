#ifndef SORT_H
#define SORT_H

/*Including the standard library for the size_t type*/
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

/*Defining a structure for doubly linked list node*/
typedef struct listint_s
{
const int n;/*Integer stored in the node*/
struct listint_s *prev;/*Pointer to the previous element of the list*/
struct listint_s *next;/*Pointer to the next element of the list*/
} listint_t;

/*Function prototypes*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/*End of header guard*/
#endif
