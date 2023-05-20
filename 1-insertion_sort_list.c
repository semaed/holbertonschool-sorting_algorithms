#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;/*Variable declarations*/

	/* *list is NULL or list has fewer than 2 nodes, no sorting is needed*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;/*Start from the second node*/
	while (current)
	{
		/*Current node is less than the previous node, we swap them*/
		while (current->prev && current->prev->n > current->n)
		{
			temp = current;/*Swap the nodes*/
			if (temp->prev->prev)/*If theres a node before, connect with temp*/
				temp->prev->prev->next = temp;
			if (temp->next)/*Moves and connect temp and tem->next*/
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;/*Connect the nodes*/
			/*Temp moves to the place of temp->prev, connect temp and temp->prev->prev*/
			temp->next = temp->prev;
			if (temp->next == *list)/*Is head of the list update list*/
				*list = temp;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (temp->prev)/*Node before temp, connect it with temp*/
				temp->prev->next = temp;

			print_list((const listint_t *)*list);/*Print list afeter each swap*/
		}

		current = current->next;/*Move to the next node*/
	}
}
