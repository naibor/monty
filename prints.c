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

/**
* pint - Function
* Description: Print value at the top of the stack, then a new line
*
* @stack: pointer parameter, head of the stack
* @line_number: line number
* 
*/

void pint(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp = *stack;
	char message[100];
	unsigned int length_stack = 0;

	/** calculate the length of the stack */
	while (temp != NULL)
	{
		temp = temp->next;
		length_stack++;
	}
	/*check if stack exists or is empty*/
	if (*stack == NULL || length_stack < 1)
	{
		sprintf(message, "L%u: can't pint, stack empty", line_number);
		error_message(message, "", stack);
	}
	printf("%d\n", (*stack)->n);
}

