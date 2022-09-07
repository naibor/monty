#include "monty.h"
/**
* error_message - Function
*
* Description: Prints error message, exits with failure.
*
* @message: Message to print.
* @arg: argument.
* @stack: stack to free.
*/
void error_message(char *message, char *arg, stack_t **stack)
{
	free_all(stack);
	fprintf(stderr, "%s%s\n", message, arg);
	exit(EXIT_FAILURE);
}

/**
* free_all - Function
*
* Description: Frees the stack
*
* @stack: stack to free
*
*/

void free_all(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
