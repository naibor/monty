#include "monty.h"
/**
* divi - Calculates the division of the top 2 elements on stack or queue.
* @stack: Stack.
* @line_number: Line number.
*/
void divi(stack_t **stack, unsigned int line_number)
{
	char message[100];

	sprintf(message, "L%d: can't div, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(message, "", stack);
	sprintf(message, "L%d: division by zero", line_number);
	if (!(*stack)->n)
		error_mes(message, "", stack);
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}