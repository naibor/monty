#include "monty.h"
/**
* pop - Function
*
* Description: Deletes top item on a stack or queue.
*
* @stack: the stack.
* @line_number: Line number.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *move = *stack;
	char message[100];
	/*check if stack exists*/
	if (!stack)
		error_message("No stack present.", "", stack);
	sprintf(message, "L%d: can't pop an empty stack", line_number);
	if (!*stack)
		error_message(message, "", stack);
	
	*stack = move->next;

	/*remove the first item and redirect nodes*/
	if (move->next)
		move->next->prev = NULL;
	/*free up the memory*/
	free(move);
}
