#include "monty.h"
/**
* length_stack - Function
*
* Description: Calculates the length of the stack
*
* @head: Head of the stack dlist
*
* Return: number of nodes in the stack
*/

size_t length_stack(const stack_t *head)
{
	unsigned int length = 0;

	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return (length);
}
