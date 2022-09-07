#include "monty.h"

/**
* pall - Function
* Description: Prints values on the stack
*
* @stack: pointer parameter, head of the stack
* @line_number: line number
*
*/

void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp = *stack;

	(void) line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
