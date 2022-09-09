#include "monty.h"
/**
* sub - Calculates the substraction of the top 2 elements on stack or queue.
* @stack: Stack.
* @line_number: Line number.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	char message[100];

	sprintf(message, "L%d: can't sub, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(message, "", stack);
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}