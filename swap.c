#include "monty.h"
/**
* swap - Function
*
* Description: Swap the top two element of the stack
*
* @stack: Pointer to the head of the stack
* @line_number: line number
*
*/

void swap(stack_t **stack, unsigned int line_number)
{
	char message[100];
	stack_t *first, *second;
	int temp;

	if (length_stack(*stack) < 2 || *stack == NULL)
	{
		sprintf(message, "L%u: can't swap, stack too short", line_number);
		error_message(message, "", stack);
	}

	first = *stack;
	second = first->next;
	temp = second->n;
	second->n = first->n;
	first->n = temp;
}

/**
* length_stack - Calculates the length of the stack
* @head: Head of the stack dlist
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
