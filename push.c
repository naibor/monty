#include "monty.h"
/**
* push_stack - Function
*
* Description: Push on a stack.
*
* @stack: The said stack.
* @line_number: Line number.
*/
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;
	char *arg, message[100];
	
	/*check if stack exists*/
	if (!stack)
		error_message("No stack present.", "", stack);
	arg = strtok(NULL, " \t");
	/*check if user input is a number*/
	if (!arg || !_isnumber(arg))
		error_message(message, "", stack);
	/*allocate memory to new stack and check if null*/
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
		error_message("Error: malloc failed", "", stack);
	/*assign value of n to user input arg*/
	new_stack->n = atoi(arg);
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
