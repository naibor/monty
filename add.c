#include "monty.h"
/**
* add - Calculates the sum of the top 2 elements on stack or queue.
* @stack: Stack.
* @line_number: Line number.
*/
void add(stack_t **stack, unsigned int line_number)
{
	char message[100];

	sprintf(message, "L%d: can't add, stack too short", line_number);
	if (!stack)
		error_message("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_message(message, "", stack);
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
